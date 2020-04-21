/*!
 * \file XBee.cpp
 *
 * \brief XBee module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#include "Xbee.h"
#include <DatagramTypes.h>


Xbee::Xbee(std::string port) {
    try {
        serialPort.setBaudrate(115200);
        serialPort.setPort(port);
        serialPort.open();
        if (serialPort.isOpen())
            std::cout << "Xbee initialise correctly now - serial port ok" << std::endl;
    } catch (const serial::IOException &e) {
        std::cerr << "Serial port error : IOException" << std::endl;
    }
}

void Xbee::send(Packet *packet) {
    if (serialPort.isOpen()) {
        serialPort.write(packet->getPacket(), packet->getSize());
        std::cout << DatagramType::getDatagramIDName(packet->getPacket()[17])
                  << " Packet have been sent  size: " << +packet->getSize()
                  << std::endl;
    }
}

Xbee::~Xbee() {
    std::cout << "Closing radio receiver" << std::endl;
    serialPort.close();
}

bool Xbee::receive(DataHandler &dataHandler) {
    try {
        if (serialPort.available()) {
            uint8_t info[3];
            serialPort.read(info, 3);
            // length of the packet is stored at a specific position in Xbee protocol
            uint16_t length(((info[1] << 8)| info[2]) + 1); // + 1 is CRC
            Packet* packet = new Packet(length);
            serialPort.read(packet->getPacket(), length);
            return dataHandler.updateRx(packet);
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

// Old version
bool Xbee::receive(Packet *packet) {
    try {
        if (serialPort.available()) {
            uint8_t info[3];
            serialPort.read(info, 3);
            uint16_t size((info[1] << 8)| info[2]);
            packet->restart();
            serialPort.read(packet->getPacket(), size + 1);
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


int Xbee::getRSSI() {
    /* AT Command (API 1)
    Start delimiter: 7E
    Length: 00 04 (4)
    Frame type: 08 (AT Command)
    Frame ID: 01 (1)
    AT Command: 44 42 (DB)
    Checksum: 70 */
    uint8_t command[] = {0x7E, 0x00, 0x04, 0x08, 0x01, 0x44, 0x42, 0x70};
    if (serialPort.isOpen()) {
        serialPort.write(command, sizeof(command));
        std::cout << "Diagnostic command have been sent - get RSSI" << std::endl;
    }
    return 0;   // value will be in a xbee packet at reception (updateRx)
}

bool Xbee::isOpen() {
    return serialPort.isOpen();
}
