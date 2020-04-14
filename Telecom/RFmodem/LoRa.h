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
#include <RFmodem.h>


class LoRa : public RFmodem {
public:
    explicit LoRa(float frequency = 868.0, double TxPower = 23, int mode = 1);

    void send(Packet *packet) override;

    bool receive(DataHandler &dataHandler) override;
    bool receive(Packet *packet);

    int getRSSI() override;

private:
    RH_RF95 rf95;
};


#endif //LoRa_H
