/*!
 * \file PL_BME.h
 *
 * \brief PL_BME module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.07.2020	
 */

#ifndef PL_BME_H
#define PL_BME_H


#include <Data.h>

class PL_BME : public Data {
public:
    void write(Packet &packet) override;

    void parse(Packet &packet) override;

    void print() const override;

    std::string log() const override;

    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    float temperature, pressure, humidity, altitude;
};


#endif //PL_BME_H
