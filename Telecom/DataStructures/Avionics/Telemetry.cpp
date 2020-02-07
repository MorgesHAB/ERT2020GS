/*!
 * \file Telemetry.cpp
 *
 * \brief Telemetry module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.02.2020	
 */

#include "Telemetry.h"

void Telemetry::write(Packet &packet) {
    packet.write(accelerometer);
    packet.write(euler);
    packet.write(temperature);
    packet.write(pressure);
    packet.write(speed);
}

void Telemetry::parse(Packet &packet) {
    packet.parse(accelerometer);
    packet.parse(euler);
    packet.parse(temperature);
    packet.parse(pressure);
    packet.parse(speed);
}

void Telemetry::print() const {
    std::cout << "Accelerometer: " << accelerometer << " Euler: " << euler
              << " Temperature: " << temperature << " Pressure: " << pressure
              << " Speed: " << speed << std::endl;
}

void Telemetry::updateTx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::T_ACCELEROMETER, accelerometer);
    connector->setData(ui_interface::T_EULER, euler);
    connector->setData(ui_interface::T_TEMPERATURE, temperature);
    connector->setData(ui_interface::T_PRESSURE, pressure);
    connector->setData(ui_interface::T_SPEED, speed);
}

void Telemetry::updateRx(std::shared_ptr<Connector> connector) {
    Data::updateRx(connector);
}
