/*!
 * \file DataHandler.cpp
 *
 * \brief DataHandler module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019
 */

#include <FrameInfo/Header.h>
#include <Avionics/GPS.h>
#include <Test/PressureData.h>
#include <Avionics/IgnitionData.h>
#include <Test/States.h>
#include <Test/Picture.h>
#include <FrameInfo/XbeeOptions.h>
#include <FrameInfo/CRC.h>
#include <Test/String.h>
#include "DataHandler.h"


DataHandler::DataHandler() : dataHandler(NBR_OF_TYPE, nullptr), lastRxID(GPSID) {
    // Create your RF Packet Datagram here
    // default protocol header ex: packet Type, packet nbr, timestamp
    for (uint8_t id(0); id < NBR_OF_TYPE; ++id) {
        dataHandler[id] = new Datagram;
        dataHandler[id]->add(new XbeeOptions);
        dataHandler[id]->add(new Header(id));
    }

    //// Packet Type  XBEE
    dataHandler[XBEE_TEST]->add(new PressureData);
    dataHandler[XBEE_TEST]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[XBEE_TEST]->add(new PressureData);
    dataHandler[XBEE_TEST]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

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
    dataHandler[IMAGE]->add(new PressureData);
    dataHandler[IMAGE]->add(new String("Image coming soon"));
    dataHandler[IMAGE]->add(new IgnitionData);

    //dataHandler[IMAGE]->add(new Picture(230, "pictureZ", 50, 50));


    // END of protocol add CRC
    for (uint8_t id(0); id < NBR_OF_TYPE; ++id) {
        dataHandler[id]->add(new CRC);
    }
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

Packet* DataHandler::getPacket(PacketID type) {
    return dataHandler[type]->getDataPacket();
}

void DataHandler::setPacket(Packet* packet) {
    auto ID = (PacketID) (packet->getPacket()[12]); // TODO PROTOCOL define !!!
    if (ID < NBR_OF_TYPE) {
        lastRxID = ID;
        packet->printDebug();
        //dataHandler[lastRxID]->getDataPacket()->~Packet(); // TODO
        delete dataHandler[lastRxID]->getDataPacket();
        dataHandler[lastRxID]->setPacket(packet);
        dataHandler[lastRxID]->parse();
        std::cout << "lastRxID " << lastRxID << std::endl;
        //dataHandler[lastRxID]->print();
    }
    else {
        std::cout << "!!!!!!!!!!!!!! RXID > NBR_OF_TYPE  " << ID << std::endl;
        packet->printDebug();
        exit(0);
    }
}

void DataHandler::printLastRxPacket() const {
    static int i(0);
    std::cout << "loop " << ++i << std::endl;
    dataHandler[lastRxID]->print();
}

void
DataHandler::writeConnector(PacketID type, std::shared_ptr<Connector> connector) {
    dataHandler[type]->writeConnector(connector);
}
