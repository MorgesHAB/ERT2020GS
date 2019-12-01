/*!
 * \file MyData.cpp
 *
 * \brief MyData module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        20.11.2019	
 */

#include "MyData.h"

void MyData::write(Packet &packet) {
    packet.write(nbr);
    packet.write(x);
}

void MyData::parse(Packet &packet) {
    packet.parse(nbr);
    packet.parse(x);
}

void MyData::update() {

}

void MyData::print() const {
    std::cout << "nbr: " << nbr << "  x: " << x << std::endl;
}

void MyData::writeConnector(std::shared_ptr<Connector> connector) {

}
