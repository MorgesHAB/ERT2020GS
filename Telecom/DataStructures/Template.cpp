/*!
 * \file Template.cpp
 *
 * \brief MyData module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        20.11.2019	
 */

#include "Template.h"

void MyData::write(Packet &packet) {
    packet.write(nbr);
    packet.write(x);
}

void MyData::parse(Packet &packet) {
    packet.parse(nbr);
    packet.parse(x);
}

void MyData::print() const {
    std::cout << "nbr: " << nbr << "  x: " << x << std::endl;
}

bool MyData::updateTx(std::shared_ptr<Connector> connector) {
    return Data::updateTx(connector);
}

bool MyData::updateRx(std::shared_ptr<Connector> connector) {
    return Data::updateRx(connector);
}
