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
    packet.write(accelerometer.x);
    packet.write(accelerometer.y);
    packet.write(accelerometer.z);
    packet.write(euler.x);
    packet.write(euler.y);
    packet.write(euler.z);
    packet.write(temperature);
    packet.write(pressure);
    packet.write(speed);
    packet.write(altitude);
}

void Telemetry::parse(Packet &packet) {
    packet.parse(accelerometer.x);
    packet.parse(accelerometer.y);
    packet.parse(accelerometer.z);
    packet.parse(euler.x);
    packet.parse(euler.y);
    packet.parse(euler.z);
    packet.parse(temperature);
    packet.parse(pressure);
    packet.parse(speed);
    packet.parse(altitude);
}

void Telemetry::print() const {
    std::cout << "Accelerometer: (" << accelerometer.x << ", " << accelerometer.y
              << ", " << accelerometer.z << ") Euler: (" << euler.x << ", " << euler.y
              << ", " << euler.z << ") "
              << " Temperature: " << temperature << " Pressure: " << pressure
              << " Speed: " << speed
              << " Altitude : " << altitude << std::endl;
}

bool Telemetry::updateTx(std::shared_ptr<Connector> connector) {
    accelerometer.x = -2 + ((float) rand()/ RAND_MAX) * 6;
    accelerometer.y = -3 + ((float) rand()/ RAND_MAX) * 3;
    accelerometer.z = -5 + ((float) rand()/ RAND_MAX) * 20;
    euler.x = -5 + ((float) rand()/ RAND_MAX) * 6;
    euler.y = -3 + ((float) rand()/ RAND_MAX) * 16;
    euler.z = -1 + ((float) rand()/ RAND_MAX) * 5;
    temperature =  12 + ((float) rand()/ RAND_MAX) * 20;
    pressure =  100 + ((float) rand()/ RAND_MAX) * 50;
    speed =  3 + ((float) rand()/ RAND_MAX) * 10;
    altitude =  500 + ((float) rand()/ RAND_MAX) * 1000;
    return true;
}

bool Telemetry::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::T_ACCELEROMETER_X, accelerometer.x);
    connector->setData(ui_interface::T_ACCELEROMETER_Y, accelerometer.y);
    connector->setData(ui_interface::T_ACCELEROMETER_Z, accelerometer.z);
    connector->setData(ui_interface::T_EULER_X, euler.x);
    connector->setData(ui_interface::T_EULER_Y, euler.y);
    connector->setData(ui_interface::T_EULER_Z, euler.z);
    connector->setData(ui_interface::T_TEMPERATURE, temperature);
    connector->setData(ui_interface::T_PRESSURE, pressure);
    connector->setData(ui_interface::T_SPEED, speed);
    connector->setData(ui_interface::T_ALTITUDE, altitude);
    if (altitude > connector->getData<float>(ui_interface::ALTITUDE_MAX))
        connector->setData(ui_interface::ALTITUDE_MAX, altitude);
    return true;
}

std::string Telemetry::log() const {
    return std::move("Telemetry" + SEPARATOR +
                     std::to_string(altitude) + SEPARATOR +
                     std::to_string(speed) + SEPARATOR +
                     std::to_string(temperature) + SEPARATOR +
                     std::to_string(pressure) + SEPARATOR +
                     std::to_string(accelerometer.x) + SEPARATOR +
                     std::to_string(accelerometer.y) + SEPARATOR +
                     std::to_string(accelerometer.z) + SEPARATOR +
                     std::to_string(euler.x) + SEPARATOR +
                     std::to_string(euler.y) + SEPARATOR +
                     std::to_string(euler.z) + SEPARATOR);
}