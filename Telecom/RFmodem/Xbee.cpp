/*!
 * \file XBee.cpp
 *
 * \brief XBee module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#include <unistd.h>
#include "Xbee.h"

#define XBEE_SERIAL_PORT            "/dev/ttyS6"


Xbee::Xbee() : serialPort(XBEE_SERIAL_PORT, 115200) {}

void Xbee::send(Packet &packet) {
    if (serialPort.isOpen()) {
        serialPort.write(packet.getPacket(), packet.getSize());
        std::cout << "Packet have been sent" << std::endl;
    }
}

Xbee::~Xbee() {
    std::cout << "Closing radio receiver" << std::endl;
    serialPort.close();
}

void Xbee::mainRoutine(DataHandler &dataHandler) {
    while (true) { //TODO thread enable
        if (receive(dataHandler.getPacket(XBEE_TEST))) {
            dataHandler.parse(XBEE_TEST);
            dataHandler.print(XBEE_TEST);
        }
    }
}

bool Xbee::receive(Packet &packet) {
    try {
        if (serialPort.available()) {
            uint8_t info[3];
            serialPort.read(info, 3);
            uint16_t size((info[1] << 8)| info[2]);
            std::cout << "Size : " << size << std::endl;
            packet.restart();
            serialPort.read(packet.getPacket(), size + 1);
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

bool Xbee::receive(DataHandler &dataHandler) {
    try {
        if (serialPort.available()) {
            uint8_t info[3];
            serialPort.read(info, 3);
            uint16_t size(((info[1] << 8)| info[2]) + 1);
            std::cout << "Size : " << size << std::endl;
            Packet* packet = new Packet(size);
            serialPort.read(packet->getPacket(), size);
            dataHandler.setPacket(packet);
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