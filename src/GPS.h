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
#include <ctime>
#include <libgpsmm.h>
#include "Packet.h"

class GPS {
public:
    GPS();
    GPS(float latitude, float longitude, float altitude, float speed, std::time_t);
    void print() const;

    bool readData();

    void write(Packet &packet);
    void parse(Packet &packet);

private:
    gpsmm gpsd;

    float latitude;
    float longitude;
    float altitude;
    float speed;
    std::time_t time;
};


#endif //GPS_H
