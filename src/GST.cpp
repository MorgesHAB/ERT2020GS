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

using namespace std;

int main() {
    Packet packetRx;
    GPS gpsData;
    LoRa loRa;
    float f;

    while (true) {
        if (loRa.receive(packetRx)) {
            std::cout << "LoRa last RSSI : " << loRa.getRSSI() << std::endl;
            gpsData.parse(packetRx);
            packetRx.parse(f);
            std::cout << "Last float = " << f << std::endl;
            gpsData.print();
        }
        usleep(1); //microseconds
    }

    return 0;
}