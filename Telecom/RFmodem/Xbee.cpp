/*!
 * \file XBee.cpp
 *
 * \brief XBee module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#include "Xbee.h"

void Xbee::send() {
    if (serialPort.isOpen()) {
        uint8_t tab[] = "Hello";
        serialPort.write(tab, 5);
        std::cout << "Packet have been sent" << std::endl;
    }
}

bool Xbee::receive() {
    try {
        if (serialPort.available()) {
            std::cout << "Byte available !! '" << serialPort.read(5) << "'" << std::endl;
            return true;
        }
    } catch (const serial::IOException &e) {
        std::cerr << "IOException while reading serial port " << std::endl;
        return false;
    } catch (const serial::SerialException &e) {
        std::cerr << "SerialException while reading serial port" << std::endl;
        return false;
    }
}

Xbee::~Xbee() {
    std::cout << "Closing radio receiver" << std::endl;
    serialPort.close();
}

Xbee::Xbee() : serialPort("/dev/ttyUSB0", 115200) {}
