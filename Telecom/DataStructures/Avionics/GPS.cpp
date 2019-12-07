/*!
 * \file GPS.cpp
 *
 * \brief GPS module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019
 */

#include <iomanip>
#include "GPS.h"

GPS::GPS() : latitude(0), longitude(0), altitude(0), speed(0),
             time(std::time(nullptr))/*,
             gpsd("localhost", DEFAULT_GPSD_PORT) */{
    srand(std::time(nullptr)); // for simulation random

    /* if (gpsd.stream(WATCH_ENABLE|WATCH_JSON) == NULL) {
         std::cerr << "No GPSD running" << std::endl;
         exit(0);
     }*/
}

void GPS::write(Packet& packet) {
    packet.write(latitude);
    packet.write(longitude);
    packet.write(altitude);
    packet.write(speed);
    packet.write(time);
}


void GPS::parse(Packet& packet) {
    packet.parse(latitude);
    packet.parse(longitude);
    packet.parse(altitude);
    packet.parse(speed);
    packet.parse(time);
}

void GPS::print() const {
    std::cout << std::setprecision(10);
    std::cout << "----- GPS DATA --------------" << std::endl;
    std::cout << "latitude : " << latitude << std::endl
              << "longitude : " << longitude << std::endl
              << "altitude : " << altitude << std::endl
              << "speed : " << speed << std::endl
              << "time : " << std::asctime(std::localtime(&time)) << std::endl;
}

void GPS::updateTx(std::shared_ptr<Connector> connector) {
    /*  struct gps_data_t* newData;

      if (!gpsd.waiting(5000000)) return;

      if ((newData = gpsd.read()) == NULL) {
          std::cerr << "Read error" << std::endl;
      } else {
          if (newData->set & ALTITUDE_SET) altitude = newData->fix.altitude;
          if (newData->set & SPEED_SET) speed = newData->fix.speed;
          if (newData->set & TIME_SET) time = newData->fix.time;
          if (newData->set & LATLON_SET) {
              latitude = newData->fix.latitude;
              longitude = newData->fix.longitude;
          }
      }*/
    latitude =  42 + ((float) rand()/ RAND_MAX) * 6;
    longitude =  11 + ((float) rand()/ RAND_MAX) * 6;
    altitude =  500 + ((float) rand()/ RAND_MAX) * 1000;
    speed = ((float) rand()/ RAND_MAX) * 100;
    time = std::time(nullptr);
}

void GPS::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::LATITUDE, latitude);
    connector->setData(ui_interface::LONGITUDE, longitude);
    connector->setData(ui_interface::ALTITUDE, altitude);
    connector->setData(ui_interface::SPEED, speed);
    connector->setData(ui_interface::TIME, time);
}

