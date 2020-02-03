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
#include <Basic/States.h>
#include <File/File.h>
#include <FrameInfo/XbeeOptions.h>
#include <FrameInfo/CRC.h>
#include <Basic/String.h>
#include <Basic/SensorData.h>
#include <Propulsion/IgnitionCode.h>
#include <File/Picture.h>

#include "DataHandler.h"


DataHandler::DataHandler(std::shared_ptr<Connector> connector)
        : connector(connector), dataHandler(packetType::TOTAL_NBR_OF_TYPES, nullptr),
          lastRxID(packetType::GPSID) {
    using namespace packetType;
    using namespace ui_interface;
    // Create your RF Packet Datagram here
    // default protocol header ex: packet Type, packet nbr, timestamp
    for (uint8_t id(0); id < TOTAL_NBR_OF_TYPES; ++id) {
        dataHandler[id] = new Datagram;
        dataHandler[id]->add(new XbeeOptions);
        dataHandler[id]->add(new Header(id));
    }
    ///////////////////////////////////////////////////////////////////////////
    ////////////////////////// Your Playground ////////////////////////////////

    //// Packet Type  XBEE
    dataHandler[XBEE_TEST]->add(new PressureData);
    dataHandler[XBEE_TEST]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[XBEE_TEST]->add(new PressureData);
    dataHandler[XBEE_TEST]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    //// Packet Type n° 1 GPS
    dataHandler[GPSID]->add(new GPS);
    dataHandler[GPSID]->add(new PressureData);
    dataHandler[GPSID]->add(new SensorData<float>(DataType::TEST_SENSOR_DATA));
    dataHandler[GPSID]->add(new SensorData<char>(DataType::TEST_SENSOR_DATA));
    dataHandler[GPSID]->add(new SensorData<uint16_t>(DataType::TEST_SENSOR_DATA));

    //// Packet Type n°2
    dataHandler[PAYLOAD]->add(new PressureData);
    dataHandler[PAYLOAD]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    //// Packet Type n°3    // Test packet without changing values =>  no 0x7E ???
    dataHandler[AVIONICS]->add(new States({1, 1, 1, 1, 0, 0, 1, 0}));
    dataHandler[AVIONICS]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[AVIONICS]->add(new String("Avionics stuff are coming"));

    //// Packet Type n°4
    dataHandler[PROPULSION]->add(new String("~~~~~~~~~~~~~~~~~"));
    dataHandler[PROPULSION]->add(new PressureData);

    //// Packet Type n°5
    //dataHandler[IMAGE]->add(new File("ERT.jpg", 200));
    dataHandler[IMAGE]->add(new Picture(200, "nul.jpg", 600, 600));

    #ifdef RUNNING_ON_RPI
    dataHandler[IGNITION_REQUEST]->add(new IgnitionCode);
    #endif
    dataHandler[IGNITION_ANSWER]->add(new String("/!\\/!\\IGNITION FIRED !!!!"));

    ///////////////////////////////////////////////////////////////////////////
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

bool DataHandler::updateRx(Packet *packet) {
    // TODO  /!\ PROTOCOL define !!! /!\.
    uint8_t frameType = packet->getPacket()[0];
    std::string myDelimiter = {(char) packet->getPacket()[12],
                               (char) packet->getPacket()[13],
                               (char) packet->getPacket()[14],
                               (char) packet->getPacket()[15]};
    auto ID = (packetType::PacketID) packet->getPacket()[16];
    if (frameType == 0x90 && myDelimiter == "EPFL"
        && ID < packetType::TOTAL_NBR_OF_TYPES) {
        connector->incrementData(ui_interface::PACKET_RX_RATE_CTR);
        connector->incrementData(ui_interface::RX_PACKET_CTR);
        lastRxID = ID;
        dataHandler[lastRxID]->updateRx(packet, connector);
        if (lastRxID == packetType::IGNITION_ANSWER)
            connector->setData(ui_interface::IGNITION_STATUS, true);
        return true;
    }
    else if (frameType == 0x88) { // command response
        std::cout << "RSSI = -" << +packet->getPacket()[5] << " dBm" << std::endl;
        connector->setData(ui_interface::LAST_RSSI, packet->getPacket()[5]);
    }
    else {
        connector->incrementData(ui_interface::CORRUPTED_PACKET_CTR);
    }
    return false;
}
