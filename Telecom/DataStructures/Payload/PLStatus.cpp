//
// Created by stephanie on 12/03/20.
//

#include "PLStatus.h"

void PLStatus::write(Packet &packet) {
    packet.write(status);
}

void PLStatus::parse(Packet &packet) {
    packet.parse(status);
}

void PLStatus::print() const {

}

std::string PLStatus::log() const {
    return std::move("PL State" + SEPARATOR +
                     std::to_string(status) + SEPARATOR);
}

bool PLStatus::updateRx(std::shared_ptr <Connector> connector) {
    connector->setData(ui_interface::PL_STATE_UI, status);
    return true;
}
