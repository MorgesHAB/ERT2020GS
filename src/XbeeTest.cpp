/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file XbeeTest.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 *  The goal of this program is just to transmit some data with Xbee
 *  or try to receive some data from another xbee
 *
 *  NB: A "range test" with XCTU application should already have been successful
 *      before performing this test.
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 */

#include <serial/serial.h>
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "--------------------INFO-----------------" << std::endl;
    std::cout << "Syntax : ./XbeeTest [mode: 'Tx' or 'Rx'] [serialport]" << std::endl;
    std::cout << "Transmit syntax : ./XbeeTest Tx ttyUSB0" << std::endl;
    std::cout << "Receive syntax :  ./XbeeTest Rx ttyS3" << std::endl;
    std::cout << "Default syntax :  ./XbeeTest Rx ttyUSB0" << std::endl;
    std::cout << "------------------------------------------\n" << std::endl;

    std::string port("/dev/ttyUSB0");
    bool modeTx(false);

    if (argc == 3) {
        modeTx = std::string(argv[1]) == "Tx";
        port = "/dev/" + std::string(argv[2]);
    }

    serial::Serial serialPort(port, 115200);
    uint8_t command[] = {0x7E,
                         0x00, 0x10, // length
                         0x10,  // Frame type // Transmit Request frame - 0x10
                         0x00,           // Frame ID - Setting it to '0' will disable response frame.
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,     // 64 bit dest address // broadcast
                         0xff, 0xfe,           // 16 bits dest address (0xff fe = broadcast) unknown address
                         0x00,           // Broadcast radius (0 = max) no hops
                         0x43,

                         0xff, //DATA
                         0xfe, //DATA
                         0xb4 // CRC
    };

    if (modeTx) {
        if (serialPort.isOpen()) {
            serialPort.write(command, sizeof(command));
            std::cout << "Test packet have been sent" << std::endl;
        }
    } else {
        while (true) {
            try {
                if (serialPort.available()) {
                    uint8_t info[3];
                    serialPort.read(info, 3); // read start delimiter & length
                    uint16_t size((info[1] << 8)| info[2]);
                    uint8_t packet[size];
                    serialPort.read(packet, size + 1);

                    std::cout << "\nPacket Received" << std::endl;
                    std::cout << "Size: " << std::to_string(size) << std::endl;
                    for (auto e : info) std::cout << " " << std::hex << +e;
                    for (auto e : packet) std::cout << " " << std:: hex << +e;
                    std::cout << std::endl;
                }
            } catch (const serial::IOException &e) {
                std::cerr << "IOException while reading serial port " << std::endl;
                return 0;
            } catch (const serial::SerialException &e) {
                std::cerr << "SerialException while reading serial port" << std::endl;
                return 0;
            }
        }
    }
    return 0;
}