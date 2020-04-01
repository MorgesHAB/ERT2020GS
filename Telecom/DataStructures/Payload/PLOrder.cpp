//
// Created by stephanie on 12/03/20.
//

#include "PLOrder.h"


void PLOrder::write(Packet &packet) {
    packet.write(order);
}
void PLOrder::parse(Packet &packet) {
    packet.parse(order);
}
void PLOrder::print() const {

}
std::string PLOrder::log() const {
    return std::move("PL order" + SEPARATOR +
                     std::to_string(order) + SEPARATOR);
}

bool PLOrder::updateTx(std::shared_ptr<Connector> connector) {
    //TODO: order = (create enum)
    return true;
}

bool PLOrder::updateRx(std::shared_ptr<Connector> connector) {
    //For GS, always in transmitting mode for this packet
    return true;
}



