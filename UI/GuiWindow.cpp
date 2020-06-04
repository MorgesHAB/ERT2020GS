/*!
 * \file GuiWindow.h
 *
 * \brief Gui Window module implementation
 *
 * \author      KESKE CEM - EPFL EL BA3
 * \date        02.12.2019
 */

#include "GuiWindow.h"
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
#include "../Telecom/DataStructures/GSE/IgnitionStates.h"
#include "gui_message.h"
#include "../Logger/utilities.h"

#include <QStyleFactory>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QCoreApplication>


constexpr uint32_t REFRESH_RATE(500);

using namespace ui_interface;



//-----Helpful Inline Utility Functions for GUI-----

inline QString degree_representation(double value)
{
    return QString::number(value) + "<sup>o</sup>";
}

template <typename T> inline QString qstr(T value)
{
    return QString::number(value);
}

inline bool get_bit(unsigned char byte, int position) // position in range 0-7
{
    return (byte >> position) & 0x1;
}



// GUI Window Class Functions

GuiWindow::GuiWindow(std::shared_ptr<Connector> connector) :
    timer_(new QTimer(this)),
    data_(connector),
    current_theme_(0),
    ready_ignition_(false),
    xbee_acvite_(false),
    fullscreen_(false)
{
#ifdef SOUND_ON
    m_player = new QMediaPlayer();
    alarm    = "qrc:/assets/nuclear_alarm.mp3";
    takeoff  = "qrc:/assets/launch.mp3";
    hymne    = "qrc:/assets/hymne.mp3";
    playSound(hymne);
#endif
    initialize_style();
    initialize_slots_signals();
    grabKeyboard();
    timer_->start(REFRESH_RATE);
}

void GuiWindow::reset_button_pressed()
{
    constexpr uint64_t z(0);
    for (auto& index : dataToReset) data_->setData(index, z);
}

void GuiWindow::refresh_data()
{
    refresh_com();
    refresh_av_state();
    refresh_telemetry();
    refresh_time();
    check_and_show();
    refresh_ignition_frame();
    refresh_gps();
    refresh_file_transmission_box();
    ++tick_counter_;
}

void GuiWindow::xbee_clicked()
{
    if (!xbee_acvite_) {
        //logger.log(new Gui_Message("XBee ON button clicked!"));
        std::cout << "XBee ON button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, true);
        xbee_button->setText("STOP XBee");
    } else {
        //logger.log(new Gui_Message("XBee STOP button clicked!"));
        std::cout << "XBee STOP button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, false);
        xbee_button->setText("START XBee");
    }
    xbee_acvite_ = !xbee_acvite_;
}

void GuiWindow::ignite_clicked()
{
    std::cout << "Ignition button clicked!" << std::endl;
    ready_ignition_ = data_->getData<bool>(IGNITION_CLICKED);
    ready_ignition_ = !ready_ignition_;
    data_->setData(ui_interface::IGNITION_CLICKED, ready_ignition_);
    show_ok_X(ready_ignition_panel, ready_ignition_);
}

void GuiWindow::theme_change_clicked()
{
    current_theme_ = ((current_theme_ + 1) % THEME_COUNT);

    std::string str("Theme change button clicked. ");

    if (current_theme_ == WHITE_ON_BLACK) {
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
    }
}

void GuiWindow::file_transmission_pressed()
{
    data_->setData(ui_interface::SEND_FILE_REQUEST, true);
}
/*
uint16_t GuiWindow::calculate_misses()
{
    static std::array<uint32_t, 1000 / REFRESH_RATE> before{ 0 };

    uint16_t current(tick_counter_ % 1000 / REFRESH_RATE);
    uint16_t tmp(missed_count_ - before[current]); // change

    before[current] = missed_count_;
    return tmp;
}
*/
void GuiWindow::closeEvent(QCloseEvent * event)
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
/*
 * Not used anymore as the packet number isn't sent.
 * 
void GuiWindow::refresh_misses()
{
    missed_count_ = data_->getData<uint32_t>(TX_PACKET_NR)
                    - data_->getData<uint32_t>(RX_PACKET_CTR);
}
*/
void GuiWindow::refresh_ignition_code()
{
    uint8_t tmp(data_->getData<uint8_t>(ui_interface::TX_IGNITION_CODE));

    code_0->setText(QString::number(get_bit(tmp, 0)));
    code_1->setText(QString::number(get_bit(tmp, 1)));
    code_2->setText(QString::number(get_bit(tmp, 2)));
    code_3->setText(QString::number(get_bit(tmp, 3)));
}

void GuiWindow::refresh_av_state()
{
    std::string str(avionic::getAVStateName(data_->getData<uint8_t>(STATUS_AV_STATE)));
    avionics_state_panel->setText(QString::fromStdString(str));
}

void GuiWindow::initialize_style()
{
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles);
    QApplication::setStyle(QStyleFactory::create("cleanlooks"));
    Ui_Form::setupUi(this);
}

void GuiWindow::refresh_ignition_frame()
{
    refresh_ignition_code();

    bool key1    = data_->getData<bool>(IGNITION_KEY_1_ACTIVATED);
    bool key2    = data_->getData<bool>(IGNITION_KEY_2_ACTIVATED);
    bool button  = data_->getData<bool>(IGNITION_RED_BUTTON_PUSHED);
    bool clicked = data_->getData<bool>(IGNITION_CLICKED);


    show_ok_X(key_1_panel, key1);
    show_ok_X(key_2_panel, key2);
    show_ok_X(red_button_panel, button);
    show_ok_X(ready_ignition_panel, clicked);

    // Ignition status
    std::string str(ignit::getIgnitionState(
        data_->eatData<ignit::IgnitionState>(IGNITION_STATUS, ignit::SLEEP)));
    ignition_status_label->setText(QString::fromStdString(str));

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
#endif // ifdef SOUND_ON
}

void GuiWindow::initialize_slots_signals()
{
    connect(timer_, SIGNAL(timeout()), this, SLOT(refresh_data()));
    connect(xbee_button, SIGNAL(pressed()), this, SLOT(xbee_clicked()));
    connect(reset_button, SIGNAL(pressed()), this, SLOT(reset_button_pressed()));
    connect(ignition_button, SIGNAL(pressed()), this, SLOT(ignite_clicked()));
    connect(change_theme, SIGNAL(pressed()), this, SLOT(theme_change_clicked()));
    connect(file_transmission_button, SIGNAL(pressed()), this, SLOT(file_transmission_pressed()));
}

void GuiWindow::refresh_telemetry()
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

void GuiWindow::refresh_gps()
{
    altitude_lcd_gps->display(qstr(data_->getData<float>(GPS_ALTITUDE)));
    altitude_max_lcd_m->display(qstr(data_->getData<float>(ALTITUDE_MAX)));
    longitude_panel->setText(qstr(data_->getData<float>(GPS_LONGITUDE)));
    latitude_panel->setText(qstr(data_->getData<float>(GPS_LATITUDE)));
    hdop_panel->setText(qstr(data_->getData<float>(GPS_HDOP)));
    sat_nbr_panel->setText(qstr(data_->getData<uint8_t>(GPS_SAT_NBR)));
}

void GuiWindow::refresh_com()
{
    last_packet_number_panel->setText(qstr(data_->getData<uint32_t>(TX_PACKET_NR)));
    std::string str(DatagramType::getDatagramIDName(data_->getData<uint8_t>(ui_interface::DATAGRAM_ID)));
    last_datagram_id_panel->setText(QString::fromStdString(str));
    received_pack_cnt_panel->setText(qstr(data_->getData<uint32_t>(RX_PACKET_CTR)));
    uint32_t packets(data_->eatData<uint32_t>(PACKET_RX_RATE_CTR, 0));
    packets_second_bar->setValue((packets * (1000.0 / (REFRESH_RATE))));
    corrupted_panel->setText(qstr(data_->getData<uint64_t>(CORRUPTED_PACKET_CTR)));
}

void GuiWindow::check_and_show()
{
    using namespace ignit;
    switch (data_->eatData<IgnitionState>(IGNITION_STATUS, ignit::SLEEP)) {
    case WRONG_CODE_RECEIVED:
        QMessageBox::warning(this, "GSE Info", "The GSE informs you that you are entering the wrong code - No Ignition - Permission denied");
        break;
    case ARMED:
        QMessageBox::warning(this, "GSE Info", "GSE confirmation : Code is correct - ARMED - Ready for Ignition !");
        break;
    case IGNITION_ON:
#ifdef SOUND_ON
        // playSound(takeoff);
#endif
        QMessageBox::warning(this, "GSE Info", "Ignition circuit active ! Igniters should be burning!");
        break;
    default:
        break;
    }

    if (data_->eatData<bool>(FILE_TRANSMISSION_ALL_RECEIVED, false)) {
        QMessageBox::warning(this, "File", "File transmission finished - All received");
    }
}

void GuiWindow::refresh_time()
{
    time_panel->setText(QString::fromStdString(utilities::time()));
}

void GuiWindow::refresh_file_transmission_box()
{
    FileTransmissionStates state(data_->getData<FileTransmissionStates>(ui_interface::FILE_TRANSMISSION_RECEIVED_STATE));

    transmitter_state_panel->setText(QString::fromStdString(getStateName(state)));
    state = data_->getData<FileTransmissionStates>(ui_interface::FILE_TRANSMISSION_MY_STATE);
    receiver_state_panel->setText(QString::fromStdString(getStateName(state)));
    file_transmission_progress_bar->setMaximum(data_->getData<uint64_t>(ui_interface::FILE_TRANSMISSION_TOTAL_PACKETS));
    file_transmission_progress_bar->setValue(data_->getData<uint16_t>(ui_interface::FILE_TRANSMISSION_CURRENT_PACKET));
}

inline void GuiWindow::show_ok_X(QLabel * label, bool ok)
{
    (ok) ? show_ok(label) : show_X(label);
}

void GuiWindow::show_ok(QLabel * label)
{
    label->setStyleSheet(QLatin1String("color: rgb(0, 255, 0);"));
    label->setText("OK");
}

void GuiWindow::show_X(QLabel * label)
{
    label->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);"));
    label->setText("X");
}

void GuiWindow::keyPressEvent(QKeyEvent * ckey)
{
    if (ckey->key() == Qt::Key_F11 || ckey->key() == Qt::Key_F) {
        fullscreen_ = !fullscreen_;
    }
    (fullscreen_) ? showFullScreen() : showNormal();
}

#ifdef SOUND_ON
void GuiWindow::playSound(const char * url)
{
    m_player->stop();
    m_player->setMedia(QUrl(url));
    m_player->setVolume(100);
    m_player->play();
}

#endif
