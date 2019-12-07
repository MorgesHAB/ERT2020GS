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


DataHandler::DataHandler(std::shared_ptr<Connector> connector)
        : connector(connector), dataHandler(NBR_OF_TYPE, nullptr), lastRxID(GPSID) {

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
    dataHandler[XBEE_TEST]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[XBEE_TEST]->add(new PressureData);
    dataHandler[XBEE_TEST]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    //// Packet Type n° 1 GPS
    //dataHandler[GPSID]->add(new GPS);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new PressureData);

    //// Packet Type n°2
    dataHandler[PAYLOAD]->add(new PressureData);
    dataHandler[PAYLOAD]->add(new IgnitionData);
    dataHandler[PAYLOAD]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    //// Packet Type n°3    // Test packet without changing values =>  no 0x7E ???
    dataHandler[AVIONICS]->add(new States({1, 1, 1, 1, 0, 0, 1, 0}));
    dataHandler[AVIONICS]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[AVIONICS]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[AVIONICS]->add(new String("First sentence transmit via XBee !!"));

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
    std::cout << "DataHandler deleted - memory released" << std::endl;
}

void DataHandler::print(PacketID type) const {
    dataHandler[type]->print();
}

// give data pointer to send
Packet* DataHandler::getPacket(PacketID type) {
    return dataHandler[type]->getDataPacket();
}

void DataHandler::printLastRxPacket() const {
    static int i(0);
    std::cout << "loop " << ++i << std::endl;
    dataHandler[lastRxID]->print();
}

void DataHandler::updateTx(PacketID type) {
    dataHandler[lastRxID]->updateTx(connector);
}

void DataHandler::updateRx(Packet *packet) {
    auto ID = (PacketID) (packet->getPacket()[12]); // TODO PROTOCOL define !!!
    if (ID < NBR_OF_TYPE) {
        lastRxID = ID;
        packet->printDebug();
        std::cout << "lastRxID " << lastRxID << std::endl;

        dataHandler[lastRxID]->updateRx(packet, connector);
    }
    else {
        std::cout << "!!!!!!!!!!!!!! RXID > NBR_OF_TYPE  " << ID << std::endl;
        packet->printDebug();
        exit(0);
    }
}
