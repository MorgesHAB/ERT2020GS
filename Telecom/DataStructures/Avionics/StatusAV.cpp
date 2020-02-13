//
// Created by stephanie on 13/02/20.
//

#include "StatusAV.h"

void StatusAV::write(Packet &packet) {
    packet.write(id);


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
              << "status enum: " <<  status << std::endl
              << "value: " << value  << std::endl;
}

std::string StatusAV::log() const {
    return Data::log();
}

void StatusAV::updateTx(std::shared_ptr<Connector> connector) {
    Data::updateTx(connector);
}

void StatusAV::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::T_ACCELEROMETER_X, accelerometer.x);

}
