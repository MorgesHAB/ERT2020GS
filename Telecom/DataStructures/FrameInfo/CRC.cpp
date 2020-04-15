/*!
 * \file CRC.cpp
 *
 * \brief CRC module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        29.11.2019	
 */

#include "CRC.h"

#define XBEE_FRAME_BEGINNING_SIZE       3   // Start delimiter (0x7E) +
                                            // uint16_t length of the frame

void CRC::write(Packet &packet) {
    // Set length of packet because we know that CRC is the last byte
    packet.getPacket()[2] = packet.getSize() - XBEE_FRAME_BEGINNING_SIZE;

    // Compute and write the CRC
    CRC = 0;
    for (size_t i(XBEE_FRAME_BEGINNING_SIZE); i < packet.getSize(); ++i) {
        CRC += packet.getPacket()[i];
    }
    CRC = 0xff - CRC;
    packet.write(CRC);
}

void CRC::parse(Packet &packet) {
    packet.parse(CRC);
}
