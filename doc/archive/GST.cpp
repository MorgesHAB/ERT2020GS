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

    while (true) {
        if (loRa.receive(dataHandler.getPacket(PAYLOAD))) {
            dataHandler.parse(PAYLOAD);
            dataHandler.print(PAYLOAD);
        }
        usleep(10); //microseconds
    }
    return 0;
}
