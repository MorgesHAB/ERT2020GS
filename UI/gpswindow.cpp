#include "gpswindow.h"
#include <iostream>
#include <QString>
#include <GPS.h>

GPSWindow::GPSWindow(uint32_t refresh_rate) : timer_(new QTimer(this))
{
    Ui_Form::setupUi(this);
    connect(timer_, SIGNAL (timeout()), this , SLOT (push_data()));
    timer_->start(refresh_rate);
}

void update() {
    this->push_data();
    this->QWidget::update();
}

void GPSWindow::push_data() {

    if (loRa.receive(dataHandler.getPacket(GPSID))) {
        std::cout << "LoRa last RSSI : " << loRa.getRSSI() << " dBm" << std::endl;
        dataHandler.parse(GPSID);
        dataHandler.print(GPSID);
        // Test V.0 - Dirty
        GPS* gps(dynamic_cast<GPS*>(dataHandler.getDatagram(GPSID)[1]));
        this->altitude_lcd->display(gps->getGpsData().altitude);
        this->speed_lcd->display(gps->getGpsData().speed);
        this->latitude_panel->setText(QString::number(gps->getGpsData().latitude) + "<sup>o</sup>");
        this->longitude_panel->setText(QString::number(gps->getGpsData().longitude) + "<sup>o</sup>");
        this->rssi_panel->setText(QString::number(loRa.getRSSI()) + " dBm");
    }
}
