/*!
 * \file ACKManager.cpp
 *
 * \brief ACKManager module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        13.02.2020	
 */

#include "ACKManager.h"

bool ACKManager::updateTx(std::shared_ptr<Connector> connector) {
    if (connector->eatData<bool>(ui_interface::IGNITION_STATUS, false)) ACK = true;
    return true; // TODO
}

void ACKManager::write(Packet &packet) {
    packet.write((uint8_t) IDtoACK);
    packet.write(ACK);
}

void ACKManager::parse(Packet &packet) {
    uint8_t tmp;
    packet.parse(tmp);
    IDtoACK = (DatagramType::DatagramID) tmp;
    packet.parse(ACK);
}

bool ACKManager::updateRx(std::shared_ptr<Connector> connector) {
    using namespace DatagramType;
    switch (ACK) {
        case 1: {
            switch (IDtoACK) {
                case GSE_IGNITION:
                    connector->setData(ui_interface::IGNITION_STATUS, true);
                    break;
                //case X: other stuff
            }
        }
        break;
        //case XX: other stuff
    }
    return true; // TODO
}

void ACKManager::print() const {

}