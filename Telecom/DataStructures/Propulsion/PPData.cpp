//
// Created by cem on 13/10/2020.
//

#include "PPData.h"
void PPData::write(Packet &packet) {
    packet.write(pressure_1);
    packet.write(pressure_2);
    packet.write(temperature_1);
    packet.write(temperature_2);
    packet.write(temperature_3);
    packet.write(status);
    packet.write(motor_position);
}

void PPData::parse(Packet &packet) {
    packet.parse(pressure_1);
    packet.parse(pressure_2);
    packet.parse(temperature_1);
    packet.parse(temperature_2);
    packet.parse(temperature_3);
    packet.parse(status);
    packet.parse(motor_position);
}

void PPData::print() const {
    std::cout << "Pressure (1,2): (" << pressure_1 << ", " << pressure_2
              << ")" <<" \n Temperature (1,2,3): (" << temperature_1 << ", " << temperature_2
              << ", " << temperature_3 << ") "
              << " \n Status:" << status << "\n"
              << "Motor Pos: " << std::hex << motor_position << std::endl;
}

bool PPData::updateTx(std::shared_ptr <Connector> connector) {}

bool PPData::updateRx(std::shared_ptr <Connector> connector) {
    connector->setData(ui_interface::PP_PRESSURE_1, pressure_1);
    connector->setData(ui_interface::PP_PRESSURE_2, pressure_2);

    connector->setData(ui_interface::PP_TEMPERATURE_1, temperature_1);
    connector->setData(ui_interface::PP_TEMPERATURE_2, temperature_2);
    connector->setData(ui_interface::PP_TEMPERATURE_3, temperature_3);

    connector->setData(ui_interface::PP_STATUS, status);

    connector->setData(ui_interface::PP_MOTOR_POSITION, motor_position);
    connector->incrementData(ui_interface::PP_REPLY_PING);

    return true;
}

std::string PPData::log() const {
    return std::move("Propulsion" + SEPARATOR +
                    std::to_string(pressure_1) + SEPARATOR +
                    std::to_string(pressure_2) + SEPARATOR +
                    std::to_string(temperature_1) + SEPARATOR +
                    std::to_string(temperature_2) + SEPARATOR +
                    std::to_string(temperature_3) + SEPARATOR +
                    std::to_string(status) + SEPARATOR +
                    std::to_string(motor_position));
}
