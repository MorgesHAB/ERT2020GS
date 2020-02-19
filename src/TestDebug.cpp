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
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 */

#include <serial/serial.h>
#include <iostream>

int main() {
    serial::Serial serialPort("/dev/ttyS6", 115200);
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

    if (serialPort.isOpen()) {
        serialPort.write(command, sizeof(command));
        std::cout << "Test packet have been sent" << std::endl;
    }
    return 0;
}