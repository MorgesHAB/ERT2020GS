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

bool Datagram::updateTx(std::shared_ptr<Connector> connector) {
    delete dataPacket;  // Data should have been logged
    dataPacket = new Packet;

    bool status(true);
    for (auto &data : datagram) {
        if (status) {
            status &= data->updateTx(connector);
            data->write(*dataPacket);
        }
    }
    return status;
}

bool Datagram::updateRx(Packet *packet, std::shared_ptr<Connector> connector) {
    delete dataPacket;      // sometimes cause seg fault ... ||
    dataPacket = packet;

    bool status(true);
    for (auto &data : datagram) {
        if (status) {
            data->parse(*dataPacket);
            status &= data->updateRx(connector);
        }
    }
    return status;
}

void Datagram::log() {
    logger.log(this);
}
