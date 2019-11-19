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
        case 1 : rf95.setModemConfig(RH_RF95::Bw125Cr45Sf128);
            break;
        case 2 : rf95.setModemConfig(RH_RF95::Bw500Cr45Sf128);
            break;
        case 3 : rf95.setModemConfig(RH_RF95::Bw31_25Cr48Sf512);
            break;
        case 4 : rf95.setModemConfig(RH_RF95::Bw125Cr48Sf4096);
            break;
    }
}

void LoRa::send(Packet &packet) {
    rf95.send(packet.getPacket(), packet.getSize());
    std::cout << "Packet have been sent" << std::endl;
}

bool LoRa::receive(Packet &packet) {
    if (rf95.available()) {
        packet.restart();
        uint8_t length(RH_RF95_MAX_MESSAGE_LEN);
        if (rf95.recv(packet.getPacket(), &length)) {
            std::cout << "\n\nPacket Received" << std::endl;
            std::cout << "LoRa last RSSI : " << getRSSI() << " dBm" << std::endl;
            return true;
        }
    }
    return false;
}

bool LoRa::receive(DataHandler &dataHandler) {
    if (rf95.available()) {
        Packet packet; // should be new to avoid copy !!
        uint8_t length(RH_RF95_MAX_MESSAGE_LEN);
        if (rf95.recv(packet.getPacket(), &length)) {
            std::cout << "\n\nNew Packet Received" << std::endl;
            std::cout << "LoRa last RSSI : " << getRSSI() << " dBm" << std::endl;
            dataHandler.setPacket(packet);
            return true;
        }
    }
    return false;
}

int LoRa::getRSSI() {
    return rf95.lastRssi();
}