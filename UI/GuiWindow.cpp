#include "GuiWindow.h"
#include <iostream>
#include <ctime>
#include <QString>
#include <QMessageBox>
#include <QPixmap>

constexpr uint8_t THEME_NUMBER(3);

using namespace ui_interface;

inline QString degree_representation(double value){
    return QString::number(value)  + "<sup>o</sup>";
}

inline QString qstr(double value){
    return QString::number(value);
}
inline QString qstr(uint64_t value){
    return QString::number(value);
}




GuiWindow::GuiWindow(int refresh_rate, std::shared_ptr<Connector> connector) :
        timer_(new QTimer(this)),
        data_(connector),
        white_theme_(0){
    Ui_Form::setupUi(this);
    connect(timer_, SIGNAL (timeout()), this, SLOT (refresh_data()));
    connect(xbee_button, SIGNAL (pressed()), this, SLOT (xbee_clicked()));
    connect(stop_xbee, SIGNAL (pressed()), this, SLOT (xbee_stop_clicked()));
    connect(ignition_button, SIGNAL (pressed()), this, SLOT (ignite_clicked()));
    connect(change_theme, SIGNAL (pressed()), this, SLOT (theme_change_clicked()));
    timer_->start(refresh_rate);
}
//TODO This function is very bad structured, must fix
void GuiWindow::refresh_data() {
    //std::cout << "Data stored reads : " << data_->getData<float>(ui_interface::PRESSURE_DATA) <<std::endl;
    float tmp(data_->getData<float>(LATITUDE));
    latitude_panel->setText(degree_representation(tmp));
    tmp = data_->getData<float>(LONGITUDE);
    longitude_panel->setText(degree_representation(tmp));
    tmp = data_->getData<float>(ALTITUDE);
    this->altitude_lcd->display(tmp);
    this->last_packet_number_panel->setText(qstr(data_->getData<uint64_t>(PACKET_NBR)));
    this->speed_lcd->display(data_->getData<float>(SPEED));
    time_t timestamp(data_->getData<time_t>(TIMESTAMP));
    char tbuffer[16];
    struct tm* tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 16, "%T", tptr);
    this->last_refresh_panel->setText(tbuffer);
    this->rssi_panel->setText("NOT YET IMPLEMENTED");
    uint64_t packets(data_->eatData<uint64_t>(PACKET_RX_COUNTER, 0));
    packets_second_bar->setValue((int)(packets*(1000.0/(timer_->interval()))));
    std::cout << "interval : " << timer_->interval() << std::endl;
}

void GuiWindow::xbee_clicked() {
    std::cout << "XBee ON button clicked!" << std::endl;
    data_->setData(ui_interface::ACTIVE_XBEE, true);
}

void GuiWindow::xbee_stop_clicked() {
    std::cout << "XBee STOP button clicked!" << std::endl;
    data_->setData(ui_interface::ACTIVE_XBEE, false);
}

void GuiWindow::ignite_clicked() {
    std::cout << "Ignition button clicked!" << std::endl;
    data_->setData(ui_interface::IGNITION_CLICKED, true);
}

void GuiWindow::theme_change_clicked()
{
    if(white_theme_%THEME_NUMBER == 0){
        setStyleSheet(QLatin1String("background-color: rgb(10, 10, 10);\n"
        "color: rgb(0, 255, 0);"));
        this->packets_second_bar->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);"));
    }else if(white_theme_%THEME_NUMBER == 1){
        setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
        "color: rgb(0, 0, 0);"));
    }else if(white_theme_%THEME_NUMBER == 2){
        setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
        "color: rgb(255, 255, 255);"));
    }
    ++white_theme_;
}

void GuiWindow::closeEvent (QCloseEvent *event)
{
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "BELLA LUI 2020",
                                                                    tr("Ending mission Bella Lui 2020.\nAre you sure?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            event->accept();
            data_->setData(ui_interface::RUNNING, false);
		std::cout << "running set to false" << std::endl;
        }
}

