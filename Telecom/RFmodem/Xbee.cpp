/*!
 * \file XBee.cpp
 *
 * \brief XBee module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#include "Xbee.h"


Xbee::Xbee(std::string port) : serialPort(port, 115200) {}

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
            /*size_t byteAvailable(serialPort.available());
            std::cout << "Byte available : " << byteAvailable << std::endl;
            //std::vector<uint8_t> buf(byteAvailable);
            uint8_t buf[byteAvailable];
            std::cout << "byte read : " << serialPort.read(buf, byteAvailable) << std::endl;
            std::cout << "Print packet Debug byte per byte :" << std::endl;
            for (auto& e : buf) std::cout << +e << " ";
            std::cout << std::endl;

            for (size_t i(0); i < byteAvailable; ++i) {
                if (buf[i] == 0x7E) {
                    uint16_t length(((buf[i + 1] << 8) | buf[i + 2]) + 1);
                    std::cout << "length : " << length << std::endl;
                    if (i + length + 2 > byteAvailable) continue;
                    Packet *packet = new Packet(length);
                    for (size_t j(i); j < length; ++j) {
                        packet->getPacket()[j] = buf[j];
                    }
                    dataHandler.updateRx(packet);
                    i += length + 2;
                }
            }*/
            //std::cout << "\n\nPacket Received" << std::endl;
            size_t byteAvail(serialPort.available());
            //std::cout << "byte avail " << byteAvail << std::endl;
            uint8_t info[3];
            serialPort.read(info, 3);
            uint16_t length(((info[1] << 8)| info[2]) + 1);
            //std::cout << "length : " << length << std::endl;
            Packet* packet = new Packet(length);
            size_t byteRead(serialPort.read(packet->getPacket(), length));
            //std::cout << "byte read : " << byteRead << std::endl;
            if (byteRead + 3 != byteAvail) std::cout << "PROBLEM !!!!!! " << byteRead << " vs " << byteAvail << std::endl;
            //std::cout << "Xbee options : " << +packet->getPacket()[11] << std::endl;
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
