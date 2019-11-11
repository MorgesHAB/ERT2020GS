/*!
 * \file GST.cpp
 *
 * \brief Ground Station Transceiver
 *
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019	
 */

#include "Packet.h"
#include "GPS.h"
#include "LoRa.h"


int main() {
    Packet packetRx;
    GPS gpsData;
    LoRa loRa;

    while (true) {
        if (loRa.receive(packetRx)) {
            std::cout << "LoRa last RSSI : " << loRa.getRSSI() << std::endl;
            gpsData.parse(packetRx);
            gpsData.print();
        }
        usleep(1); //microseconds
    }

    return 0;
}