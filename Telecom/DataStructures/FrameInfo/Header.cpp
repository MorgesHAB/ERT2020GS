/*!
 * \file Header.cpp
 *
 * \brief Header module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        22.11.2019	
 */

#include <DataHandler.h>    // for PacketID
#include "Header.h"

uint32_t Header::packetNbr = 0;     // init static variable

Header::Header(uint8_t packetID) : packetID(packetID),
                                   timestamp(std::time(nullptr)) {}

void Header::write(Packet &packet) {
    packet.write(packetID);
    packet.write(packetNbr);
    packet.write(timestamp);
}

void Header::parse(Packet &packet) {
    packet.parse(packetID);
    packet.parse(packetNbr);
    packet.parse(timestamp);
}

void Header::print() const {
    std::cout << "*** Packet Type : ";
    switch (packetID) {
        case GPSID: std::cout << "GPS";
            break;
        case PAYLOAD: std::cout << "Payload";
            break;
        case AVIONICS: std::cout << "Avionics";
            break;
        case PROPULSION: std::cout << "Propulsion";
            break;
        case IMAGE: std::cout << "Image";
            break;
        case XBEE_TEST: std::cout << "Xbee frame";
            break;
        default: std::cout << "Unknown";
    }
    std::cout << "\t packet nbr: " << packetNbr << "\t time: "
              << std::asctime(std::localtime(&timestamp)) << std::endl;
}

void Header::updateTx(std::shared_ptr<Connector> connector) {
    ++packetNbr;
    timestamp = std::time(nullptr);
}

void Header::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::PACKET_ID, packetID);
    connector->setData(ui_interface::PACKET_NBR, packetNbr);
    connector->setData(ui_interface::TIMESTAMP, timestamp);
}