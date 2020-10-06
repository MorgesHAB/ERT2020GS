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
#include <cmath>
#include "../Telecom/DataStructures/Avionics/StateValues.h"
#include "../Telecom/DataHandler/DatagramTypes.h"
#include "../Telecom/DataStructures/File/FileTransmissionStates.h"
#include "../Telecom/DataStructures/GSE/IgnitionStates.h"
#include "../Telecom/DataStructures/GSE/GSEOrderValue.h"
#include "Gui_message.h"
#include "../Logger/utilities.h"

#include <QStyleFactory>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QCoreApplication>
#include <QInputDialog>
#include <QDir>


constexpr uint32_t REFRESH_RATE(500);
constexpr float M_TO_FT(3.2808399);
constexpr uint32_t FREQUENCY(1000.0 / REFRESH_RATE);
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
    logger(5,"GUI"),
    timer_(new QTimer(this)),
    data_(connector),
    current_theme_(0),
    password_("EPFL"),
    manual_mode(false),
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
    init_password();
    //grabKeyboard(); otherwise can't enter password
    timer_->start(REFRESH_RATE);
    logger.log(new Gui_Message("Gui started."));

}

void GuiWindow::fill_valve_open_pressed()
{
    data_->setData(ui_interface::GSE_OPEN_FILL_VALVE, true);
    logger.log(new Gui_Message("FILL valve OPEN button pressed"));
    data_->setData(ui_interface::GSE_ORDER, gse::OPEN_FILLING);
}

void GuiWindow::purge_valve_open_pressed()
{
    data_->setData(ui_interface::GSE_OPEN_PURGE_VALVE, true);
    data_->setData(ui_interface::GSE_ORDER, gse::OPEN_PURGE);
    logger.log(new Gui_Message("PURGE valve OPEN button pressed"));
}

void GuiWindow::fill_valve_close_pressed()
{
    data_->setData(ui_interface::GSE_CLOSE_FILL_VALVE, true);
    data_->setData(ui_interface::GSE_ORDER, gse::CLOSE_FILLING);
    logger.log(new Gui_Message("FILL valve CLOSE button pressed"));
}

void GuiWindow::purge_valve_close_pressed()
{
    data_->setData(ui_interface::GSE_CLOSE_PURGE_VALVE, true);
    data_->setData(ui_interface::GSE_ORDER, gse::CLOSE_PURGE);
    logger.log(new Gui_Message("PURGE valve CLOSE button pressed"));
}

void GuiWindow::disconnect_wire_pressed()
{
    //TODO find a way to delete
    data_->setData(ui_interface::GSE_DISCONNECT_WIRE, true);
    data_->setData(ui_interface::GSE_ORDER, gse::DISCONNECT_HOSE);
    auto* message = new Gui_Message("DISCONNECT wire button pressed");
    logger.log(message);
    delete message;
}

void GuiWindow::manual_mode_pressed()
{
    logger.log(new Gui_Message("Manual mode button pressed"));
    if(ask_password()){
        manual_mode = true;
        QMessageBox::information(this,"Manual Mode","Manual mode is activated");
        logger.log(new Gui_Message("Manual mode activated."));
        manual_mode_button->setCheckable(true);
        manual_mode_button->setEnabled(false);
        manual_mode_button->setChecked(true);
    }

}

void GuiWindow::rssi_request_pressed()
{
     logger.log(new Gui_Message("RSSI request button pressed"));
     data_->setData(ui_interface::RSSI_READ_ORDER, true);

}

void GuiWindow::reset_button_pressed()
{
    logger.log(new Gui_Message("Reset button pressed. Data reset."));
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
    refresh_serial_status();
    refresh_payload();
    refresh_ack_blinking();

    ++tick_counter_;
}

void GuiWindow::xbee_clicked()
{
    if (!xbee_acvite_) {
        logger.log(new Gui_Message("XBee ON button clicked!"));
        std::cout << "XBee ON button clicked!" << std::endl;
        uint64_t index = serialport_selector->currentIndex();
        data_->setData(ui_interface::SERIALPORT_INDEX, index); //index selection hardcoded inside the telecom worker :(
        data_->setData(ui_interface::ACTIVE_XBEE, true);
        logger.log(new Gui_Message("XBee port no " + std::to_string(index) + "selected."));
        xbee_button->setText("STOP XBee");
    } else {
        logger.log(new Gui_Message("XBee STOP button clicked!"));
        std::cout << "XBee STOP button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, false);
        xbee_button->setText("START XBee");
    }
    xbee_acvite_ = !xbee_acvite_;
}

void GuiWindow::ignite_clicked()
{
    std::cout << "Ignition button clicked!" << std::endl;
    std::string str("Ignition toggled. The state is: ");
    ready_ignition_ = data_->getData<bool>(IGNITION_CLICKED);
    ready_ignition_ = !ready_ignition_;
    data_->setData(ui_interface::IGNITION_CLICKED, ready_ignition_);
    show_ok_X(ready_ignition_panel, ready_ignition_);
    logger.log(new Gui_Message(str.append(ready_ignition_? "READY" : "NOT READY")));
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
    logger.log(new Gui_Message(str));
}

void GuiWindow::file_transmission_pressed()
{
    logger.log(new Gui_Message("File transmission request button pressed."));
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
    logger.log(new Gui_Message("Window close attempt..."));
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "BELLA LUI 2020",
                                                               tr("Ending mission Bella Lui 2020.\nAre you sure?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes) {
        event->ignore();
        logger.log(new Gui_Message("Window close rejected."));
    } else {
        logger.log(new Gui_Message("Window close accepted, exiting program."));
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

    show_ok_X(sleep_state_ok_panel, data_->getData<bool>(ui_interface::SLEEP_REACHED));
    show_ok_X(calibration_state_ok_panel, data_->getData<bool>(ui_interface::CALIBRATION_REACHED));
    show_ok_X(idle_state_ok_panel, data_->getData<bool>(ui_interface::IDLE_REACHED));
    show_ok_X(filling_av_ok_panel, data_->getData<bool>(ui_interface::FILLING_REACHED));
    show_ok_X(liftoff_state_ok_panel, data_->getData<bool>(ui_interface::LIFTOFF_REACHED));
    show_ok_X(coast_state_ok_panel, data_->getData<bool>(ui_interface::COAST_REACHED));
    show_ok_X(first_event_ok_panel, data_->getData<bool>(ui_interface::PRIMARY_EVENT_REACHED));
    show_ok_X(second_event_ok_panel, data_->getData<bool>(ui_interface::SECONDARY_EVENT_REACHED));
    show_ok_X(touchdown_event_ok_panel, data_->getData<bool>(ui_interface::TOUCH_DOWN_REACHED));
}

void GuiWindow::refresh_payload()
{

    pl_sat_nbr_panel->setText(qstr(data_->getData<uint8_t>(ui_interface::PL_GPS_SAT_NBR)));
    pl_longitude_panel->setText(qstr(data_->getData<float>(ui_interface::PL_GPS_LONGITUDE)));
    pl_latitude_panel->setText(qstr(data_->getData<float>(ui_interface::PL_GPS_LATITUDE)));
    pl_hdop_panel->setText(qstr(data_->getData<float>(ui_interface::PL_GPS_HDOP)));
    pl_gps_altitude_panel->setText(qstr(data_->getData<float>(ui_interface::PL_GPS_ALTITUDE)));


    pl_bno_temperature_panel->setText(qstr(data_->getData<uint8_t>(ui_interface::PL_BNO_TEMPERATURE)));
    pl_bno_oz_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BNO_ORIENTATION_Z)));
    pl_bno_oy_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BNO_ORIENTATION_Y)));
    pl_bno_ox_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BNO_ORIENTATION_X)));
    pl_bno_az_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BNO_ACCELERATION_Z)));
    pl_bno_ay_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BNO_ACCELERATION_Y)));
    pl_bno_ax_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BNO_ACCELERATION_X)));

    pl_bme_temperature_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BME_TEMPERATURE)));
    pl_bme_pressure_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BME_PRESSURE)));
    pl_bme_temperature_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BME_TEMPERATURE)));
    pl_bme_humidity_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BME_HUMIDITY)));
    pl_bme_altitude_panel->setText(qstr(data_->getData<float>(ui_interface::PL_BME_ALTITUDE)));
}

void GuiWindow::initialize_style()
{
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles);
    QApplication::setStyle(QStyleFactory::create("cleanlooks"));
    Ui_Form::setupUi(this);
}

void GuiWindow::init_password()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Password initialization"),
                                         tr("Enter a password to use when enabling the manual mode. "
                                            "\nIf you cancel this step the default password will be: EPFL"), QLineEdit::Normal,
                                         "EPFL", &ok, Qt::Tool);
    if (ok && !text.isEmpty())
        password_ = text.toStdString();
    logger.log(new Gui_Message("The password is set."));
    std::cout << "The password is set to " << text.toStdString() << std::endl;
}

bool GuiWindow::ask_password()
{
    logger.log(new Gui_Message("Asked password to user."));

    bool ok;
    QString text = QInputDialog::getText(this, tr("Authorization required"),
                                         tr("Enter the password if you have set one."
                                            "\nThe default password is: EPFL"), QLineEdit::Normal,
                                         "", &ok, Qt::Tool);
    bool result(false);
    if (ok && !text.isEmpty()){
        if(password_ == text.toStdString()){ //password is correct
            logger.log(new Gui_Message("Password was entered correctly."));
            result = true;

        } else {
            QMessageBox::warning(this, "Warning", "Wrong password, permission denied.");
            logger.log(new Gui_Message("Password wasn't correct."));
        }
    }

    std::cout << "The password is set to " << text.toStdString() << std::endl;
    return result;
}

void GuiWindow::refresh_ack_blinking() {

    auto order = data_->eatData<gse::GSEOrderValue>(ui_interface::GSE_ORDER_ACK, gse::NO_ORDER);

    switch (order){
        case gse::NO_ORDER :
            purge_open_button->setStyleSheet("");
            purge_close_button->setStyleSheet("");
            filling_open_button->setStyleSheet("");
            filling_close_button->setStyleSheet("");
            disconnect_wire_button->setStyleSheet("");
            break;
        case gse::OPEN_PURGE:
            purge_open_button->setStyleSheet("background-color: rgb(0, 255, 255);");
            break;
        case gse::CLOSE_PURGE:
            purge_close_button->setStyleSheet("background-color: rgb(0, 255, 255);");
            break;
        case gse::OPEN_FILLING:
            filling_open_button->setStyleSheet("background-color: rgb(0, 255, 255);");
            break;
        case gse::CLOSE_FILLING:
            filling_close_button->setStyleSheet("background-color: rgb(0, 255, 255);");
            break;
        case gse::DISCONNECT_HOSE:
            disconnect_wire_button->setStyleSheet("background-color: rgb(0, 255, 255);");
            break;
        default:
            purge_open_button->setStyleSheet("");
            purge_close_button->setStyleSheet("");
            filling_open_button->setStyleSheet("");
            filling_close_button->setStyleSheet("");
            disconnect_wire_button->setStyleSheet("");
            break;

    }
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
    connect(manual_mode_button, SIGNAL(pressed()), this, SLOT(manual_mode_pressed()));
    connect(request_rssi, SIGNAL(pressed()), this, SLOT(rssi_request_pressed()));
    connect(filling_open_button,SIGNAL(pressed()),this, SLOT(fill_valve_open_pressed()));
    connect(filling_close_button,SIGNAL(pressed()),this, SLOT(fill_valve_close_pressed()));
    connect(purge_open_button,SIGNAL(pressed()),this, SLOT(purge_valve_open_pressed()));
    connect(purge_close_button,SIGNAL(pressed()),this, SLOT(purge_valve_close_pressed()));
    connect(disconnect_wire_button, SIGNAL(pressed()),this, SLOT(disconnect_wire_pressed()));
}

void GuiWindow::refresh_telemetry()
{
    altitude_panel_telemetry->setText(qstr(data_->getData<float>(T_ALTITUDE)));

    float accelx(data_->getData<float>(T_ACCELEROMETER_X));
    float accely(data_->getData<float>(T_ACCELEROMETER_Y));
    float accelz(data_->getData<float>(T_ACCELEROMETER_Z));

    accel_x_panel->setText(qstr(accelx));
    accel_y_panel->setText(qstr(accely));
    accel_z_panel->setText(qstr(accelz));
    norm_panel->setText(qstr(std::sqrt(accelx*accelx + accely*accely + accelz*accelz)));


    euler_x_panel->setText(qstr(data_->getData<float>(T_EULER_X)));
    euler_y_panel->setText(qstr(data_->getData<float>(T_EULER_Y)));
    euler_z_panel->setText(qstr(data_->getData<float>(T_EULER_Z)));
    pressure_panel->setText(qstr(data_->getData<float>(T_PRESSURE)));
    speed_panel->setText(qstr(data_->getData<float>(T_SPEED)));
    temperature_panel->setText(qstr(data_->getData<float>(T_TEMPERATURE)));
}

void GuiWindow::refresh_gps()
{
    float altitude(data_->getData<float>(GPS_ALTITUDE));
    altitude_lcd_gps->display(qstr((int)altitude));
    altitude_lcd_gps_ft->display(qstr((int)(M_TO_FT * altitude)));

    float altitude_max(data_->getData<float>(ALTITUDE_MAX));
    altitude_max_lcd_m->display(qstr((int)altitude_max));
    altitude_max_lcd_ft->display(qstr((int)(altitude_max*M_TO_FT)));

    longitude_panel->setText(qstr(data_->getData<float>(GPS_LONGITUDE)));
    latitude_panel->setText(qstr(data_->getData<float>(GPS_LATITUDE)));
    hdop_panel->setText(qstr(data_->getData<float>(GPS_HDOP)));
    sat_nbr_panel->setText(qstr(data_->getData<uint8_t>(GPS_SAT_NBR)));
}

void GuiWindow::refresh_com()
{
    received_pack_cnt_panel->setText(qstr(data_->getData<uint64_t>(TOTAL_RX_PACKET_CTR)));
    packets_second_bar->setValue((data_->eatData<uint32_t>(PACKET_CTR_ALL, 0) * FREQUENCY));
    av_packets_second_bar->setValue((data_->eatData<uint32_t>(PACKET_CTR_AV, 0) * FREQUENCY));
    pl_packets_second_bar->setValue((data_->eatData<uint32_t>(PACKET_CTR_PL, 0) * FREQUENCY));
    gse_packets_second_bar->setValue((data_->eatData<uint32_t>(PACKET_CTR_GSE, 0) * FREQUENCY));
    corrupted_panel->setText(qstr(data_->getData<uint64_t>(CORRUPTED_PACKET_CTR)));
    rssi_panel->display(qstr(-1* (int) data_->getData<uint8_t>(ui_interface::RSSI_VALUE)));

    // Time since last received packet
    time_t t = difftime(std::time(nullptr), data_->getData<time_t>(ui_interface::TIME_SINCE_LAST_RX_PACKET));
    struct tm* tt = gmtime(&t);
    char buf[32];
    std::strftime(buf, 32, "%T", tt);
    time_since_last_panel->setText(buf);

    /*
    std::string str(DatagramType::getDatagramIDName(data_->getData<uint8_t>(ui_interface::LAST_DATAGRAM_ID)));
    received_pack_cnt_panel->setText(qstr(data_->getData<uint32_t>(RX_PACKET_CTR)));
    uint32_t packets(data_->eatData<uint32_t>(PACKET_RX_RATE_CTR, 0));
    packets_second_bar->setValue((packets * (1000.0 / (REFRESH_RATE))));

    corrupted_panel->setText(qstr(data_->getData<uint64_t>(CORRUPTED_PACKET_CTR)));
    */
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

void GuiWindow::show_dots(QLabel * label)
{
    label->setStyleSheet(QLatin1String("color: rgb(0, 255, 255);"));
    label->setText("...");
}
void GuiWindow::keyPressEvent(QKeyEvent * ckey)
{
    if (ckey->key() == Qt::Key_F11 || ckey->key() == Qt::Key_F) {
        fullscreen_ = !fullscreen_;
    }
    (fullscreen_) ? showFullScreen() : showNormal();
    std::string str("Fullscreen ");
    logger.log(new Gui_Message(str.append(fullscreen_? "ON" : "OFF")));
}

void GuiWindow::refresh_serial_status()
{
    auto serial_status = data_->getData<int>(ui_interface::SERIALPORT_STATUS);
    if(serial_status==0){
        show_dots(serial_status_panel);
    } else if(serial_status==1){
        show_ok(serial_status_panel);
    }else{
        show_X(serial_status_panel);
    }
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
