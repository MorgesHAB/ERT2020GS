/*!
 * \file LoRa.cpp
 *
 * \brief LoRa module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        03.11.2019	
 */

#include "LoRa.h"
#include <iostream>

LoRa::LoRa(double frequency, double TxPower, int mode) {
    wiringPiSetupGpio();

    if (!rf95.init()) {
        std::cout << "LoRa Init failed" << std::endl;
        exit(0);
    }
    rf95.setFrequency(frequency); /* MHz */
    rf95.setTxPower(TxPower);
    switch(mode) {
        case 1 :
            rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128);
            break;
        case 2 :
            rf95.setModemConfig(RH_RF95::Bw500Cr45Sf128);
            break;
        case 3 :
            rf95.setModemConfig(RH_RF95::Bw31_25Cr48Sf512);
            break;
        case 4 :
            rf95.setModemConfig(RH_RF95::Bw125Cr48Sf4096);
            break;
    }
}


void LoRa::send(const Packet &packet) {
    rf95.send(packet.getPacket(), packet.getSize());
}

void LoRa::receive(const Packet &packet) {
    if (rf95.available()) {
        uint8_t length(RH_RF95_MAX_MESSAGE_LEN);
        if (rf95.recv(packet.getPacket(), &length)) {
            std::cout << "Packet Received" << std::endl;
        }
    }
}

int LoRa::getRSSI() {
    return rf95.lastRssi();
}