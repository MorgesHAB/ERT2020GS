#include "gpswindow.h"
#include <iostream>
#include <QString>
#include <LoRa.h>
#include <DataHandler.h>

GPSWindow::GPSWindow(uint32_t refresh_rate) : timer_(new QTimer(this))
{
    Ui_Form::setupUi(this);
    connect(timer_, SIGNAL (timeout()), this , SLOT (push_data()));
    timer_->start(refresh_rate);
}

void GPSWindow::push_data(){
    /**
    * 1- Include the header containing data getter methods.
    * 2- Change GET_ALTITUDE, GET_SPEED, etc. with corresponding getter methods.
    * 3- Uncomment the instructions run the QTApplication instance on main and have fun :)
    * 
    */
    static LoRa loRa;
    static DataHandler dataHandler;

    if (loRa.receive(dataHandler.getPacket(GPS))) {
        std::cout << "LoRa last RSSI : " << loRa.getRSSI() << " dBm" << std::endl;
        dataHandler.parse(GPS);
        dataHandler.print(GPS);
        GPS* gps(dynamic_cast<GPS*>(dataHandler.getPacket(GPS)[0]));
        this->altitude_lcd->display(gps->getGpsData().altitude);
        this->speed_lcd->display(gps->getGpsData().speed);
        this->latitude_panel->setText(QString::number(gps->getGpsData().latitude) + "<sup>o</sup>");
        this->longitude_panel->setText(QString::number(gps->getGpsData().longitude) + "<sup>o</sup>");
        this->rssi_panel->setText(QString::number(loRa.getRSSI()) + " dBm");
    }
}
