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
        RFmodem* xbee = new Xbee("/dev/ttyS6");
        //RFmodem* loRa = new LoRa;   // another example

        while (connector->getData<bool>(ui_interface::ACTIVE_XBEE) &&
               connector->getData<bool>(ui_interface::RUNNING)) {
            if (xbee->receive(dataHandler)) {
                dataHandler.printLastRxPacket();
                //dataHandler.logLastRxPacket();
                //xbee.getRSSI();
            }
            manageIgnitionTx(dataHandler, xbee);

            // Image communication
            if (connector->eatData<bool>(ui_interface::SEND_FILE_REQUEST, false)) {
                dataHandler.updateTx(packetType::IMAGE);
                xbee->send(dataHandler.getPacket(packetType::IMAGE));
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        delete xbee;
    }
}


void Worker::manageIgnitionTx(DataHandler& dataHandler, RFmodem* rfmodem) {
    // If ignition from Gui & keys & red button
    dataHandler.updateTx(packetType::IGNITION_REQUEST);
    if (connector->getData<bool>(ui_interface::IGNITION_KEY_1_ACTIVATED) &&
        connector->getData<bool>(ui_interface::IGNITION_KEY_2_ACTIVATED) &&
        connector->getData<bool>(ui_interface::IGNITION_RED_BUTTON_PUSHED) &&
        connector->eatData<bool>(ui_interface::IGNITION_CLICKED, false)) {
        // /!\ Critical point /!\.
        rfmodem->send(dataHandler.getPacket(packetType::IGNITION_REQUEST));
    }
}
