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

    loRa.receive(packetRx);

    gpsData.parse(packetRx);
    gpsData.print();

    return 0;
}