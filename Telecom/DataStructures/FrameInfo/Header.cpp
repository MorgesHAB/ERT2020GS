/*!
 * \file Header.cpp
 *
 * \brief Header module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        22.11.2019	
 */

#include "Header.h"

uint32_t Header::packetNbr = 0;     // init static variable

Header::Header(uint8_t DatagramID) : DatagramID(DatagramID),
                                     timestamp(std::time(nullptr)) {}

void Header::write(Packet &packet) {
    packet.write(DatagramID);
    for (auto& e : myDelimiter) packet.write(e);    
    packet.write(static_cast<uint32_t>(timestamp));
    packet.write(packetNbr);
}

void Header::parse(Packet &packet) {
    packet.parse(DatagramID);
    for (auto& e : myDelimiter) packet.parse(e);
    uint32_t tmp;
    packet.parse(tmp);
    timestamp = static_cast<time_t> (tmp);
    packet.parse(packetNbr);
}

void Header::print() const {
    std::cout << "*** Packet Type : ";

    std::cout << "\t packet nbr: " << packetNbr << "\t time: "
              << std::asctime(std::localtime(&timestamp)) << std::endl;
}

std::string Header::log() const {
    return std::move(
            std::to_string(DatagramID) + SEPARATOR +
            std::to_string(timestamp) + SEPARATOR +
            std::to_string(packetNbr) + SEPARATOR);
}

void Header::updateTx(std::shared_ptr<Connector> connector) {
    ++packetNbr;
    timestamp = std::time(nullptr);
}

void Header::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::PACKET_ID, DatagramID);
    connector->setData(ui_interface::TX_PACKET_NR, packetNbr);
    connector->setData(ui_interface::TIMESTAMP, timestamp);
}
