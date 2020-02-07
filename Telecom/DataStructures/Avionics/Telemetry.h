/*!
 * \file Telemetry.h
 *
 * \brief Telemetry module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.02.2020	
 */

#ifndef Telemetry_H
#define Telemetry_H

#include <Data.h>

class Telemetry : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    float accelerometer, euler, temperature, pressure, speed, altitude;
};


#endif //Telemetry_H
