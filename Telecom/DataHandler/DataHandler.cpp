/*!
 * \file DataHandler.cpp
 *
 * \brief DataHandler module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019	
 */

#include <GPS.h>
#include <PressureData.h>
#include <IgnitionData.h>
#include <States.h>
#include <Picture.h>
#include <PacketType.h>

#include "DataHandler.h"


DataHandler::DataHandler() : dataHandler(NBR_OF_TYPE, nullptr), lastRxID(GPSID) {
    // Create your RF Packet Datagram here

    //// Packet Type n° 1 GPS
    Datagram* datagram1 = new Datagram;
    datagram1->add(new PacketType(GPSID));
    datagram1->add(new GPS);
    datagram1->add(new PressureData);
    dataHandler[GPSID] = datagram1;

    //// Packet Type n°2
    Datagram* datagram2 = new Datagram;
    datagram2->add(new PacketType(PAYLOAD));
    datagram2->add(new PressureData);
    datagram2->add(new IgnitionData);
    datagram2->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));
    dataHandler[PAYLOAD] = datagram2;

    //// Packet Type n°3
    Datagram* datagram3 = new Datagram;
    datagram3->add(new PacketType(AVIONICS));
    datagram3->add(new States({1, 1, 1, 1, 0, 0, 1, 0}));
    dataHandler[AVIONICS] = datagram3;

    //// Packet Type n°4
    Datagram* datagram4 = new Datagram;
    datagram4->add(new PacketType(PROPULSION));
    datagram4->add(new PressureData);
    datagram4->add(new PressureData);
    dataHandler[PROPULSION] = datagram4;

    //// Packet Type n°5
    Datagram* datagram5 = new Datagram;
    datagram5->add(new PressureData);
    //datagram5->add(new Picture(100));
    dataHandler[IMAGE] = datagram5;
}

DataHandler::~DataHandler() {
    for (auto& datagram : dataHandler) delete datagram;
}

void DataHandler::update(PacketID type) {
    dataHandler[type]->update();
}

void DataHandler::parse(PacketID type) {
    dataHandler[type]->parse();
}

void DataHandler::print(PacketID type) const {
    dataHandler[type]->print();
}

Packet &DataHandler::getPacket(PacketID type) {
    return dataHandler[type]->getDataPacket();
}

void DataHandler::setPacket(Packet &packet) {
    lastRxID = (PacketID) packet.getType();
    dataHandler[lastRxID]->getDataPacket() = packet;
    dataHandler[lastRxID]->parse();
}

void DataHandler::printLastRxPacket() const {
    dataHandler[lastRxID]->print();
}

const std::vector<Data *> &DataHandler::getDatagram(PacketID type) {
    return dataHandler[type]->getDatagram();
}

PacketID DataHandler::getLastRxID() const {
    return lastRxID;
}
