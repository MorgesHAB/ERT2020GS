/*!
 * \file GPS.cpp
 *
 * \brief GPS module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019
 */

#include <iomanip>
#include <Loggable.h>
#include "GPS.h"
#include "../../../Logger/Loggable.h"

GPS::GPS() /*,
             gpsd("localhost", DEFAULT_GPSD_PORT) */{
    srand(std::time(nullptr)); // for simulation random

    /* if (gpsd.stream(WATCH_ENABLE|WATCH_JSON) == NULL) {
         std::cerr << "No GPSD running" << std::endl;
         exit(0);
     }*/
}

void GPS::write(Packet& packet) {
    packet.write(satelliteNbr);
    packet.write(hdop);
    packet.write(latitude);
    packet.write(longitude);
    packet.write(altitude);
}


void GPS::parse(Packet& packet) {
    packet.parse(satelliteNbr);
    packet.parse(hdop);
    packet.parse(latitude);
    packet.parse(longitude);
    packet.parse(altitude);
}

void GPS::print() const {
    std::cout << std::setprecision(10);
    std::cout << "----- GPS DATA --------------" << std::endl;
    std::cout << "latitude : " << latitude << "°" << std::endl
              << "longitude : " << longitude << "°" << std::endl
              << "altitude : " << altitude << " m" << std::endl
              << "Satellite Nbr : " << satelliteNbr << std::endl
              << "hdop : " << hdop << std::endl;
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
    satelliteNbr = rand() % 10;
    hdop =  100 + ((float) rand()/ RAND_MAX) * 100;
}

void GPS::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::GPS_ALTITUDE, latitude);
    connector->setData(ui_interface::GPS_LONGITUDE, longitude);
    connector->setData(ui_interface::GPS_ALTITUDE, altitude);
    connector->setData(ui_interface::GPS_HDOP, hdop);
    connector->setData(ui_interface::GPS_SAT_NBR, satelliteNbr);
    if (altitude > connector->getData<float>(ui_interface::ALTITUDE_MAX))
        connector->setData(ui_interface::ALTITUDE_MAX, altitude);
}

std::string GPS::log() const {
    return std::move( "GPS" + SEPARATOR +
            std::to_string(latitude) + SEPARATOR +
            std::to_string(longitude) + SEPARATOR +
            std::to_string(altitude) + SEPARATOR +
            std::to_string(hdop) + SEPARATOR +
            std::to_string(satelliteNbr) + SEPARATOR );
}
