/*!
 * \file PL_BNO.cpp
 *
 * \brief PL_BNO module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.07.2020	
 */

#include "PL_BNO.h"

void PL_BNO::write(Packet &packet) {
    packet.write(temperature);
    packet.write(orientationX);
    packet.write(orientationY);
    packet.write(orientationZ);
    packet.write(accelerationX);
    packet.write(accelerationY);
    packet.write(accelerationZ);
}

void PL_BNO::parse(Packet &packet) {
    packet.parse(temperature);
    packet.parse(orientationX);
    packet.parse(orientationY);
    packet.parse(orientationZ);
    packet.parse(accelerationX);
    packet.parse(accelerationY);
    packet.parse(accelerationZ);
}

void PL_BNO::print() const {
    std::cout << " Temperature: " << +temperature << " Orientation: (" << orientationX
              << "," << orientationY << "," << orientationZ << ")   " << " Accel: ("
              << accelerationX << "," << accelerationY << "," << accelerationZ
              << ")" << std::endl;
}

std::string PL_BNO::log() const {
    return std::move("BNO PAYLOAD" + SEPARATOR +
                     std::to_string(temperature) + SEPARATOR +
                     std::to_string(orientationX) + SEPARATOR +
                     std::to_string(orientationY) + SEPARATOR +
                     std::to_string(orientationZ) + SEPARATOR +
                     std::to_string(accelerationX) + SEPARATOR +
                     std::to_string(accelerationY) + SEPARATOR +
                     std::to_string(accelerationZ));
}

bool PL_BNO::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::PL_BNO_ACCELERATION_X, accelerationX);
    connector->setData(ui_interface::PL_BNO_ACCELERATION_Y, accelerationY);
    connector->setData(ui_interface::PL_BNO_ACCELERATION_Z, accelerationZ);
    connector->setData(ui_interface::PL_BNO_ORIENTATION_X, orientationX);
    connector->setData(ui_interface::PL_BNO_ORIENTATION_Y, orientationY);
    connector->setData(ui_interface::PL_BNO_ORIENTATION_Z, orientationZ);
    connector->setData(ui_interface::PL_BNO_TEMPERATURE, temperature);
    return Data::updateRx(connector);
}
