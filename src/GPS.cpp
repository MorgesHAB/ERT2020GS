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

GPS::GPS() : latitude(0), longitude(0), altitude(0),speed(0), time("NO TIME"),
             gps_rec("localhost", DEFAULT_GPSD_PORT) {

    if (gps_rec.stream(WATCH_ENABLE|WATCH_JSON) == NULL) {
        std::cerr << "No GPSD running" << std::endl;
        exit(0);
    }
}

GPS::GPS(float latitude, float longitude, float altitude, float speed,
         const std::string& time) : latitude(latitude), longitude(longitude),
                                    altitude(altitude), speed(speed), time(time) {}

void GPS::write(Packet &packet) {
    packet.write(latitude);
    packet.write(longitude);
    packet.write(altitude);
    packet.write(speed);
    packet.write(time);
}


void GPS::parse(Packet &packet) {
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
              << "time : " << time << std::endl;
}

bool GPS::readData() {

    struct gps_data_t* newData;

    if (!gps_rec.waiting(5000000)) return false;

    if ((newData = gps_rec.read()) == NULL) {
        std::cerr << "Read error" << std::endl;
        exit(0);
    } else {
        if (newData->set & ALTITUDE_SET) {
            std::cout << "Altitude : " << newData->fix.altitude << std::endl;
            altitude = newData->fix.altitude;
        }
        if (newData->set & LATLON_SET) {
            std::cout << "Lat / Lon : " << newData->fix.latitude << " / " << newData->fix.longitude << std::endl;
            latitude = newData->fix.latitude;
            longitude = newData->fix.longitude;
        }
        if (newData->set & SPEED_SET) {
            std::cout << "Speed : " << newData->fix.speed << std::endl;
            speed = newData->fix.speed;
        }
        if (newData->set & TIME_SET) {
            std::cout << "Time : " << newData->fix.time << std::endl;
            time = newData->fix.time;
        }
        return true;
    }
}
