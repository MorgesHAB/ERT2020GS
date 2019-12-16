/*!
 * \file GuiWindow.h
 *
 * \brief Gui Window module implementation
 *
 * \author      KESKE CEM - EPFL EL BA3
 * \date        02.12.2019
 */

#include "GuiWindow.h"
#include <chrono>
#include <iostream>
#include <ctime>
#include <QStyleFactory>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QCoreApplication>
#include <array>

constexpr uint8_t THEME_NUMBER(3);


using namespace ui_interface;

inline QString degree_representation(double value)
{
    return QString::number(value) + "<sup>o</sup>";
}

inline QString qstr(double value)
{
    return QString::number(value);
}

inline QString qstr(uint8_t value)
{
    return QString::number(value);
}

inline QString qstr(uint16_t value)
{
    return QString::number(value);
}

inline QString qstr(uint32_t value)
{
    return QString::number(value);
}

inline QString qstr(uint64_t value)
{
    return QString::number(value);
}

inline bool get_bit(unsigned char byte, int position) // position in range 0-7
{
    return (byte >> position) & 0x1;
}

GuiWindow::GuiWindow(int refresh_rate, std::shared_ptr<Connector> connector) :
    timer_(new QTimer(this)),
    data_(connector),
    missed_count_(0),
    white_theme_(0),
    current_theme_(0),
    ready_ignition_(false),
    xbee_acvite_(false)
{
    initialize_style();
    initialize_slots_signals();
    timer_->start(refresh_rate);

}

void GuiWindow::refresh_data()
{
    refresh_com();
    refresh_telemetry();
    refresh_time();
    check_and_show();
    refresh_ignition_frame();
    ++tick_counter_;
}

void GuiWindow::xbee_clicked()
{
    if (!xbee_acvite_) {
        std::cout << "XBee ON button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, true);
        xbee_button->setText("STOP XBee");
    } else {
        std::cout << "XBee STOP button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, false);
        xbee_button->setText("START XBee");
    }
    xbee_acvite_ = !xbee_acvite_;
}

void GuiWindow::ignite_clicked()
{
    std::cout << "Ignition button clicked!" << std::endl;

    ready_ignition_ = !ready_ignition_;
    data_->setData(ui_interface::IGNITION_CLICKED, ready_ignition_);
    show_ok_X(ready_ignition_panel, ready_ignition_);


}

void GuiWindow::theme_change_clicked()
{
    if(current_theme_ == BLACK_ON_WHITE)
        current_theme_ = start;


    current_theme_ = (Theme)((int)current_theme_+1);



    if (current_theme_ == GREEN_ON_BLACK) {
        setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
          "color: rgb(0, 255, 0);"));
        packets_second_bar->setStyleSheet(
            QLatin1String("color: rgb(255, 255, 255);"));
    } else if (current_theme_ == WHITE_ON_BLACK) {
        setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
          "color: rgb(0, 0, 0);"));
        packets_second_bar->setStyleSheet(QLatin1String("color: rgb(0,0,0);"));
    } else if (current_theme_ == BLACK_ON_WHITE) {
        setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
          "color: rgb(255, 255, 255);"));
        packets_second_bar->setStyleSheet(
            QLatin1String("color: rgb(255, 255, 255);"));
    }
}

uint16_t GuiWindow::calculate_misses_in_last_2()
{
    static std::array<uint32_t, 4> before{ 0 };

    uint64_t current(tick_counter_ % 4);
    uint64_t tmp(missed_count_ - before[current]);

    before[current] = missed_count_;
    return tmp;
}

void GuiWindow::closeEvent(QCloseEvent * event)
{
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

void GuiWindow::refresh_misses()
{
    missed_count_ = data_->getData<uint32_t>(TX_PACKET_NR)
      - data_->getData<uint32_t>(RX_PACKET_CTR);
}

void GuiWindow::refresh_ignition_code()
{
    uint8_t tmp(data_->getData<uint8_t>(ui_interface::TX_IGNITION_CODE));

    code_0->setText(QString::number(get_bit(tmp, 0)));
    code_1->setText(QString::number(get_bit(tmp, 1)));
    code_2->setText(QString::number(get_bit(tmp, 2)));
    code_3->setText(QString::number(get_bit(tmp, 3)));
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
    show_ok_X(key_1_panel, data_->getData<bool>(IGNITION_KEY_1_ACTIVATED));
    show_ok_X(key_2_panel, data_->getData<bool>(IGNITION_KEY_2_ACTIVATED));
    show_ok_X(red_button_panel, data_->getData<bool>(IGNITION_RED_BUTTON_PUSHED));
}

void GuiWindow::initialize_slots_signals()
{
    connect(timer_, SIGNAL(timeout()), this, SLOT(refresh_data()));
    connect(xbee_button, SIGNAL(pressed()), this, SLOT(xbee_clicked()));
    connect(ignition_button, SIGNAL(pressed()), this, SLOT(ignite_clicked()));
    connect(change_theme, SIGNAL(pressed()), this, SLOT(theme_change_clicked()));
}

void GuiWindow::refresh_telemetry()
{
    float tmp(data_->getData<float>(LATITUDE));

    latitude_panel->setText(degree_representation(tmp));
    tmp = data_->getData<float>(LONGITUDE);
    longitude_panel->setText(degree_representation(tmp));
    tmp = data_->getData<float>(ALTITUDE);
    this->altitude_lcd->display(tmp);
}

void GuiWindow::refresh_com()
{
    refresh_misses();
    this->last_packet_number_panel->setText(
            qstr(data_->getData<uint32_t>(TX_PACKET_NR)));
    received_pack_cnt_panel->setText(qstr(data_->getData<uint32_t>(RX_PACKET_CTR)));
    this->speed_lcd->display(data_->getData<float>(SPEED));
    time_t timestamp(data_->getData<time_t>(TIMESTAMP));
    char tbuffer[32];
    struct tm *tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 32, "%T", tptr);
    miss_panel->setText(qstr(calculate_misses_in_last_2()));
    this->last_refresh_panel->setText(tbuffer);
    this->rssi_panel->setText("NOT YET IMPLEMENTED");
    uint32_t packets(data_->eatData<uint32_t>(PACKET_RX_RATE_CTR, 0));
    packets_second_bar->setValue((int) (packets * (1000.0 / (timer_->interval()))));
}

void GuiWindow::check_and_show()
{
    if (data_->eatData<bool>(IGNITION_STATUS, false)) {
        QMessageBox::warning(this, "Ignition", "BOOM!");
    }
}

void GuiWindow::refresh_time()
{
    time_t timestamp(std::time(nullptr));
    char tbuffer[32];
    struct tm * tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 32, "%H:%M:%S", tptr);
    time_panel->setText(tbuffer);
}

void GuiWindow::show_ok_X(QLabel * label, bool ok)
{
    if(ok)
        show_ok(label);
    else
        show_X(label);
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

