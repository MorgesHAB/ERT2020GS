/*!
 * \file XBee.cpp
 *
 * \brief XBee module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#include "XBee.h"

void XBee::send(Packet &packet) {
/*    if (serialPort.isOpen()) {
        serialPort.write(packet.getPacket(), packet.getSize());
        std::cout << "Packet have been sent" << std::endl;
    }*/
}

bool XBee::receive(Packet &packet) {
    return false;
}
