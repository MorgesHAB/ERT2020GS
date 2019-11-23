/*!
 * \file DataHandler.cpp
 *
 * \brief DataHandler module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019	
 */

#include <Header.h>
#include <GPS.h>
#include <PressureData.h>
#include <IgnitionData.h>
#include <States.h>
#include <Picture.h>
#include "DataHandler.h"


DataHandler::DataHandler() : dataHandler(NBR_OF_TYPE, nullptr), lastRxID(GPSID) {
    // Create your RF Packet Datagram here
    // default protocol header ex: packet Type, packet nbr, timestamp
    for (uint8_t id(0); id < NBR_OF_TYPE; ++id) {
        dataHandler[id] = new Datagram;
        dataHandler[id]->add(new Header(id));
    }

    //// Packet Type n° 1 GPS
    //dataHandler[GPSID]->add(new GPS);
    dataHandler[GPSID]->add(new PressureData);

    //// Packet Type n°2
    dataHandler[PAYLOAD]->add(new PressureData);
    dataHandler[PAYLOAD]->add(new IgnitionData);
    dataHandler[PAYLOAD]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    //// Packet Type n°3
    dataHandler[AVIONICS]->add(new States({1, 1, 1, 1, 0, 0, 1, 0}));

    //// Packet Type n°4
    dataHandler[PROPULSION]->add(new PressureData);
    dataHandler[PROPULSION]->add(new PressureData);

    //// Packet Type n°5
    dataHandler[IMAGE]->add(new Picture(200, "pictureZ", 40, 40));
    //dataHandler[IMAGE]->add(new Picture(100));
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

void DataHandler::setPacket(Packet* packet) {
    lastRxID = (PacketID) (packet->getType() % NBR_OF_TYPE); // tmp avoid seg fault
    dataHandler[lastRxID]->getDataPacket() = *packet;
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
