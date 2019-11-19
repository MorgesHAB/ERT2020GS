/*!
 * \file GSE.cpp
 *
 * \brief Ground Support Equipment Transceiver
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

    while (true) {
        dataHandler.update(PAYLOAD);
        loRa.send(dataHandler.getPacket(PAYLOAD));
        usleep(100000);
    }

    return 0;
}