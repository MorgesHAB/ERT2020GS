//
// Created by stephanie on 12/03/20.
//

#include "StatusPL.h"

void StatusPL::write(Packet &packet) {
    packet.write(status);
}

void StatusPL::parse(Packet &packet) {
    packet.parse(status);
}

void StatusPL::print() const {

}

std::string StatusPL::log() const {
    return std::move("PL State" + SEPARATOR +
                     std::to_string(status) + SEPARATOR);
}

void StatusPL::updateTx(std::shared_ptr <Connector> connector) {
    //For GS, always in receiving mode for this packet
}

void StatusPL::updateRx(std::shared_ptr <Connector> connector) {
    connector->setData(ui_interface::PL_STATE_UI, status);
}
