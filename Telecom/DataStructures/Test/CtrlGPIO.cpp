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

CtrlGPIO::CtrlGPIO(int pin) : pin(pin), pinState(false) {
    wiringPiSetupGpio();
    pinMode(pin, OUTPUT);		// Configure GPIO pin as an output
}

void CtrlGPIO::write(Packet &packet) {
    packet.write(pinState);
}

void CtrlGPIO::parse(Packet &packet) {
    packet.parse(pinState);
}

void CtrlGPIO::print() const {
    std::cout << "GPIO : " << pin << " is currently at state : "
              << ((pinState) ? "HIGH" : "LOW") << std::endl;
}

void CtrlGPIO::updateTx(std::shared_ptr<Connector> connector) {
    pinState = connector->getData<bool>(ui_interface::IGNITION_CLICKED);
}

void CtrlGPIO::updateRx(std::shared_ptr<Connector> connector) {
    digitalWrite(pin, pinState);
}