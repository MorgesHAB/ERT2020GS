//
// Created by stephanie on 12/03/20.
//

#include "PLTemperature.h"

void PLTemperature::write(Packet &packet) {
    packet.write(temperature);
}

void PLTemperature::parse(Packet &packet) {
    packet.parse(temperature);
}

void PLTemperature::print() const {

}

std::string PLTemperature::log() const {
    return std::move("PL Temperature" + SEPARATOR +
                            std::to_string(temperature) + SEPARATOR);
}

bool PLTemperature::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::PL_TEMPERATURE, temperature);
    return true;
}

