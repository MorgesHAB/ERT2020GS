/*!
 * \file XBee.cpp
 *
 * \brief XBee module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#include "Xbee.h"

#define XBEE_SERIAL_PORT            "/dev/ttyS6"


Xbee::Xbee(std::string port) : serialPort(port, 115200) {}

void Xbee::initSerialPort(std::string port) {
    serialPort.setPort(port);
    serialPort.setBaudrate(115200);
}

void Xbee::send(Packet *packet) {
    if (serialPort.isOpen()) {
        serialPort.write(packet->getPacket(), packet->getSize());
        std::cout << "Packet have been sent" << std::endl;
    }
}

Xbee::~Xbee() {
    std::cout << "Closing radio receiver" << std::endl;
    serialPort.close();
}

bool Xbee::receive(Packet *packet) {
    try {
        if (serialPort.available()) {
            uint8_t info[3];
            serialPort.read(info, 3);
            uint16_t size((info[1] << 8)| info[2]);
            std::cout << "Size : " << size << std::endl;
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

bool Xbee::receive(DataHandler &dataHandler) {
    try {
        //std::cout << "byte avail " << serialPort.available() << std::endl;
        if (serialPort.available()) {
            /*uint8_t buffer[4096];
            for (auto& e: buffer) {
                std::cout << +e << " ";
            }
            std::cout << std::endl;
            return false;*/
            /*size_t byteavailable = serialPort.available();
            std::vector<uint8_t> buffer(byteavailable);
            //uint8_t buffer[4096];
            serialPort.read(buffer, byteavailable);
            uint16_t length(((buffer[1] << 8)| buffer[2]) + 1);
            if (buffer.begin() + 3 < buffer.back()) ;
            //Packet* packet = new Packet(length);*/
            std::cout << "\n\nPacket Received" << std::endl;
            std::cout << "****************" << serialPort.available() << std::endl;
            uint8_t info[3];
            serialPort.read(info, 3);
            uint16_t size(((info[1] << 8)| info[2]) + 1);
            std::cout << "Size : " << size << std::endl;
            Packet* packet = new Packet(size);
            serialPort.read(packet->getPacket(), size);
            dataHandler.updateRx(packet);
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
