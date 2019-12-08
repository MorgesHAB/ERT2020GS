/*!
 * \file States.cpp
 *
 * \brief States module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019	

 */

#include "States.h"

States::States(const std::vector<bool> &states) : states(states) {}

void States::write(Packet &packet) {
    uint8_t statePacket(0);
    for (uint8_t i(0); i < states.size(); ++i) {
        statePacket |= states[i] << i;
    }
    packet.write(statePacket);
}

void States::parse(Packet &packet) {
    uint8_t statePacket(0);
    packet.parse(statePacket);
    for (uint8_t i(0); i < states.size(); ++i) {
        states[i] = statePacket & (1 << i);
    }
}

void States::print() const {
    std::cout << "States vector : [ ";
    for (uint8_t i(0); i < states.size() - 1; ++i) std::cout << states[i] << " , ";
    std::cout << states.back() << " ] " << std::endl;
}
