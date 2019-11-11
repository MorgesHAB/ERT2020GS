/*!
 * \file PressureData.cpp
 *
 * \brief PressureData module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#include "PressureData.h"

void PressureData::write(Packet &packet) {
    packet.write(pressure);
}

void PressureData::parse(Packet &packet) {
    packet.parse(pressure);
}

void PressureData::update() {
    pressure = 850 + ((float) rand()/ RAND_MAX) * 300;
}

void PressureData::print() const {
    std::cout << "Pressure Data : " << pressure << " hPa" << std::endl;
}