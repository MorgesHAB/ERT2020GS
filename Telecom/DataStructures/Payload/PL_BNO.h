/*!
 * \file PL_BNO.h
 *
 * \brief PL_BNO module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.07.2020	
 */

#ifndef PL_BNO_H
#define PL_BNO_H


#include <Data.h>

class PL_BNO : public Data {
public:
    void write(Packet &packet) override;

    void parse(Packet &packet) override;

    void print() const override;

    std::string log() const override;

    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t temperature;
    float orientationX, orientationY, orientationZ,
          accelerationX, accelerationY, accelerationZ;
};


#endif //PL_BNO_H
