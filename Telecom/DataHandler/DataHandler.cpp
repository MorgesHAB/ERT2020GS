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
#include <Propulsion/IgnitionCode.h>
#include "DataHandler.h"


DataHandler::DataHandler(std::shared_ptr<Connector> connector)
        : connector(connector), dataHandler(NBR_OF_TYPE, nullptr), lastRxID(GPSID),
          packetRxCounter(0), ignorePacketRxCounter(0)  {

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
    dataHandler[IMAGE]->add(new PressureData);
    dataHandler[IMAGE]->add(new String("Image coming soon"));
    dataHandler[IMAGE]->add(new IgnitionData);
    //dataHandler[IMAGE]->add(new Picture(230, "pictureZ", 50, 50));

    //dataHandler[PROPULSION_TEST]->add(new IgnitionCode);

    dataHandler[IGNITION_ANSWER]->add(new String("/!\\/!\\IGNITION FIRED !!!!"));

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
    std::cout << "\n\nPrinting Last Packet Received..." << std::endl;
    dataHandler[lastRxID]->print();
}

void DataHandler::updateTx(PacketID type) {
    dataHandler[type]->updateTx(connector);
}

void DataHandler::updateRx(Packet *packet) {
    auto ID = (PacketID) packet->getPacket()[12]; // TODO PROTOCOL define !!!
    if (ID < NBR_OF_TYPE) {
        ++packetRxCounter;
        connector->incrementData(ui_interface::PACKET_RX_RATE_CTR);
        connector->incrementData(ui_interface::RX_PACKET_CTR);
        lastRxID = ID;
        dataHandler[lastRxID]->updateRx(packet, connector);
        if (lastRxID == IGNITION_ANSWER)
            connector->setData(ui_interface::IGNITION_STATUS, true);
    }
    else {
        ++ignorePacketRxCounter;
        printLastRxPacket();
        std::cout << "\n!!!!!!!!!!!!!! RXID > NBR_OF_TYPE  " << ID << std::endl;
        std::cout << "Packet Rx nbr : " << packetRxCounter<< std::endl;
        packet->printDebug();
    }
}
