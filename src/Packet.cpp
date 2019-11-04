/*!
 * \file Controller.cpp
 *
 * \brief Packet module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019
 */

#include "Packet.h"


Packet::Packet() : packet(new uint8_t[PACKET_SIZE]), packetPosition(packet) {}

Packet::~Packet() {
    delete[] packet;
}

void Packet::startParsing() {
    packetPosition = packet;
}

void Packet::write(std::string& msg)  {
    write(uint8_t (msg.size()));
    for (auto& character : msg) write(character);
}

void Packet::parse(std::string& msg)  {
    uint8_t size(0);
    parse(size);
    for (int i(0); i < size; ++i) {
        char c;
        parse(c);
        msg += c;
    }
}

uint8_t *Packet::getPacket() const {
    return packet;
}

uint8_t Packet::getSize() const {
    return packetPosition - packet;
}