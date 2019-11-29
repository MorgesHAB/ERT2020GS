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
#define XBEE_ESCAPE 0x7d
#define XBEE_TX_FRAME_TYPE 0x10 // Transmit request frame
#define XBEE_FRAME_BEGINNING_SIZE 3 // Start delimiter (0x7E) + uint16_t length of the frame
#define XBEE_CHECKSUM_SIZE 1 // checksum size of the XBee packet
#define XBEE_API_RX_INDICATOR 12 // xbee option size in Rx side


XbeeOptions::XbeeOptions() : msg{0x7E, 0x00, 0x1B, 0x10, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
                                 0xFE, 0x00, 0x43, 0x55, 0x55, 0x55, 0x55, 0x14, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x14, 0x35},
XBEE_FRAME_OPTIONS{
            XBEE_TX_FRAME_TYPE,  // Frame type
            0x00,           // Frame ID
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,     // 64 bit dest address // broadcast
            0xff, 0xfe,           // 16 bits dest address (0xff fe = broadcast)
            0x00,           // Broadcast radius (0 = max)
            0x43}          // Transmit options (disable ACK and Route discovery)

            , data("Hello Nils c'est Lionel"), nbr(102314455)
{}


void XbeeOptions::write(Packet &packet) {
    //for (uint8_t& part : msg) packet.write(part);
    packet.write((uint8_t)XBEE_START);
    uint16_t size = XBEE_FRAME_OPTIONS_SIZE + sizeof(nbr) + data.size();
    packet.write(size);

    for (uint8_t& part : XBEE_FRAME_OPTIONS) packet.write(part);

    packet.write(data);
    packet.write(nbr);

    // calculate CRC
    uint8_t CRC(0);
    for (size_t i(XBEE_FRAME_BEGINNING_SIZE); i < packet.getSize(); ++i) {
        CRC += packet.getPacket()[i];
    }
    CRC = 0xff - CRC;
    packet.write(CRC);
}

void XbeeOptions::parse(Packet &packet) {
    //for (uint8_t& part : msg) packet.parse(part);
    uint8_t tmp;
    packet.parse(tmp);
    uint16_t size;
    packet.parse(size);

    for (size_t i(0); i < XBEE_API_RX_INDICATOR; ++i) packet.parse(XBEE_FRAME_OPTIONS[i]);

    packet.parse(data);
    packet.parse(nbr);
 /*   for (uint8_t& part : msg) {
        part = 0;
        packet.parse(part);
        std::cout << +part << " ";
    }
    std::cout << std::endl;*/
}

void XbeeOptions::update() {

}

void XbeeOptions::print() const {
    //for (uint8_t part : msg) std::cout << +part;
    std::cout << "Data : " << data  << "  nbr: " << nbr << std::endl;
}