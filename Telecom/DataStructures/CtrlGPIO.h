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
    void update() override;
    void print() const override;

private:
    int pin;
};


#endif //CtrlGPIO_H
