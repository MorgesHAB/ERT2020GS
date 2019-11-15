#include "gpswindow.h"
#include <iostream>
#include <QString>
#include <DataHandler.h>
#include <LoRa.h>
#include <DataHandler.h>
#include <PressureData.h>

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
    static bool first(true);
    if (first) {
        dataHandler.add(new PressureData);
        first = false;
    }

    if (loRa.receive(dataHandler.getDataPacket())) {
        std::cout << "LoRa last RSSI : " << loRa.getRSSI() << " dBm" << std::endl;
        dataHandler.parse();
        dataHandler.print();
        this->altitude_lcd->display(dynamic_cast<PressureData>(dataHandler.getDataHandler()[0]).getPressure());
        //this->speed_lcd->display(GET_SPEED);
        //this->latitude_panel->setText(QString::number(GET_LATITUDE) + "<sup>o</sup>");
        //this->longitude_panel->setText(QString::number(GET_LONGITUDE) + "<sup>o</sup>");
        this->rssi_panel->setText(QString::number(loRa.getRSSI()) + " dBm");
    }
}
