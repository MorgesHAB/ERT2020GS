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
#include <File/File.h>
#include <FrameInfo/XbeeOptions.h>
#include <FrameInfo/CRC.h>
#include <Test/String.h>
#include <Propulsion/IgnitionCode.h>
#include "DataHandler.h"


DataHandler::DataHandler(std::shared_ptr<Connector> connector)
        : connector(connector), dataHandler(packetType::TOTAL_NBR_OF_TYPES, nullptr),
          lastRxID(packetType::GPSID) {
    using namespace packetType;
    // Create your RF Packet Datagram here
    // default protocol header ex: packet Type, packet nbr, timestamp
    for (uint8_t id(0); id < TOTAL_NBR_OF_TYPES; ++id) {
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
    dataHandler[GPSID]->add(new GPS);
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
    dataHandler[PROPULSION]->add(new String("~~~~~~~~~~~~~~~~~"));
    dataHandler[PROPULSION]->add(new PressureData);

    //// Packet Type n°5
    dataHandler[IMAGE]->add(new File("Data.cpp", 100));

    #ifdef RUNNING_ON_RPI
    dataHandler[IGNITION_REQUEST]->add(new IgnitionCode);
    #endif
    dataHandler[IGNITION_ANSWER]->add(new String("/!\\/!\\IGNITION FIRED !!!!"));

    // END of protocol add CRC
    for (uint8_t id(0); id < TOTAL_NBR_OF_TYPES; ++id) {
        dataHandler[id]->add(new CRC);
    }
}

DataHandler::~DataHandler() {
    for (auto& datagram : dataHandler) delete datagram;
    std::cout << "DataHandler deleted - memory released" << std::endl;
}

void DataHandler::print(packetType::PacketID type) const {
    dataHandler[type]->print();
}

// give data pointer to send
Packet* DataHandler::getPacket(packetType::PacketID type) {
    return dataHandler[type]->getDataPacket();
}

void DataHandler::printLastRxPacket() const {
    std::cout << "\n\nPrinting Last Packet Received..." << std::endl;
    dataHandler[lastRxID]->print();
}

void DataHandler::updateTx(packetType::PacketID type) {
    dataHandler[type]->updateTx(connector);
}

void DataHandler::updateRx(Packet *packet) {
    auto ID = (packetType::PacketID) packet->getPacket()[12]; // TODO PROTOCOL define !!!
    if (ID < packetType::TOTAL_NBR_OF_TYPES) {
        connector->incrementData(ui_interface::PACKET_RX_RATE_CTR);
        connector->incrementData(ui_interface::RX_PACKET_CTR);
        lastRxID = ID;
        dataHandler[lastRxID]->updateRx(packet, connector);
        if (lastRxID == packetType::IGNITION_ANSWER)
            connector->setData(ui_interface::IGNITION_STATUS, true);
    }
    else {
        connector->incrementData(ui_interface::CORRUPTED_PACKET_CTR);
        //printLastRxPacket();
        std::cerr << "\n!!!!!!!!!!!!!! RXID > TOTAL_NBR_OF_TYPES  " << ID << std::endl;
        packet->printDebug();
    }
}
