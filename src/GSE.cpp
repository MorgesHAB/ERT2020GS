/*!
 * \file GSE.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019	
 */

#include "Packet.h"
#include "GPS.h"
#include "LoRa.h"
#include <libgpsmm.h>



int main() {
    Packet packet;
    LoRa loRa;
    GPS gpsTest(46.654268333, 6.961496667, 9985.7, 70.9884, "2017-07-01T08:11:39.000Z");
    GPS gps;

    while (true) {
        if (gps.readData()) {
            gps.print();
            gps.write(packet);
            loRa.send(packet);
        }
    }

    return 0;
}