/*!
 * \file ACK.cpp
 *
 * \brief ACK module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.04.2020	
 */

#include "ACK.h"

ACK::ACK(ui_interface::DataType indexName) : ackvalue(0), indexName(indexName) {}

bool ACK::updateTx(std::shared_ptr<Connector> connector) {
    if (ackvalue == 0) ackvalue = 1;
    return true;
}

void ACK::write(Packet &packet) {
    packet.write(ackvalue);
}

void ACK::parse(Packet &packet) {
    packet.parse(ackvalue);
}

bool ACK::updateRx(std::shared_ptr<Connector> connector) {
    switch (ackvalue) {
        case 1:
            ackvalue = 2;
            return true;
        case 2:
            connector->setData(indexName, ackvalue);
            ackvalue = 0;
            return false; // next update won't be called & no print or log
        default:
            return true; // print packet
    }
}
