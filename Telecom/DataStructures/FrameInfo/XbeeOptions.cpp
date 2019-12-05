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
            0x00,           // Frame ID
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,     // 64 bit dest address // broadcast
            0xff, 0xfe,           // 16 bits dest address (0xff fe = broadcast)
            0x00,           // Broadcast radius (0 = max)
            0x43}          // Transmit options (disable ACK and Route discovery)
            {}


void XbeeOptions::write(Packet &packet) {
    packet.write((uint8_t)XBEE_START);
    uint16_t size = XBEE_FRAME_OPTIONS_SIZE; //!!! will be set later in CRC
    packet.write(size);

    for (uint8_t& part : XBEE_FRAME_OPTIONS) packet.write(part);
}

void XbeeOptions::parse(Packet &packet) {
    uint8_t tmp;
    //packet.parse(tmp); // TODO
    uint16_t size;
    //packet.parse(size);

    for (size_t i(0); i < XBEE_API_RX_INDICATOR; ++i) packet.parse(XBEE_FRAME_OPTIONS[i]);
}

void XbeeOptions::update() {}

void XbeeOptions::print() const {
    // Don't print Xbee options
}

void XbeeOptions::writeConnector(std::shared_ptr<Connector> connector) {

}
