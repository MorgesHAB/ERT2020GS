/*!
 * \file Worker.cpp
 *
 * \brief Worker module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        05.12.2019	
 */

#include "Worker.h"

Worker::Worker(std::shared_ptr<Connector> connector) : connector(connector) {}


void Worker::mainRoutine() {
    // Your RF modem
    Xbee xbee;      // Can use eg:      LoRa loRa;
    // RF packet handler
    DataHandler dataHandler;

    while (!connector->getData<bool>(ui_interface::ACTIVE_XBEE));
    std::cout << "Xbee init now" << std::endl;
    xbee.initSerialPort();

    while (connector->getData<bool>(ui_interface::RUNNING)) {
        if (xbee.receive(dataHandler)) {
            dataHandler.parse(XBEE_TEST);
            dataHandler.print(XBEE_TEST);
            //dataHandler.update(XBEE_TEST); Tx part
            dataHandler.writeConnector(XBEE_TEST, connector);
        }
    }
}