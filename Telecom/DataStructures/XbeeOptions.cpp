/*!
 * \file XbeeOptions.cpp
 *
 * \brief XbeeOptions module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        29.11.2019	
 */

#include "XbeeOptions.h"

XbeeOptions::XbeeOptions() : msg{0x7E, 0x00, 0x1B, 0x10, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
                                 0xFE, 0x00, 0x43, 0x55, 0x55, 0x55, 0x55, 0x14, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x14, 0x35} {}


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