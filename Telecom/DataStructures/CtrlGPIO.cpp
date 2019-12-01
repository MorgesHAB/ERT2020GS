/*!
 * \file CtrlGPIO.cpp
 *
 * \brief CtrlGPIO module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.12.2019	
 */

#include <wiringPi.h>
#include "CtrlGPIO.h"

CtrlGPIO::CtrlGPIO(int pin) : pin(pin) {
    wiringPiSetupGpio();
    pinMode(pin, OUTPUT);		// Configure GPIO0 as an output
}

void CtrlGPIO::write(Packet &packet) {

}

void CtrlGPIO::parse(Packet &packet) {
    digitalWrite(pin, HIGH);
}

void CtrlGPIO::update() {

}

void CtrlGPIO::print() const {
    std::cout << "GPIO : " << " is currently at state : "
              << (digitalRead(pin) ? "HIGH" : "LOW") << std::endl;
}
