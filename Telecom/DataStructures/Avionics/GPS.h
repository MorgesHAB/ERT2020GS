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

#include <ctime>
#include <Data.h>


class GPS : public Data {
public:
    GPS();
    void write(Packet& packet) override;
    void parse(Packet& packet) override;

    void print() const override;
    std::string log() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t satelliteNbr;
    float hdop;
    float latitude, longitude, altitude;
};


#endif //GPS_H
