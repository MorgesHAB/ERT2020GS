/*!
 * \file XBee.cpp
 *
 * \brief XBee module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#include "Xbee.h"

#define XBEE_PACKET_MAX_SIZE       256


void Xbee::send(Packet &packet) {
    if (serialPort.isOpen()) {
        serialPort.write(packet.getPacket(), packet.getSize());
        std::cout << "Packet have been sent" << std::endl;
    }
}

bool Xbee::receive(Packet &packet) {
    try {
        if (serialPort.available()) {
            packet.restart();
            serialPort.read(packet.getPacket(), XBEE_PACKET_MAX_SIZE);
            std::cout << "\n\nPacket Received" << std::endl;
            return true;
        }
    } catch (const serial::IOException &e) {
        std::cerr << "IOException while reading serial port " << std::endl;
        return false;
    } catch (const serial::SerialException &e) {
        std::cerr << "SerialException while reading serial port" << std::endl;
        return false;
    }
    return false;
}

Xbee::~Xbee() {
    std::cout << "Closing radio receiver" << std::endl;
    serialPort.close();
}

Xbee::Xbee() : serialPort("/dev/ttyUSB0", 115200) {}
