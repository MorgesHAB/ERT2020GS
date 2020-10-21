/*!
 * \file IgnitionCode.h
 *
 * \brief IgnitionCode module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.12.2019	
 */

// DATA INFO :  PROPULSION TEST mid-December 2019
// if the code is identical on the TX & Rx side the igniter is activated

#ifndef IgnitionCode_H
#define IgnitionCode_H

#include <array>
#include <Data.h>
#include "IgnitionStates.h"

class IgnitionCode : public Data {
public:
    IgnitionCode();

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    std::array<bool,4> code;
    uint8_t ignitionCode, order, gseCode;
};


#endif //IgnitionCode_H
