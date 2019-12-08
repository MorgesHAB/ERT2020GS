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
#include "Worker.h"

Worker::Worker(std::shared_ptr<Connector> connector) : connector(connector) {}


void Worker::mainRoutine() {

    while (connector->getData<bool>(ui_interface::RUNNING)) {
        // RF packet handler
        DataHandler dataHandler(connector);
        // Wait that we clicked on Active Xbee or we close the Window
        while (!connector->getData<bool>(ui_interface::ACTIVE_XBEE)) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            if (!connector->getData<bool>(ui_interface::RUNNING)) return;
        }

        // Your RF modem    // Can use eg:      LoRa loRa;
        Xbee xbee("/dev/ttyS3");
        std::cout << "Xbee init now" << std::endl;

        while (connector->getData<bool>(ui_interface::ACTIVE_XBEE) &&
               connector->getData<bool>(ui_interface::RUNNING)) {
            if (xbee.receive(dataHandler)) {
                dataHandler.printLastRxPacket();
            }
            if (connector->eatData<bool>(ui_interface::IGNITION_CLICKED, false)) {
                xbee.send(dataHandler.getPacket(PROPULSION_TEST));
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(7));
        }
    }
}
