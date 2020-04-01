/*!
 * \file Header.cpp
 *
 * \brief Header module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        22.11.2019	
 */

#include "Header.h"
#include <DatagramTypes.h>

uint32_t Header::packetNbr = 0;     // init static variable

Header::Header(uint8_t datagramID) : datagramID(datagramID),
                                     timestamp(std::time(nullptr)) {}

void Header::write(Packet &packet) {
    packet.write(datagramID);
    for (auto& e : myDelimiter) packet.write(e);    
    packet.write(static_cast<uint32_t>(timestamp));
    packet.write(packetNbr);
}

void Header::parse(Packet &packet) {
    packet.parse(datagramID);
    for (auto& e : myRxDelimiter) packet.parse(e);
    uint32_t tmp;
    packet.parse(tmp);
    timestamp = static_cast<time_t> (tmp);
    packet.parse(packetNbr);
}

void Header::print() const {
    std::cout << "*** Packet Type : " << DatagramType::getDatagramIDName(datagramID);
    std::cout << "\t packet nbr: " << packetNbr << "\t time: "
              << std::asctime(std::localtime(&timestamp)) << std::endl;
}

std::string Header::log() const {
    return std::move("Header" + SEPARATOR +
            std::to_string(datagramID) + SEPARATOR +
            std::to_string(timestamp) + SEPARATOR +
            std::to_string(packetNbr) + SEPARATOR);
}

bool Header::updateTx(std::shared_ptr<Connector> connector) {
    ++packetNbr;
    timestamp = std::time(nullptr);
    return true;
}

bool Header::updateRx(std::shared_ptr<Connector> connector) {
    using namespace DatagramType;

    bool datagramIDcorrect(datagramID > 0 && datagramID < TOTAL_NBR_OF_TYPES);

    if (!(datagramIDcorrect && myRxDelimiter[0] == 'E' && myRxDelimiter[1] == 'P' &&
          myRxDelimiter[2] == 'F' && myRxDelimiter[3] == 'L'))
        return false;

    connector->setData(ui_interface::DATAGRAM_ID, datagramID);
    connector->setData(ui_interface::TX_PACKET_NR, packetNbr);
    connector->setData(ui_interface::TIMESTAMP, timestamp);

    connector->setData(ui_interface::TIME_SINCE_LAST_RX_PACKET, std::time(nullptr));
    // Increment counter per subsystem for GUI packet rate slider
    connector->incrementData(ui_interface::PACKET_CTR_ALL);
    switch (datagramID) {
        case AV_TELEMETRY:
        case AV_STATUS:
        case AV_GPS:
        case AV_DEBUG:
            connector->incrementData(ui_interface::PACKET_CTR_AV);
            break;
        case GSE_STATUS:
        case GSE_ORDER:
        case GSE_IGNITION:
            connector->incrementData(ui_interface::PACKET_CTR_GSE);
            break;
        case PL_STATE:
        case PL_ORDER:
        case PL_GPS:
        case PL_IMAGE:
            connector->incrementData(ui_interface::PACKET_CTR_PL);
            break;
        case PROPULSION:
            connector->incrementData(ui_interface::PACKET_CTR_PP);
            break;
    }
    return true;
}
