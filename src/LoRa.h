/*!
 * \file LoRa.h
 
 * \brief LoRa module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        03.11.2019	
 */

#ifndef LoRa_H
#define LoRa_H

#include <RH_RF95.h>

class LoRa {
public:
    LoRa(double frequency = 868.0, double TxPower = 23, int mode = 1);
    void send(const uint8_t* data, uint8_t len);

private:
    RH_RF95 rf95;
};


#endif //LoRa_H
