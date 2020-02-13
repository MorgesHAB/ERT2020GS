//
// Created by stephanie on 13/02/20.
//

#include <iomanip>
#include "StatusAV.h"

void StatusAV::write(Packet &packet) {
    packet.write(id);
    packet.write(value);
    packet.write(status);
}

void StatusAV::parse(Packet &packet) {
    packet.parse(id);
    packet.parse(value);
    uint8_t statusTmp;
    packet.parse(statusTmp);
    status = (StateValues) statusTmp;
}

void StatusAV::print() const {
    std::cout << std::setprecision(10);
    std::cout << "----- AV STATUS DATA --------------" << std::endl;
    std::cout << "id: " << id << std::endl
              << "value: " << value  << std::endl
              << "status enum: " <<  status << std::endl;
}

std::string StatusAV::log() const {
    return Data::log();
}

void StatusAV::updateTx(std::shared_ptr<Connector> connector) {
}

void StatusAV::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::STATUS_AV_ID, id);
    connector->setData(ui_interface::STATUS_AV_VALUE, value);
    connector->setData(ui_interface::STATUS_AV_STATE, status);
}
