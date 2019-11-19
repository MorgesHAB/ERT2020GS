/*!
 * \file PacketType.cpp
 *
 * \brief PacketType module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019	
 */

#include <DataHandler.h>
#include "PacketType.h"

PacketType::PacketType(uint8_t type) : type(type) {}

void PacketType::write(Packet &packet) {
    packet.write(type);
}

void PacketType::parse(Packet &packet) {
    packet.parse(type);
}

void PacketType::update() {}

void PacketType::print() const {
    std::cout << "*** Packet Type : ";
    switch (type) {
        case GPSID: std::cout << "GPS";
            break;
        case PAYLOAD: std::cout << "Payload";
            break;
        case AVIONICS: std::cout << "Avionics";
            break;
        case PROPULSION: std::cout << "Propulsion";
            break;
        default: std::cout << "Unknown";
    }
    std::cout << std::endl;
}
