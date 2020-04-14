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
#define XBEE_START                  0x7e
#define API_TRANSMIT_REQUEST        0x10 // Transmit request frame
#define API_RECEIVED_PACKET         0x90 // Received request frame


XbeeOptions::XbeeOptions() :
        xbeeTransmitOptions {
            API_TRANSMIT_REQUEST,  // Frame type // Transmit Request frame - 0x10
            0x00,           // Frame ID - Setting it to '0' will disable response frame.
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,     // 64 bit dest address // broadcast
            0xff, 0xfe,           // 16 bits dest address (0xff fe = broadcast) unknown address
            0x00,           // Broadcast radius (0 = max) no hops
            0x43} // = 0100 0011‬    // Transmit options (disable ACK and Route discovery) see p.103/187 doc
            {}


void XbeeOptions::write(Packet &packet) {
    packet.write((uint8_t)XBEE_START);
    uint16_t size = XBEE_TX_OPTIONS_SIZE; //!!! will be set later in CRC class
    packet.write(size);

    for (auto& part : xbeeTransmitOptions) packet.write(part);
}

void XbeeOptions::parse(Packet &packet) {
    /*uint8_t startDelimiter;       // already parsed in xbee.receive()
    //packet.parse(startDelimiter);
    uint16_t length;
    //packet.parse(length); */
    for (auto& part : xbeeReceivedOptions) packet.parse(part);
}

bool XbeeOptions::updateRx(std::shared_ptr<Connector> connector) {
    return xbeeReceivedOptions[0] == API_RECEIVED_PACKET;
}
