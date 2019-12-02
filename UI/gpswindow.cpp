#include "gpswindow.h"
#include <iostream>
#include <QString>

GPSWindow::GPSWindow(int refresh_rate, std::shared_ptr<Connector> connector) :
    timer_(new QTimer(this)),
    data_(connector)
{
    Ui_Form::setupUi(this);
    connect(timer_, SIGNAL (timeout()), this , SLOT (push_data()));
    timer_->start(refresh_rate);
}

void GPSWindow::update() {
    this->push_data();
    this->QWidget::update();
}

void GPSWindow::push_data() {    
        this->altitude_lcd->display(QString::number(data_->get_data<uint64_t>(ui_interface::PRESSURE_DATA)));
        this->speed_lcd->display(0);
        this->latitude_panel->setText(QString::number(0) + "<sup>o</sup>");
        this->longitude_panel->setText(QString::number(0) + "<sup>o</sup>");
        this->rssi_panel->setText(QString::number(0) + " dBm");
    }

