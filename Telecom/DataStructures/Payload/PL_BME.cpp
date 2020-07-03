/*!
 * \file PL_BME.cpp
 *
 * \brief PL_BME module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.07.2020	
 */

#include "PL_BME.h"

void PL_BME::write(Packet &packet) {
    packet.write(temperature);
    packet.write(pressure);
    packet.write(humidity);
    packet.write(altitude);
}

void PL_BME::parse(Packet &packet) {
    packet.parse(temperature);
    packet.parse(pressure);
    packet.parse(humidity);
    packet.parse(altitude);
}

void PL_BME::print() const {
    std::cout << " Temperature: " << temperature << " Pressure: " << pressure
              << " Humidity: " << humidity
              << " Altitude : " << altitude << std::endl;
}

std::string PL_BME::log() const {
    return std::move("BME PAYLOAD" + SEPARATOR +
                     std::to_string(temperature) + SEPARATOR +
                     std::to_string(pressure) + SEPARATOR +
                     std::to_string(humidity) + SEPARATOR +
                     std::to_string(altitude) + SEPARATOR);
}

bool PL_BME::updateRx(std::shared_ptr<Connector> connector) {
    // give to GUI
    connector->setData(ui_interface::PL_BME_ALTITUDE, altitude);
    connector->setData(ui_interface::PL_BME_TEMPERATURE, temperature);
    connector->setData(ui_interface::PL_BME_PRESSURE, pressure);
    connector->setData(ui_interface::PL_BME_HUMIDITY, humidity);
    return true;
}
