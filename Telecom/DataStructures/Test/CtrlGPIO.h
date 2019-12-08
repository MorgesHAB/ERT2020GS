/*!
 * \file CtrlGPIO.h
 *
 * \brief CtrlGPIO module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.12.2019	
 */

#ifndef CtrlGPIO_H
#define CtrlGPIO_H

#include <Data.h>

class CtrlGPIO : public Data {
public:
    CtrlGPIO(int pin);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    int pin;
    bool pinState;
};


#endif //CtrlGPIO_H
