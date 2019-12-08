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

#include <vector>
#include <Data.h>

class IgnitionCode : public Data {
public:
    IgnitionCode();

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    std::vector<bool> states;
};


#endif //IgnitionCode_H
