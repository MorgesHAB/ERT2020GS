/*!
 * \file XbeeOptions.cpp
 *
 * \brief XbeeOptions module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        29.11.2019	
 */

#include "XbeeOptions.h"

// XBee API mode
#define XBEE_START 0x7e
#define XBEE_TX_FRAME_TYPE 0x10 // Transmit request frame
#define XBEE_API_RX_INDICATOR 12 // xbee option size in Rx side


XbeeOptions::XbeeOptions() :
        XBEE_FRAME_OPTIONS{
            XBEE_TX_FRAME_TYPE,  // Frame type
            0x00,           // Frame ID - Setting it to '0' will disable response frame.
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,     // 64 bit dest address // broadcast
            0xff, 0xfe,           // 16 bits dest address (0xff fe = broadcast) unknown address
            0x00,           // Broadcast radius (0 = max) no hops
            0x01}  //0x43}          // Transmit options (disable ACK and Route discovery)
            {}


void XbeeOptions::write(Packet &packet) {
    packet.write((uint8_t)XBEE_START);
    uint16_t size = XBEE_FRAME_OPTIONS_SIZE; //!!! will be set later in CRC
    packet.write(size);

    for (uint8_t& part : XBEE_FRAME_OPTIONS) packet.write(part);
}

void XbeeOptions::parse(Packet &packet) {
    uint8_t startDelimiter;
    //packet.parse(startDelimiter); // TODO already parsed
    uint16_t length;
    //packet.parse(length);
    uint8_t tmp[XBEE_API_RX_INDICATOR]; // TODO temporaire !!
    for (size_t i(0); i < XBEE_API_RX_INDICATOR; ++i) packet.parse(tmp[i]);
    //for (size_t i(0); i < XBEE_API_RX_INDICATOR; ++i) packet.parse(XBEE_FRAME_OPTIONS[i]);
}

void XbeeOptions::print() const {
    // Don't print Xbee options
}
