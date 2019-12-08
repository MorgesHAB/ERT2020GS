/*!
 * \file Worker.cpp
 *
 * \brief Worker module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        05.12.2019	
 */

#include "Worker.h"
#include <thread>
#include <chrono>

Worker::Worker(std::shared_ptr<Connector> connector) : connector(connector) {}


using namespace std::chrono_literals;

void Worker::mainRoutine() {
    // RF packet handler
    DataHandler dataHandler(connector);

    while(connector->getData<bool>(ui_interface::RUNNING)){
    
    	// Wait that we clicked on Active Xbee or we close the Window
    	while (!connector->getData<bool>(ui_interface::ACTIVE_XBEE)){
		std::this_thread::sleep_for(2s);
		if(connector->getData<bool>(ui_interface::RUNNING) == false) return;
	}
    	// Your RF modem    // Can use eg:      LoRa loRa;
    	Xbee xbee("/dev/ttyS3");
    	std::cout << "Xbee init now" << std::endl;

    	while (connector->getData<bool>(ui_interface::ACTIVE_XBEE) && 
		connector->getData<bool>(ui_interface::RUNNING)) {
        	if (xbee.receive(dataHandler)) {
        	    dataHandler.printLastRxPacket();
		    //TODO ADD WAITING TIME !!!!!!!!!!!
        	}
    	}
    }
}
