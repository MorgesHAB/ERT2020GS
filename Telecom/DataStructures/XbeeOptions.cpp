/*!
 * \file XbeeOptions.cpp
 *
 * \brief XbeeOptions module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        29.11.2019	
 */

#include "XbeeOptions.h"

void XbeeOptions::write(Packet &packet) {
    for (uint8_t& part : msg) packet.write(part);
}

void XbeeOptions::parse(Packet &packet) {
    for (uint8_t& part : msg) packet.parse(part);
}

void XbeeOptions::update() {

}

void XbeeOptions::print() const {
    for (uint8_t part : msg) std::cout << +part << std::endl;
    std::cout << std::endl;
}
