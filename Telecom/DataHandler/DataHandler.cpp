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
#include <Avionics/Telemetry.h>
#include <Propulsion/PPPressure.h>
#include <Basic/States.h>
#include <File/File.h>
#include <FrameInfo/XbeeOptions.h>
#include <FrameInfo/ACKManager.h>
#include <FrameInfo/CRC.h>
#include <Basic/String.h>
#include <Basic/SensorData.h>
#include <Propulsion/IgnitionCode.h>
#include <File/Picture.h>
#include <GSE/GSEOrder.h>
#include <GSE/GSESensors.h>
#include <Avionics/StatusAV.h>

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
        dataHandler[id]->add(new XbeeOptions);
        dataHandler[id]->add(new Header(id));
    }
    ///////////////////////////////////////////////////////////////////////////
    ////////////////////////// Your Playground ////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    //// Avionics Datagram
    dataHandler[AV_GPS]->add(new GPS);

    dataHandler[AV_STATUS]->add(new StatusAV);

    dataHandler[AV_TELEMETRY]->add(new Telemetry);

    //// Propulsion Datagram
    dataHandler[PROPULSION]->add(new PPPressure);

    //// Air Brakes Datagram
    dataHandler[AIR_BRAKES]->add(new SensorData<float>(DataType::AIR_BRAKES_ANGLE));

    //// Payload Datagram
    dataHandler[PL_STATE]->add(new String("Not ready yet"));
    dataHandler[PL_STATE]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    //dataHandler[PL_IMAGE]->add(new File("panda.jpg", 200));
    dataHandler[PL_IMAGE]->add(new File("Yann.png", 200));
    //dataHandler[PL_IMAGE]->add(new Picture(200, "livePic.jpg", 600, 600));



    //// GSE Datagram
    //dataHandler[GSE_ORDER]->add(new GSEOrder);

    // Acknowledge
    dataHandler[ACK]->add(new ACKManager);

    #ifdef RUNNING_ON_RPI
    dataHandler[GSE_IGNITION]->add(new IgnitionCode);
    #endif

    //// TEST ----------- Datagram
    dataHandler[TEST]->add(new String("First sentence transmit via XBee !!"));
    dataHandler[TEST]->add(new States({1, 0, 1, 1, 0, 0, 1, 0}));

    dataHandler[IGNITION_ANSWER]->add(new SensorData<ignit::IgnitionState>(DataType::IGNITION_STATUS));

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // END of protocol add CRC
    for (uint8_t id(1); id < TOTAL_NBR_OF_TYPES; ++id) {
        dataHandler[id]->add(new CRC);
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
        return dataHandler[lastRxID]->updateRx(packet, connector);
    }
    else if (packet->getPacket()[0] == 0x88) { // RSSI command response
        std::cout << "RSSI = -" << +packet->getPacket()[5] << " dBm" << std::endl;
        connector->setData(ui_interface::RSSI_VALUE, packet->getPacket()[5]);
    }
    // Else packet won't be parsed
    connector->incrementData(ui_interface::CORRUPTED_PACKET_CTR);
    return false;
}
