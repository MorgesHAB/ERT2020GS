/*!
 * \file IgnitionCode.cpp
 *
 * \brief IgnitionCode module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.12.2019	
 */

#include <wiringPi.h>
#include "IgnitionCode.h"


IgnitionCode::IgnitionCode(int gpio1, int gpio2, int gpio3, int gpio4)
        : gpio1(gpio1), gpio2(gpio2), gpio3(gpio3), gpio4(gpio4) {
    wiringPiSetupGpio();
    // Configure GPIO pins as an input
    pinMode(gpio1, INPUT);
    pinMode(gpio2, INPUT);
    pinMode(gpio3, INPUT);
    pinMode(gpio4, INPUT);
}

void IgnitionCode::write(Packet &packet) {
    uint8_t statePacket(0);
    for (uint8_t i(0); i < states.size(); ++i) {
        statePacket |= states[i] << i;
    }
    packet.write(statePacket);
}

void IgnitionCode::parse(Packet &packet) {
    uint8_t statePacket(0);
    packet.parse(statePacket);
    for (uint8_t i(0); i < states.size(); ++i) {
        states[i] = statePacket & (1 << i);
    }
}

void IgnitionCode::print() const {
    std::cout << "States vector : [ ";
    for (uint8_t i(0); i < states.size() - 1; ++i) std::cout << states[i] << " , ";
    std::cout << states.back() << " ] " << std::endl;

    std::cout << "=> Ignition code : [ " << states[0] << " " << states[1] << " "
              << states[2] << " " << states[3] << " ]" << std::endl;
}

void IgnitionCode::updateTx(std::shared_ptr<Connector> connector) {
    states[0] = digitalRead(gpio1);
    states[1] = digitalRead(gpio2);
    states[2] = digitalRead(gpio3);
    states[3] = digitalRead(gpio4);
}

void IgnitionCode::updateRx(std::shared_ptr<Connector> connector) {
    std::vector<int> codeRx = {digitalRead(gpio1), digitalRead(gpio2),
                               digitalRead(gpio3), digitalRead(gpio4)};

    std::cout << "Code read on the Rx RPi" << std::endl;
    std::cout << "=> Ignition code Rx: [ " << codeRx[0] << " " << codeRx[1] << " "
              << codeRx[2] << " " << codeRx[3] << " ]" << std::endl;

    if (codeRx[0] == states[0] && codeRx[1] == states[1] && codeRx[2] == states[2] &&
        codeRx[3] == states[3]) {
        std::cout << "Code are identical => GPIO ignition HIGH !!" << std::endl;
    } else {
        std::cout << "Code aren't identical : ignition aborted" << std::endl;
    }
}
