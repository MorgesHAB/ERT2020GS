//
// Created by stephanie on 13/02/20.
//

#include "GSESensors.h"

void GSESensors::write(Packet &packet) {
    packet.write(hose_pressure);
    packet.write(hose_temp);
    packet.write(hose_status);
    packet.write(motor_speed);
    packet.write(tank_weight);
}

void GSESensors::parse(Packet &packet) {
    packet.parse(hose_pressure);
    packet.parse(hose_temp);
    packet.parse(hose_status);
    packet.parse(motor_speed);
    packet.parse(tank_weight);
}

void GSESensors::print() const {

}

std::string GSESensors::log() const {
    return Data::log();
}

bool GSESensors::updateTx(std::shared_ptr<Connector> connector) {
    return true;
}

bool GSESensors::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::GSE_HOSE_PRESSURE, hose_pressure);
    connector->setData(ui_interface::GSE_HOSE_TEMP, hose_temp);
    connector->setData(ui_interface::GSE_HOSE_STATUS, hose_status);
    connector->setData(ui_interface::GSE_MOTOR_SPEED, motor_speed);
    connector->setData(ui_interface::GSE_TANK_WEIGHT, tank_weight);
    return true;
}
