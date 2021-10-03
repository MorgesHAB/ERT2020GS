/*!
 * \file Worker.cpp
 *
 * \brief Worker module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        05.12.2019	
 */

#include <thread>
#include <chrono>
#include <Xbee.h>
#include "Worker.h"

#define PACKET_FLOW_NBR        5

Worker::Worker(std::shared_ptr<Connector> connector) : connector(connector) {}


void Worker::mainRoutine() {
    while (connector->getData<bool>(ui_interface::RUNNING)) {
        //Create the RF packet handler
        DataHandler dataHandler(connector);
        // Wait that we clicked on Active Xbee or we close the Window
        while (!connector->getData<bool>(ui_interface::ACTIVE_XBEE)) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (connector->getData<bool>(ui_interface::RUNNING) == false) return;
        }

        // Your RF modem
        RFmodem* xbee = new Xbee(getSerialport());
        //RFmodem* loRa = new LoRa;   // another example

        connector->setData(ui_interface::SERIALPORT_STATUS, (xbee->isOpen()) ? 1 : 2);

        if (xbee->isOpen()) {
            while (connector->getData<bool>(ui_interface::ACTIVE_XBEE) &&
                   connector->getData<bool>(ui_interface::RUNNING)) {

                RFroutine(dataHandler, xbee);

                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        } else {
            connector->setData(ui_interface::ACTIVE_XBEE, false);
            std::this_thread::sleep_for(std::chrono::seconds(3)); // time to show error
        }
        delete xbee;
        connector->setData(ui_interface::SERIALPORT_STATUS, 0);
    }
}


void Worker::RFroutine(DataHandler& dataHandler, RFmodem* rfmodem) {
    // Manage Reception

    if (rfmodem->receive(dataHandler)) {
        //if (connector->getData<bool>(ui_interface::LOGGING_ACTIVE)) // always log -waiting a button
            dataHandler.logLastRxPacket();
        dataHandler.printLastRxPacket();
    }

    // Manage Transmission
    
    // Manage Ignition
    if (dataHandler.updateTx(DatagramType::GSE_IGNITION)) {
        // /!\ Critical point /!\.
        for (int i(0); i < PACKET_FLOW_NBR; ++i) {
            rfmodem->send(dataHandler.getPacket(DatagramType::GSE_IGNITION));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        connector->setData(ui_interface::IGNITION_SENT, true);
    }


    // Manage GSE Orders
    if (dataHandler.updateTx(DatagramType::GSE_ORDER)) {
        for (int i(0); i < PACKET_FLOW_NBR; ++i) {
            rfmodem->send(dataHandler.getPacket(DatagramType::GSE_ORDER));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    //Manage GSE Ping
    if (dataHandler.updateTx(DatagramType::GSE_PING)) {
            rfmodem->send(dataHandler.getPacket(DatagramType::GSE_PING));
    }

    //Manage PP Commands
    if (dataHandler.updateTx(DatagramType::PP_COMMAND)){
        for (int i(0); i < PACKET_FLOW_NBR; ++i) {
            rfmodem->send(dataHandler.getPacket(DatagramType::PP_COMMAND));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    if (dataHandler.updateTx(DatagramType::TVC_COMMAND)){
        for (int i(0); i < PACKET_FLOW_NBR; ++i) {
            rfmodem->send(dataHandler.getPacket(DatagramType::TVC_COMMAND));
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    
    // Manage Image Transmission
    /*if (dataHandler.updateTx(DatagramType::PL_IMAGE))
        rfmodem->send(dataHandler.getPacket(DatagramType::PL_IMAGE));*/

    // if need to send AT command for RSSI
    if (connector->eatData<bool>(ui_interface::RSSI_READ_ORDER, false))
        rfmodem->getRSSI();

}

std::string Worker::getSerialport() {
    switch (connector->getData<uint64_t>(ui_interface::SERIALPORT_INDEX)) {
        case 0:
            return "/dev/ttyUSB0";
        case 1:
            return "/dev/ttyUSB1";
        case 2:
            return "/dev/ttyS3";
        case 3:
            return "/dev/ttyS6";
        default:
            return "/dev/ttyUSB0";
    }
}
