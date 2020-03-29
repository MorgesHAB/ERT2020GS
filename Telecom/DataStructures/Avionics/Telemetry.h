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
    std::string log() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    struct Vector3D {
        float x, y, z;
    } accelerometer, euler;

    float temperature, pressure, speed, altitude;
};


#endif //Telemetry_H
