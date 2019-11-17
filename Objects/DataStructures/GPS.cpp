/*!
 * \file GPS.cpp
 *
 * \brief GPS module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019
 */
#include <iostream>
#include <iomanip>
#include "GPS.h"

GPS::GPS() : gpsd("localhost", DEFAULT_GPSD_PORT),
             gpsData{0, 0, 0, 0, std::time(nullptr)} {

    if (gpsd.stream(WATCH_ENABLE|WATCH_JSON) == NULL) {
        std::cerr << "No GPSD running" << std::endl;
        exit(0);
    }
}

void GPS::write(Packet& packet) {
    packet.write(gpsData.latitude);
    packet.write(gpsData.longitude);
    packet.write(gpsData.altitude);
    packet.write(gpsData.speed);
    packet.write(gpsData.time);
}


void GPS::parse(Packet& packet) {
    packet.parse(gpsData.latitude);
    packet.parse(gpsData.longitude);
    packet.parse(gpsData.altitude);
    packet.parse(gpsData.speed);
    packet.parse(gpsData.time);
}

void GPS::print() const {
    std::cout << std::setprecision(10);
    std::cout << "----- GPS DATA --------------" << std::endl;
    std::cout << "latitude : " << gpsData.latitude << std::endl
              << "longitude : " << gpsData.longitude << std::endl
              << "altitude : " << gpsData.altitude << std::endl
              << "speed : " << gpsData.speed << std::endl
              << "time : " << std::asctime(std::localtime(&gpsData.time)) << std::endl;
}

void GPS::update() {
    struct gps_data_t* newData;

    if (!gpsd.waiting(5000000)) return;

    if ((newData = gpsd.read()) == NULL) {
        std::cerr << "Read error" << std::endl;
    } else {
        if (newData->set & ALTITUDE_SET) gpsData.altitude = newData->fix.altitude;
        if (newData->set & SPEED_SET) gpsData.speed = newData->fix.speed;
        if (newData->set & TIME_SET) gpsData.time = newData->fix.time;
        if (newData->set & LATLON_SET) {
            gpsData.latitude = newData->fix.latitude;
            gpsData.longitude = newData->fix.longitude;
        }
    }
}

const GPS::GPSData &GPS::getGpsData() const {
    return gpsData;
}
