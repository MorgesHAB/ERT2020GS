/*!
 * \file GPS.h
 *
 * \brief GPS module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019	
 */

#ifndef GPS_H
#define GPS_H


#include <string>
#include "Packet.h"

class GPS {
public:
    GPS();
    GPS(float latitude, float longitude, float altitude, float speed,
        const std::string &time);
    void print() const;

    void write(Packet &packet);
    void parse(Packet &packet);

private:
    float latitude;
    float longitude;
    float altitude;
    float speed;
    std::string time;
};


#endif //GPS_H
