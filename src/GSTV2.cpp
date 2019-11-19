/*!
 * \file GST.cpp
 *
 * \brief Ground Station Transceiver
 *
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019	
 */

#include <LoRa.h>
#include <DataHandler.h>


int main() {
    // Your RF modem
    LoRa loRa;
    // RF packet handler
    DataHandler dataHandler;

    std::cout << "\nLoRa Reception is active... waiting for RF packet..." << std::endl;

    // Automatic detection of the packet type - then auto parse
    while (true) {
        if (loRa.receive(dataHandler)) {
            dataHandler.print();
        }
        usleep(10); //microseconds
    }
    return 0;
}
