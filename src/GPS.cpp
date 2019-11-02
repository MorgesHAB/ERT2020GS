/*!
 * \file GPS.cpp

 * \brief GPS module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019
 */
#include "GPS.h"

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
    std::cout << "----- GPS DATA --------------" << std::endl;
    std::cout << "latitude : " << latitude << std::endl
              << "longitude : " << longitude << std::endl
              << "altitude : " << altitude << std::endl
              << "speed : " << speed << std::endl
              << "time : " << time << std::endl;
}

GPS::GPS() : latitude(0), longitude(0), altitude(0),speed(0), time("") {}
