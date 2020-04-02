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

#define IGNITION_PACKET_FLOW_NBR        10

Worker::Worker(std::shared_ptr<Connector> connector) : connector(connector) {}


void Worker::mainRoutine() {

    while (connector->getData<bool>(ui_interface::RUNNING)) {
        // RF packet handler
        DataHandler dataHandler(connector);
        // Wait that we clicked on Active Xbee or we close the Window
        while (!connector->getData<bool>(ui_interface::ACTIVE_XBEE)) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (!connector->getData<bool>(ui_interface::RUNNING)) return;
        }

        // Your RF modem
        RFmodem* xbee = new Xbee(getSerialport());
        //RFmodem* loRa = new LoRa;   // another example
        connector->setData(ui_interface::SERIALPORT_ERROR, xbee->isOpen());

        if (xbee->isOpen()) {
            while (connector->getData<bool>(ui_interface::ACTIVE_XBEE) &&
                   connector->getData<bool>(ui_interface::RUNNING)) {
                // Manage Reception
                if (xbee->receive(dataHandler)) {
                    dataHandler.logLastRxPacket();
                    dataHandler.printLastRxPacket();
                }
                // Manage Transmission
                //manageIgnitionTx(dataHandler, xbee);

                // Manage Image Transmission
                if (dataHandler.updateTx(DatagramType::PL_IMAGE))
                    xbee->send(dataHandler.getPacket(DatagramType::PL_IMAGE));

                // if need to send AT command for RSSI
                if (connector->eatData<bool>(ui_interface::RSSI_READ_ORDER, false))
                    xbee->getRSSI();

                std::this_thread::sleep_for(std::chrono::milliseconds(50));
            }
        } else {
            connector->setData(ui_interface::ACTIVE_XBEE, false);
        }
        delete xbee;
    }
}


void Worker::manageIgnitionTx(DataHandler& dataHandler, RFmodem* rfmodem) {
    if (dataHandler.updateTx(DatagramType::GSE_IGNITION)) {
        // /!\ Critical point /!\.
        for (int i(0); i < IGNITION_PACKET_FLOW_NBR; ++i) {
            rfmodem->send(dataHandler.getPacket(DatagramType::GSE_IGNITION));
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        connector->setData(ui_interface::IGNITION_SENT, true);
    }
    //need ack
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
