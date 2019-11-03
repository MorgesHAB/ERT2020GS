/*!
 * \file LoRa.cpp
 *
 * \brief LoRa module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        03.11.2019	
 */

#include "LoRa.h"

LoRa(double frequency, double TxPower, int mode) {
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


void send(const uint8_t* data, uint8_t len) {
    rf95.send(data, len);
}

