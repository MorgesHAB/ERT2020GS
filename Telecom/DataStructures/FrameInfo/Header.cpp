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

static uint32_t packet_number_tx = 0;

Header::Header(uint8_t datagramID) : datagramID(datagramID),
                                     timestamp(std::time(nullptr)) {}

bool Header::updateTx(std::shared_ptr<Connector> connector) {
    timestamp = std::time(nullptr);
    return true;
}

void Header::write(Packet &packet) {
    packet.write(datagramID);
    for (auto& e : myDelimiter) packet.write(e);    
    packet.write(timestamp);
    packet.write(packet_number_tx);
    ++packet_number_tx;
}

void Header::parse(Packet &packet) {
    packet.parse(datagramID);
    for (auto& e : myRxDelimiter) packet.parse(e);
    packet.parse(timestamp);
    packet.parse(packetNumber);
}

bool Header::updateRx(std::shared_ptr<Connector> connector) {
    using namespace DatagramType;

    if (!(myRxDelimiter[0] == 'E' && myRxDelimiter[1] == 'P' &&
          myRxDelimiter[2] == 'F' && myRxDelimiter[3] == 'L')) {
        connector->incrementData(ui_interface::CORRUPTED_PACKET_CTR);
        return false;
    }

    connector->setData(ui_interface::LAST_DATAGRAM_ID, datagramID);
    connector->setData(ui_interface::TIMESTAMP, timestamp);

    connector->setData(ui_interface::TIME_SINCE_LAST_RX_PACKET, std::time(nullptr));
    // Increment counter per subsystem for GUI packet rate slider
    connector->incrementData(ui_interface::TOTAL_RX_PACKET_CTR);
    connector->incrementData(ui_interface::PACKET_CTR_ALL);
    switch (datagramID) {
        case AV_TELEMETRY:
        case AV_STATUS:
        case AV_GPS:
        case AV_DEBUG:
        case TVC_COMMAND:
        case TVC_STATUS:
            connector->incrementData(ui_interface::PACKET_CTR_AV);
            break;
        case GSE_SENSORS:
            connector->incrementData(ui_interface::PACKET_CTR_GSE);
            break;
        case GSE_ORDER:
            connector->incrementData(ui_interface::PACKET_CTR_GSE);
            break;
        case GSE_IGNITION:
            connector->incrementData(ui_interface::PACKET_CTR_GSE);
            break;
        case PL_STATE:
            connector->incrementData(ui_interface::PACKET_CTR_PL);
            break;
        case PL_ORDER:
            connector->incrementData(ui_interface::PACKET_CTR_PL);
            break;
        case PL_GPS:
            connector->incrementData(ui_interface::PACKET_CTR_PL);
            break;
        case PL_BME_SENSOR:
            connector->incrementData(ui_interface::PACKET_CTR_PL);
            break;
        case PL_BNO_SENSOR:
            connector->incrementData(ui_interface::PACKET_CTR_PL);
            break;
        //case PL_IMAGE:
        //    connector->incrementData(ui_interface::PACKET_CTR_PL);
        //    break;
        //case PROPULSION:
        //    connector->incrementData(ui_interface::PACKET_CTR_PP);
        //    break;
        case PP_DATA:
            connector->incrementData(ui_interface::PACKET_CTR_PP);
            break;
        case PP_COMMAND:
            connector->incrementData(ui_interface::PACKET_CTR_PP);
            break;
    }
    return true;
}

void Header::print() const {
    std::cout << "*** Packet Type : " << DatagramType::getDatagramIDName(datagramID);
    std::cout << "\t time: " << timestamp  << " [ms]" << std::endl;
}

std::string Header::log() const {
    return std::move("Header" + SEPARATOR +
                     std::to_string(datagramID) + SEPARATOR +
                     std::to_string(timestamp) + SEPARATOR);
}
