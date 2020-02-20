/*!
 * \file Datagram.cpp
 *
 * \brief Datagram module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#include "Datagram.h"

Datagram::Datagram(DatagramType::DatagramID ID) : ID(ID), dataPacket(new Packet),
                                        logger(DatagramType::getDatagramIDName(ID)) {}

Datagram::~Datagram() {
    for (auto &data : datagram) delete data;
}

Packet* Datagram::getDataPacket() {
    return dataPacket;
}

void Datagram::add(Data *data) {
    datagram.push_back(data);
}

void Datagram::print() const {
    for (auto &data : datagram) data->print();
}

std::string Datagram::log_description() const {
    std::string datagramLog;
    for (auto &data : datagram) datagramLog += data->log();
    return std::move(datagramLog);
}

void Datagram::updateTx(std::shared_ptr<Connector> connector) {
    delete dataPacket;  // Data should have been logged
    dataPacket = new Packet;

    for (auto &data : datagram) {
        data->updateTx(connector);
        data->write(*dataPacket);
    }
}

void Datagram::updateRx(Packet *packet, std::shared_ptr<Connector> connector) {
    delete dataPacket;
    dataPacket = packet;

    for (auto &data : datagram) {
        data->parse(*dataPacket);
        data->updateRx(connector);
    }
}

void Datagram::log() {
    logger.log(this);
}
