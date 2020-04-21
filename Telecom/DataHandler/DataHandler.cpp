/*!
 * \file DataHandler.cpp
 *
 * \brief DataHandler module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019
 */

#include <FrameInfo/Header.h>
#include <FrameInfo/XbeeOptions.h>
#include <FrameInfo/CRC.h>

#include <Basic/States.h>
#include <Basic/String.h>
#include <Basic/BasicData.h>

#include <Avionics/GPS.h>
#include <Avionics/Telemetry.h>
#include <Avionics/StatusAV.h>

#include <Payload/StatusPL.h>
#include <Payload/PLGps.h>
#include <Payload/PLOrder.h>

#include <GSE/IgnitionCode.h>
#include <GSE/GSEOrder.h>
#include <GSE/GSESensors.h>

#include <Propulsion/PPPressure.h>

#include <File/File.h>
#include <File/Picture.h>

#include "DataHandler.h"


DataHandler::DataHandler(std::shared_ptr<Connector> connector)
        : connector(connector), dataHandler(DatagramType::TOTAL_NBR_OF_TYPES, nullptr),
          lastRxID(DatagramType::INIT) {
    using namespace DatagramType;
    using namespace ui_interface;
    // Create your RF Packet Datagram here
    // default protocol header ex: packet Type, packet nbr, timestamp
    for (uint8_t id(1); id < TOTAL_NBR_OF_TYPES; ++id) {
        dataHandler[id] = new Datagram((DatagramID) id);
        dataHandler[id]->add(new XbeeOptions); // requirement of xbee protocol
        dataHandler[id]->add(new Header(id)); // GS requirement
    }
    ///////////////////////////////////////////////////////////////////////////
    ////////////////////////// Your Playground ////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // Here you can create / compose all your datagram content with your Data
    // First create your Datagram ID in DatagramTypes.h
    // Data are in DataStructures/...
    //// Avionics Datagram
        dataHandler[AV_GPS]->add(new GPS);

        dataHandler[AV_STATUS]->add(new StatusAV);

        dataHandler[AV_TELEMETRY]->add(new Telemetry);

        dataHandler[AV_DEBUG]->add(new String("Hello Avionic"));

    //// GSE Datagram
        dataHandler[GSE_ORDER]->add(new GSEOrder);

        dataHandler[GSE_SENSORS]->add(new GSESensors);

        dataHandler[GSE_IGNITION]->add(new IgnitionCode);

    //// Payload Datagram
        dataHandler[PL_STATE]->add(new StatusPL);

        dataHandler[PL_GPS]->add(new PLGps);

        dataHandler[PL_ORDER]->add(new PLOrder);

        dataHandler[PL_IMAGE]->add(new File("Yann.png"));
        //dataHandler[PL_IMAGE]->add(new Picture("livePic.jpg", 220, 600, 600));

    //// Propulsion Datagram
        dataHandler[PROPULSION]->add(new PPPressure);

    //// Air Brakes Datagram
        dataHandler[AIR_BRAKES]->add(new BasicData<float>(DataType::AIR_BRAKES_ANGLE));

    //// [Subsystem Name] Datagram
        // dataHandler[DatagramID]->add(new MyData);


    //// TEST ----------- Datagram ----------
    dataHandler[TEST]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[TEST]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // END of protocol add CRC
    for (uint8_t id(1); id < TOTAL_NBR_OF_TYPES; ++id) {
        dataHandler[id]->add(new CRC);  // requirement of xbee protocol
    }
}

DataHandler::~DataHandler() {
    for (auto& datagram : dataHandler) delete datagram;
    std::cout << "DataHandler deleted - memory released" << std::endl;
}

void DataHandler::print(DatagramType::DatagramID type) const {
    dataHandler[type]->print();
}

// give data pointer to send
Packet* DataHandler::getPacket(DatagramType::DatagramID type) {
    return dataHandler[type]->getDataPacket();
}

void DataHandler::printLastRxPacket() const {
    std::cout << "\n\nPrinting Last Packet Received..." << std::endl;
    dataHandler[lastRxID]->print();
}

void DataHandler::logLastRxPacket() {
    dataHandler[lastRxID]->log();
}

bool DataHandler::updateTx(DatagramType::DatagramID type) {
    return dataHandler[type]->updateTx(connector);
}

bool DataHandler::updateRx(Packet *packet) {
    if (packet->getPacket()[0] == 0x90) {
        lastRxID = (DatagramType::DatagramID) packet->getPacket()[12]; // Position of Datagram ID in packet
        if (lastRxID > 0 && lastRxID < DatagramType::TOTAL_NBR_OF_TYPES) // ID valid ?
            return dataHandler[lastRxID]->updateRx(packet, connector);
        else
            std::cout << "wrong DatagramID " << lastRxID << std::endl;
    }
    else if (packet->getPacket()[0] == 0x88) { // RSSI command response
        std::cout << "RSSI = -" << +packet->getPacket()[5] << " dBm" << std::endl;
        connector->setData(ui_interface::RSSI_VALUE, packet->getPacket()[5]);
        return false;
    }
    // Else packet won't be parsed
    connector->incrementData(ui_interface::CORRUPTED_PACKET_CTR);
    return false;
}
