/*!
 * \file GSE.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019	
 */

#include "LoRa.h"
#include "DataHandler.h"
#include "GPS.h"
#include "PressureData.h"


int main() {
    // Your RF modem
    LoRa loRa;

    // Create your RF Packet serialisation
    DataHandler dataHandler;
    dataHandler.add(new GPS);
    dataHandler.add(new PressureData);
   // dataHandler.add(new CPUData);
   // dataHandler.add(new TemperatureData); // etc...

    while (true) {
        dataHandler.update();
        loRa.send(dataHandler.getDataPacket());
        usleep(1000000);
    }

    return 0;
}