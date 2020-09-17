/*!
 * \file SecondWindow.cpp
 *
 * \brief Gui Window module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        22.03.2020
 */

#include "SecondWindow.h"

#include <chrono>
#include <iostream>
#include <ctime>
#include <array>


#include "../Telecom/DataStructures/Avionics/StateValues.h"
#include "../Telecom/DataHandler/DatagramTypes.h"
#include "../Telecom/DataStructures/File/FileTransmissionStates.h"
#include "../Telecom/DataStructures/GSE/IgnitionStates.h"

#include <QStyleFactory>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QCoreApplication>


constexpr uint32_t REFRESH_RATE(500);

using namespace ui_interface;

void SecondWindow::refresh_data()
{
    refresh_com();
    refresh_av_state();
    refresh_telemetry();
    refresh_time();
    check_and_show();
    refresh_ignition_frame();
    refresh_gps();
    refresh_file_transmission();
    refresh_lionel_stuff();
    ++tick_counter_;
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
    connector(connector),
    missed_count_(0),
    current_theme_(0),
    ready_ignition_(false),
    xbee_acvite_(false),
    fullscreen_(false),
    musicON_(false),
    FTX_beginning_time(0)
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
    connector->setData(ui_interface::TIME_SINCE_LAST_RX_PACKET, std::time(nullptr));
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
    a = !a;

    auto serialStatus = connector->getData<int>(ui_interface::SERIALPORT_STATUS);
    serialport_status->setStyleSheet(
            (serialStatus == 0) ? "QLabel {image: url(:/assets/refresh.png);}"
                                : (serialStatus == 1)
                                  ? "QLabel {image: url(:/assets/correct.png);}"
                                  : "QLabel {image: url(:/assets//redCross.png);}");
}

void SecondWindow::valve_control() {
    static int x(0);
    connector->setData(IGNITION_STATUS, (ignit::IgnitionState) x);
    x+=1;
}

void SecondWindow::reset_button_pressed()
{
    constexpr uint64_t z(0);
    for (auto& index : dataToReset) connector->setData(index, z);
}

void SecondWindow::xbee_clicked()
{
    if (!xbee_acvite_) {
        xbee_button->setStyleSheet("QPushButton{\n"
                                   "qproperty-icon: url(:/assets/powerOFF.png);\n"
                                   "qproperty-iconSize: 55px;\n"
                                   "border-radius: 25px;\n"
                                   "}\n");
        //logger.log(new Gui_Message("XBee ON button clicked!"));
        std::cout << "XBee ON button clicked!" << std::endl;
        uint64_t index(serialport_selector->currentIndex());
        connector->setData(ui_interface::SERIALPORT_INDEX, index);
        connector->setData(ui_interface::ACTIVE_XBEE, true);
    } else {
        xbee_button->setStyleSheet("QPushButton{\n"
                                   "qproperty-icon: url(:/assets/powerON.png);\n"
                                   "qproperty-iconSize: 55px;\n"
                                   "border-radius: 25px;\n"
                                   "}\n");
        //logger.log(new Gui_Message("XBee STOP button clicked!"));
        std::cout << "XBee STOP button clicked!" << std::endl;
        connector->setData(ui_interface::ACTIVE_XBEE, false);
    }
    xbee_acvite_ = !xbee_acvite_;
}

void SecondWindow::ignite_clicked()
{
    ready_ignition_ = connector->getData<bool>(IGNITION_CLICKED);
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
    connector->setData(ui_interface::IGNITION_CLICKED, ready_ignition_);
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
    connector->setData(ui_interface::SEND_FILE_REQUEST, true);
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
        connector->setData(ui_interface::RUNNING, false);
        std::cout << "running set to false" << std::endl;
    }
}

void SecondWindow::refresh_misses()
{
    missed_count_ = connector->getData<uint32_t>(TX_PACKET_NR)
                    - connector->getData<uint32_t>(RX_PACKET_CTR);
}

void SecondWindow::refresh_ignition_code()
{
    uint8_t tmp(connector->getData<uint8_t>(ui_interface::TX_IGNITION_CODE));

    code_0->setText(QString::number(get_bit(tmp, 0)));
    code_1->setText(QString::number(get_bit(tmp, 1)));
    code_2->setText(QString::number(get_bit(tmp, 2)));
    code_3->setText(QString::number(get_bit(tmp, 3)));
}

void SecondWindow::refresh_av_state()
{
    std::string str(avionic::getAVStateName(connector->getData<uint8_t>(STATUS_AV_STATE)));
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

    bool key1    = connector->getData<bool>(IGNITION_KEY_1_ACTIVATED);
    bool key2    = connector->getData<bool>(IGNITION_KEY_2_ACTIVATED);
    bool button  = connector->getData<bool>(IGNITION_RED_BUTTON_PUSHED);
    bool clicked = connector->getData<bool>(IGNITION_CLICKED);

    // Keys
    ignition_key1->setStyleSheet((key1) ? "QLabel {image: url(:/assets/keyON.png);}"
                                        : "QLabel {image: url(:/assets/keyOFF.png);}");
    ignition_key2->setStyleSheet((key2) ? "QLabel {image: url(:/assets/keyON.png);}"
                                        : "QLabel {image: url(:/assets/keyOFF.png);}");

    // Ignition status
    auto ignitState = connector->getData<ignit::IgnitionState>(IGNITION_STATUS);
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
    if (connector->eatData<bool>(IGNITION_SENT, false)) playSound(takeoff);
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
    connect(send_msg,SIGNAL(pressed()), this, SLOT(send_msg_pressed()));
    connect(clear_image,SIGNAL(pressed()), this, SLOT(clear_image_pressed()));
    connect(PL_image_abort,SIGNAL(pressed()), this, SLOT(image_abort_pressed()));
    connect(ftx_missing_request,SIGNAL(pressed()), this, SLOT(ftx_missing_request_pressed()));
    connect(ftx_save_file,SIGNAL(pressed()), this, SLOT(ftx_save_file_pressed()));
}

void SecondWindow::refresh_telemetry()
{
    altitude_panel_telemetry->setText(qstr(connector->getData<float>(T_ALTITUDE)));
    accel_x_panel->setText(qstr(connector->getData<float>(T_ACCELEROMETER_X)));
    accel_y_panel->setText(qstr(connector->getData<float>(T_ACCELEROMETER_Y)));
    accel_z_panel->setText(qstr(connector->getData<float>(T_ACCELEROMETER_Z)));
    euler_x_panel->setText(qstr(connector->getData<float>(T_EULER_X)));
    euler_y_panel->setText(qstr(connector->getData<float>(T_EULER_Y)));
    euler_z_panel->setText(qstr(connector->getData<float>(T_EULER_Z)));
    pressure_panel->setText(qstr(connector->getData<float>(T_PRESSURE)));
    speed_panel->setText(qstr(connector->getData<float>(T_SPEED)));
    temperature_panel->setText(qstr(connector->getData<float>(T_TEMPERATURE)));
}

void SecondWindow::refresh_gps()
{
    altitude_lcd_gps->display(qstr((int) connector->getData<float>(GPS_ALTITUDE)));
    altitude_max_lcd_m->display(qstr((int) connector->getData<float>(ALTITUDE_MAX)));
    longitude_panel->setText(qstr(connector->getData<float>(GPS_LONGITUDE)));
    latitude_panel->setText(qstr(connector->getData<float>(GPS_LATITUDE)));
    hdop_panel->setText(qstr(connector->getData<float>(GPS_HDOP)));
    sat_nbr_panel->display(qstr(connector->getData<uint8_t>(GPS_SAT_NBR)));
}

void SecondWindow::refresh_com()
{
    refresh_misses();
    //last_packet_number_panel->setText(qstr(connector->getData<uint32_t>(TX_PACKET_NR)));
    std::string str(DatagramType::getDatagramIDName(connector->getData<uint8_t>(ui_interface::LAST_DATAGRAM_ID)));
    //last_datagram_id_panel->setText(QString::fromStdString(str));
    received_pack_cnt_panel->setText(qstr(connector->getData<uint64_t>(TOTAL_RX_PACKET_CTR)));
    // this->speed_lcd->display(connector->getData<float>(SPEED)); no speed
    time_t timestamp(connector->getData<time_t>(TIMESTAMP));
    char tbuffer[32];
    struct tm * tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 32, "%T", tptr);
    miss_panel->setText(qstr(calculate_misses_in_last_2()));
    //this->last_refresh_panel->setText(tbuffer);
    uint32_t coef(1000.0 / REFRESH_RATE);
    all_packet_rate->setValue((connector->eatData<uint32_t>(PACKET_CTR_ALL, 0) * coef));
    AV_packet_rate->setValue((connector->eatData<uint32_t>(PACKET_CTR_AV, 0) * coef));
    PL_packet_rate->setValue((connector->eatData<uint32_t>(PACKET_CTR_PL, 0) * coef));
    GSE_packet_rate->setValue((connector->eatData<uint32_t>(PACKET_CTR_GSE, 0) * coef));
    PP_packet_rate->setValue((connector->eatData<uint32_t>(PACKET_CTR_PP, 0) * coef));

    corrupted_panel->setText(qstr(connector->getData<uint64_t>(CORRUPTED_PACKET_CTR)));

    // call this every X seconds if you want or update when  RSSSI button clicked
    //connector->setData(ui_interface::RSSI_READ_ORDER, true);
    rssi_value->display(-1* (int) connector->getData<uint8_t>(ui_interface::RSSI_VALUE));

    // Time since last received packet
    time_t t = difftime(std::time(nullptr), connector->getData<time_t>(ui_interface::TIME_SINCE_LAST_RX_PACKET));
    struct tm* tt = gmtime(&t);
    char buf[32];
    std::strftime(buf, 32, "%T", tt);
    time_since_last_Rx->setText(buf);
}

void SecondWindow::check_and_show()
{

}

void SecondWindow::refresh_time()
{
    time_t timestamp(std::time(nullptr));
    char tbuffer[32];
    struct tm * tptr = std::localtime(&timestamp);

    std::strftime(tbuffer, 32, "%H:%M:%S", tptr);
    time_panel->setText(tbuffer);
}

void SecondWindow::refresh_file_transmission()
{
    auto state(connector->getData<FileTransmissionStates>(ui_interface::FILE_TRANSMISSION_RECEIVED_STATE));
    transmitter_state_panel->setText(QString::fromStdString(getStateName(state)));
    state = connector->getData<FileTransmissionStates>(ui_interface::FILE_TRANSMISSION_MY_STATE);
    receiver_state_panel->setText(QString::fromStdString(getStateName(state)));

    auto packetTotNbr(connector->getData<uint32_t>(ui_interface::FILE_TRANSMISSION_TOTAL_PACKETS));
    auto packetNbr(connector->getData<uint32_t>(ui_interface::FILE_TRANSMISSION_CURRENT_PACKET));
    file_transmission_progress_bar->setMaximum(packetTotNbr);
    file_transmission_progress_bar->setValue(packetNbr);

    if (connector->eatData<bool>(ui_interface::FTX_FILE_TX_SENT, false)) {
        FTX_beginning_time = std::time(nullptr);
        PL_state_file_Tx_sent->setStyleSheet("QLabel {image: url(:/assets/correct.png);}");
    }
    if (connector->eatData<bool>(ui_interface::FTX_PL_RESPONSE, false))
        PL_state_payload_response->setStyleSheet("QLabel {image: url(:/assets/correct.png);}");
    if (connector->eatData<bool>(ui_interface::FTX_MISSING_REQUEST_SENT, false))
        PL_state_missing_request_sent->setStyleSheet("QLabel {image: url(:/assets/correct.png);}");
    if (connector->eatData<bool>(ui_interface::FTX_ALL_RECEIVED, false))
        PL_state_all_received->setStyleSheet("QLabel {image: url(:/assets/correct.png);}");
    if (connector->eatData<bool>(ui_interface::FTX_ACK_SENT, false)) {
        FTX_beginning_time = 0;
        PL_state_ack_sent->setStyleSheet("QLabel {image: url(:/assets/correct.png);}");
    }

    if (connector->eatData<bool>(FILE_TRANSMISSION_ALL_RECEIVED, false)) {
        PL_image_display->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QPixmap img(QString::fromStdString(connector->getImgPLfilename()));
        PL_image_display->setPixmap(img);
    }

    // Time since the beginning of the File transmission
    if (FTX_beginning_time != 0) {
        time_t t = difftime(std::time(nullptr), FTX_beginning_time);
        struct tm *tt = gmtime(&t);
        char buf[32];
        std::strftime(buf, 32, "%T", tt);
        ftx_beginning_time->setText(buf);

        // Time left
        if (PL_packet_rate->value() != 0) {
            t = (packetTotNbr - packetNbr) / PL_packet_rate->value();
            tt = gmtime(&t);
            std::strftime(buf, 32, "%T", tt);
            ftx_time_left->setText(buf);
        }
    }
    // Packet counter
    auto Rx_packet_ctr(connector->getData<uint64_t>(ui_interface::FTX_RX_PACKET_CTR));
    ftx_packet_ctr->setText(qstr((Rx_packet_ctr > 0) ? Rx_packet_ctr - 1 : 0));
    ftx_missed_packets->setText(qstr((packetNbr > Rx_packet_ctr) ? packetNbr - Rx_packet_ctr - 1 : 0));
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
    connector->setData(ui_interface::RSSI_READ_ORDER, true);
}

void SecondWindow::send_msg_pressed() {
    // for test
    connector->setData(ui_interface::RSSI_VALUE, (uint8_t) (rand() % 100));
    //password_line_edit->setText("hey !!");
    std::cout << password_line_edit->text().toStdString() << std::endl;
}

void SecondWindow::clear_image_pressed() {
    PL_image_display->clear();
    PL_state_file_Tx_sent->setStyleSheet("QLabel {image: url(:/assets/refresh.png);}");
    PL_state_payload_response->setStyleSheet("QLabel {image: url(:/assets/refresh.png);}");
    PL_state_missing_request_sent->setStyleSheet("QLabel {image: url(:/assets/refresh.png);}");
    PL_state_all_received->setStyleSheet("QLabel {image: url(:/assets/refresh.png);}");
    PL_state_ack_sent->setStyleSheet("QLabel {image: url(:/assets/refresh.png);}");
    connector->setData(ui_interface::FTX_FILE_TX_SENT, false);
    connector->setData(ui_interface::FTX_PL_RESPONSE, false);
    connector->setData(ui_interface::FTX_MISSING_REQUEST_SENT, false);
    connector->setData(ui_interface::FTX_ALL_RECEIVED, false);
    connector->setData(ui_interface::FTX_ACK_SENT, false);
    connector->setData(ui_interface::FILE_TRANSMISSION_TOTAL_PACKETS, 0);
    connector->setData(ui_interface::FILE_TRANSMISSION_CURRENT_PACKET, 0);
    ftx_beginning_time->setText("...");
    ftx_time_left->setText("...");
    connector->reset(ui_interface::FTX_RX_PACKET_CTR);
}

void SecondWindow::image_abort_pressed() {
    connector->setData(ui_interface::FILE_TRANSMISSION_ABORT_ORDER, true);
    FTX_beginning_time = 0;
}

void SecondWindow::ftx_missing_request_pressed() {
    connector->setData(ui_interface::FTX_SEND_MISSING_REQUEST, true);
}

void SecondWindow::ftx_save_file_pressed() {
    connector->setData(ui_interface::FTX_SAVE_FILE, true);
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
