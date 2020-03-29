#include "SecondWindow.h"
/*!
 * \file SecondWindow.h
 *
 * \brief Gui Window module implementation
 *
 * \author      KESKE CEM - EPFL EL BA3
 * \date        02.12.2019
 */

#include "SecondWindow.h"
/// see reference for #include's
/// https://stackoverflow.com/questions/3943352/where-to-put-include-statements-header-or-source
/// https://stackoverflow.com/questions/2297567/where-should-include-be-put-in-c
/// and many others

#include <chrono>
#include <iostream>
#include <ctime>
#include <array>
#include "../Telecom/DataStructures/Avionics/StateValues.h"
#include "../Telecom/DataHandler/DatagramTypes.h"
#include "../Telecom/DataStructures/File/FileTransmissionStates.h"
#include "../Telecom/DataStructures/Propulsion/IgnitionStates.h"
#include "gui_message.h"

#include <QStyleFactory>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QCoreApplication>


constexpr uint32_t REFRESH_RATE(500);

using namespace ui_interface;

inline QString degree_representation(double value)
{
    return QString::number(value) + "<sup>o</sup>";
}

// Works for double, uint8_t, uint32_t, uint64_t
template <typename T> inline QString qstr(T value)
{
    return QString::number(value);
}

inline bool get_bit(unsigned char byte, int position) // position in range 0-7
{
    return (byte >> position) & 0x1;
}

SecondWindow::SecondWindow(std::shared_ptr<Connector> connector) :
    timer_(new QTimer(this)),
    data_(connector),
    missed_count_(0),
    current_theme_(0),
    ready_ignition_(false),
    xbee_acvite_(false),
    fullscreen_(false),
    musicON_(false)
{
#ifdef SOUND_ON
    m_player = new QMediaPlayer();
    alarm    = "qrc:/assets/nuclear_alarm.mp3";
    takeoff  = "qrc:/assets/launch.mp3";
    hymne    = "qrc:/assets/hymne.mp3";
#endif

    initialize_style();
    initialize_slots_signals();
    grabKeyboard();
    timer_->start(REFRESH_RATE);
}
///////////////////////////////////////////////////////////////////////////
void SecondWindow::refresh_lionel_stuff() {
    if (musicON_) {
#ifdef SOUND_ON
        playSound(hymne);
#endif
        verticalSlider_1->setValue(rand() % 100);
        verticalSlider_2->setValue(rand() % 100);
        verticalSlider_3->setValue(rand() % 100);
        verticalSlider_4->setValue(rand() % 100);
        verticalSlider_5->setValue(rand() % 100);
        verticalSlider_11->setValue(rand() % 100);
        verticalSlider_12->setValue(rand() % 100);
        verticalSlider_13->setValue(rand() % 100);
        verticalSlider_14->setValue(rand() % 100);
        verticalSlider_15->setValue(rand() % 100);
    }
    //// Lionel test
    static bool a(false);
    ignition_status_label->setStyleSheet((a) ? "QLabel {color: rgb(255, 255, 255);}"
                                             : "QLabel {color: rgb(255, 0, 0);}");
    antenna_img->setStyleSheet((xbee_acvite_ && a) ?
                                                   "QLabel {image: url(:/assets/radioON.png);}":
                                                   "QLabel {image: url(:/assets/radioOFF.png);}");
    serialport_status->setStyleSheet((data_->getData<bool>(ui_interface::SERIALPORT_ERROR)) ?
                               "QLabel {image: url(:/assets/green_check.png);}":
                               "QLabel {image: url(:/assets//redCross.png);}");
    a = !a;
}

void SecondWindow::valve_control() {
    QString url = R"(Yann.png)";
    QPixmap img(url);
    image_lio->setPixmap(img);
    data_->setData(ui_interface::RSSI_VALUE, (uint8_t) (rand() % 100));
    static int x(0);
    data_->setData(IGNITION_STATUS, (ignit::IgnitionState) x);
    x+=1;
}

void SecondWindow::reset_button_pressed()
{
    constexpr uint64_t z(0);
    for (auto& index : dataToReset) data_->setData(index, z);
}

void SecondWindow::refresh_data()
{
    refresh_com();
    refresh_av_state();
    refresh_telemetry();
    refresh_time();
    check_and_show();
    refresh_ignition_frame();
    refresh_gps();
    refresh_file_transmission_box();
    refresh_lionel_stuff();
    ++tick_counter_;
}

void SecondWindow::xbee_clicked()
{
    if (!xbee_acvite_) {
        //logger.log(new Gui_Message("XBee ON button clicked!"));
        std::cout << "XBee ON button clicked!" << std::endl;
        uint64_t index(serialport_selector->currentIndex());
        data_->setData(ui_interface::SERIALPORT_INDEX, index);
        data_->setData(ui_interface::ACTIVE_XBEE, true);
        //xbee_button->setText("STOP XBee");
    } else {
        //logger.log(new Gui_Message("XBee STOP button clicked!"));
        std::cout << "XBee STOP button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, false);
        //xbee_button->setText("START XBee");
    }
    xbee_acvite_ = !xbee_acvite_;
}

void SecondWindow::ignite_clicked()
{
    ready_ignition_ = data_->getData<bool>(IGNITION_CLICKED);
    if (ready_ignition_) {
        ready_ignit_button->setStyleSheet(
            "QPushButton { qproperty-icon: url(:/assets/readiness.png);}");
        red_button->setStyleSheet(
            "QLabel { image: url(:/assets/alarmON.png);}");
    } else {
        ready_ignit_button->setStyleSheet(
            "QPushButton { qproperty-icon: url(:/assets/notreadiness.png);}");
        red_button->setStyleSheet(
            "QLabel { image: url(:/assets/alarmOFF.png);}");
    }

    std::cout << "Ignition button clicked!" << std::endl;
    ready_ignition_ = !ready_ignition_;
    data_->setData(ui_interface::IGNITION_CLICKED, ready_ignition_);
}

void SecondWindow::theme_change_clicked()
{
    current_theme_ = ((current_theme_ + 1) % THEME_COUNT);

    std::string str("Theme change button clicked. ");

    /*   if (current_theme_ == WHITE_ON_BLACK) {
        str += "Theme set to \"white on black.\"";

    setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
                                "color: rgb(255, 255, 255);"));
    packets_second_bar->setStyleSheet(
        QLatin1String("color: rgb(255, 255, 255);"));
} else if (current_theme_ == GREEN_ON_BLACK)    {
    str += "Theme set to \"green on black.\"";
    setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
                                "color: rgb(0, 255, 0);"));
    packets_second_bar->setStyleSheet(
        QLatin1String("color: rgb(255, 255, 255);"));
} else if (current_theme_ == BLACK_ON_WHITE)    {
    str += "Theme set to \"black on white.\"";
    setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
                                "color: rgb(0, 0, 0);"));
    packets_second_bar->setStyleSheet(QLatin1String("color: rgb(0,0,0);"));
}*/
//logger.log(new Gui_Message(str));
}

void SecondWindow::file_transmission_pressed()
{
    //logger.log(new Gui_Message("File transmission button pressed. SEND_FILE_REQUEST set to true."));
    data_->setData(ui_interface::SEND_FILE_REQUEST, true);
}

uint16_t SecondWindow::calculate_misses_in_last_2()
{
    static std::array<uint32_t, 2000 / REFRESH_RATE> before{ 0 };

    uint16_t current(tick_counter_ % 2000 / REFRESH_RATE);
    uint16_t tmp(missed_count_ - before[current]); // change

    before[current] = missed_count_;
    return tmp;
}

void SecondWindow::closeEvent(QCloseEvent * event)
{
    //logger.log(new Gui_Message("Window close clicked."));
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "BELLA LUI 2020",
                                                               tr("Ending mission Bella Lui 2020.\nAre you sure?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
        data_->setData(ui_interface::RUNNING, false);
        std::cout << "running set to false" << std::endl;
    }
}

void SecondWindow::refresh_misses()
{
    missed_count_ = data_->getData<uint32_t>(TX_PACKET_NR)
                    - data_->getData<uint32_t>(RX_PACKET_CTR);
}

void SecondWindow::refresh_ignition_code()
{
    uint8_t tmp(data_->getData<uint8_t>(ui_interface::TX_IGNITION_CODE));

    code_0->setText(QString::number(get_bit(tmp, 0)));
    code_1->setText(QString::number(get_bit(tmp, 1)));
    code_2->setText(QString::number(get_bit(tmp, 2)));
    code_3->setText(QString::number(get_bit(tmp, 3)));
}

void SecondWindow::refresh_av_state()
{
    std::string str(avionic::getAVStateName(data_->getData<uint8_t>(STATUS_AV_STATE)));
    avionics_state_panel->setText(QString::fromStdString(str));
}

void SecondWindow::initialize_style()
{
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles);
    QApplication::setStyle(QStyleFactory::create("cleanlooks"));
    Ui_second_ui::setupUi(this);
}

void SecondWindow::refresh_ignition_frame()
{
    refresh_ignition_code();

    bool key1    = data_->getData<bool>(IGNITION_KEY_1_ACTIVATED);
    bool key2    = data_->getData<bool>(IGNITION_KEY_2_ACTIVATED);
    bool button  = data_->getData<bool>(IGNITION_RED_BUTTON_PUSHED);
    bool clicked = data_->getData<bool>(IGNITION_CLICKED);

    // Keys
    ignition_key1->setStyleSheet((key1) ? "QLabel {image: url(:/assets/keyON.png);}"
                                        : "QLabel {image: url(:/assets/keyOFF.png);}");
    ignition_key2->setStyleSheet((key2) ? "QLabel {image: url(:/assets/keyON.png);}"
                                        : "QLabel {image: url(:/assets/keyOFF.png);}");

    // Ignition status
    auto ignitState = data_->getData<ignit::IgnitionState>(IGNITION_STATUS);
    ignition_status_label->setText(QString::fromStdString(ignit::getIgnitionState(ignitState)));
    switch (ignitState) {
    case ignit::SLEEP:
        ignition_state_icon->setStyleSheet("QLabel {image: url(:/assets/safe.png);}");
        break;
    case ignit::WRONG_CODE_RECEIVED:
        ignition_state_icon->setStyleSheet("QLabel {image: url(:/assets/password.png);}");
        info_ignition->setText("The GSE informs you that you are entering the wrong code - No Ignition - Permission denied");
        break;
    case ignit::ARMED:
        ignition_state_icon->setStyleSheet("QLabel {image: url(:/assets/warning.png);}");
        info_ignition->setText("GSE confirmation : Code is correct - ARMED - Ready for Ignition !");

        break;
    case ignit::IGNITION_ON:
        ignition_state_icon->setStyleSheet("QLabel {image: url(:/assets/fire.png);}");
        info_ignition->setText("Ignition circuit active ! Igniters should be burning!");
#ifdef SOUND_ON
        // playSound(takeoff);
#endif
        break;
    }

#ifdef SOUND_ON
    if (key1 && key2 && clicked) {
        if (m_player->state() != QMediaPlayer::PlayingState) {
            playSound(alarm);
        }
    } else {
        if (m_player->media() == QMediaContent(QUrl(alarm))) {
            m_player->stop();
        }
    }
    if (data_->eatData<bool>(IGNITION_SENT, false)) playSound(takeoff);
#endif // SOUND_ON
}

void SecondWindow::initialize_slots_signals()
{
    connect(timer_, SIGNAL(timeout()), this, SLOT(refresh_data()));
    connect(xbee_button, SIGNAL(pressed()), this, SLOT(xbee_clicked()));
    connect(reset_button, SIGNAL(pressed()), this, SLOT(reset_button_pressed()));
    connect(ready_ignit_button, SIGNAL(pressed()), this, SLOT(ignite_clicked()));
    connect(change_theme, SIGNAL(pressed()), this, SLOT(theme_change_clicked()));
    connect(file_transmission_button, SIGNAL(pressed()), this, SLOT(file_transmission_pressed()));
    connect(valve_button,SIGNAL(pressed()), this, SLOT(valve_control()));
    connect(play_music,SIGNAL(pressed()), this, SLOT(play_music_pressed()));
    connect(rssi_button,SIGNAL(pressed()), this, SLOT(rssi_get_pressed()));
}

void SecondWindow::refresh_telemetry()
{
    altitude_panel_telemetry->setText(qstr(data_->getData<float>(T_ALTITUDE)));
    accel_x_panel->setText(qstr(data_->getData<float>(T_ACCELEROMETER_X)));
    accel_y_panel->setText(qstr(data_->getData<float>(T_ACCELEROMETER_Y)));
    accel_z_panel->setText(qstr(data_->getData<float>(T_ACCELEROMETER_Z)));
    euler_x_panel->setText(qstr(data_->getData<float>(T_EULER_X)));
    euler_y_panel->setText(qstr(data_->getData<float>(T_EULER_Y)));
    euler_z_panel->setText(qstr(data_->getData<float>(T_EULER_Z)));
    pressure_panel->setText(qstr(data_->getData<float>(T_PRESSURE)));
    speed_panel->setText(qstr(data_->getData<float>(T_SPEED)));
    temperature_panel->setText(qstr(data_->getData<float>(T_TEMPERATURE)));
}

void SecondWindow::refresh_gps()
{
    altitude_lcd_gps->display(qstr(data_->getData<float>(GPS_ALTITUDE)));
    altitude_max_lcd_m->display(qstr(data_->getData<float>(ALTITUDE_MAX)));
    longitude_panel->setText(qstr(data_->getData<float>(GPS_LONGITUDE)));
    latitude_panel->setText(qstr(data_->getData<float>(GPS_LATITUDE)));
    hdop_panel->setText(qstr(data_->getData<float>(GPS_HDOP)));
    sat_nbr_panel->display(qstr(data_->getData<uint8_t>(GPS_SAT_NBR)));
}

void SecondWindow::refresh_com()
{
    refresh_misses();
    //last_packet_number_panel->setText(qstr(data_->getData<uint32_t>(TX_PACKET_NR)));
    std::string str(DatagramType::getDatagramIDName(data_->getData<uint8_t>(ui_interface::DATAGRAM_ID)));
    //last_datagram_id_panel->setText(QString::fromStdString(str));
    received_pack_cnt_panel->setText(qstr(data_->getData<uint32_t>(RX_PACKET_CTR)));
    // this->speed_lcd->display(data_->getData<float>(SPEED)); no speed
    time_t timestamp(data_->getData<time_t>(TIMESTAMP));
    char tbuffer[32];
    struct tm * tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 32, "%T", tptr);
    miss_panel->setText(qstr(calculate_misses_in_last_2()));
    this->last_refresh_panel->setText(tbuffer);
    uint32_t packets(data_->eatData<uint32_t>(PACKET_RX_RATE_CTR, 0));
    all_packet_rate->setValue((packets * (1000.0 / (REFRESH_RATE))));
    corrupted_panel->setText(qstr(data_->getData<uint64_t>(CORRUPTED_PACKET_CTR)));

    rssi_value->display(-1* (int) data_->getData<uint8_t>(ui_interface::RSSI_VALUE));
}

void SecondWindow::check_and_show()
{
    if (data_->eatData<bool>(FILE_TRANSMISSION_ALL_RECEIVED, false)) {
        QMessageBox::warning(this, "File", "File transmission finished - All received");
    }
}

void SecondWindow::refresh_time()
{
    time_t timestamp(std::time(nullptr));
    char tbuffer[32];
    struct tm * tptr = std::localtime(&timestamp);

    std::strftime(tbuffer, 32, "%H:%M:%S", tptr);
    time_panel->setText(tbuffer);
}

void SecondWindow::refresh_file_transmission_box()
{
    FileTransmissionStates state(data_->getData<FileTransmissionStates>(ui_interface::FILE_TRANSMISSION_RECEIVED_STATE));

    transmitter_state_panel->setText(QString::fromStdString(getStateName(state)));
    state = data_->getData<FileTransmissionStates>(ui_interface::FILE_TRANSMISSION_MY_STATE);
    receiver_state_panel->setText(QString::fromStdString(getStateName(state)));
    file_transmission_progress_bar->setMaximum(data_->getData<uint64_t>(ui_interface::FILE_TRANSMISSION_TOTAL_PACKETS));
    file_transmission_progress_bar->setValue(data_->getData<uint16_t>(ui_interface::FILE_TRANSMISSION_CURRENT_PACKET));
}

void SecondWindow::show_ok_X(QLabel * label, bool ok)
{
    (ok) ? show_ok(label) : show_X(label);
}

void SecondWindow::show_ok(QLabel * label)
{
    label->setStyleSheet(QLatin1String("color: rgb(0, 255, 0);"));
    label->setText("OK");
}

void SecondWindow::show_X(QLabel * label)
{
    label->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);"));
    label->setText("X");
}

void SecondWindow::keyPressEvent(QKeyEvent * ckey)
{
    if (ckey->key() == Qt::Key_F11 || ckey->key() == Qt::Key_F) {
        fullscreen_ = !fullscreen_;
    }
    (fullscreen_) ? showFullScreen() : showNormal();
}

void SecondWindow::play_music_pressed() {
    musicON_ = !musicON_;
    if (!musicON_) {
        verticalSlider_1->setValue(0);
        verticalSlider_2->setValue(0);
        verticalSlider_3->setValue(0);
        verticalSlider_4->setValue(0);
        verticalSlider_5->setValue(0);
        verticalSlider_11->setValue(0);
        verticalSlider_12->setValue(0);
        verticalSlider_13->setValue(0);
        verticalSlider_14->setValue(0);
        verticalSlider_15->setValue(0);
#ifdef SOUND_ON
        m_player->stop();
#endif
    }
}

void SecondWindow::rssi_get_pressed() {
    data_->setData(ui_interface::RSSI_READ_ORDER, true);
}

#ifdef SOUND_ON
void SecondWindow::playSound(const char * url)
{
    m_player->stop();
    m_player->setMedia(QUrl(url));
    m_player->setVolume(100);
    m_player->play();
}
#endif
