/*!
 * \file Controller.cpp
 *
 * \brief Packet module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019
 */

#include "Packet.h"


Packet::Packet(size_t packetSize) : packet(new uint8_t[packetSize]),
                                    packetPosition(packet), packetSize(packetSize) {}

Packet::~Packet() {
    delete[] packet;
}

void Packet::restart() {
    delete[] packet;
    packet = new uint8_t[packetSize];
    packetPosition = packet;
}

void Packet::write(std::string& msg)  {
    write(uint8_t (msg.size()));
    for (auto& character : msg) write(character);
}

void Packet::parse(std::string& msg)  {
    msg.clear();
    uint8_t stringSize(0);
    parse(stringSize);
    for (int i(0); i < stringSize; ++i) {
        char c;
        parse(c);
        msg += c;
    }
}

uint8_t *Packet::getPacket() {
    return packet;
}

uint8_t Packet::getSize() const {
    return packetPosition - packet;
}

void Packet::printDebug() const {
    std::cout << "Print packet Debug byte per byte :" << std::endl;
    for (uint8_t i(0); i < packetSize; ++i) std::cout << +packet[i] << " ";
    std::cout << std::endl;
}