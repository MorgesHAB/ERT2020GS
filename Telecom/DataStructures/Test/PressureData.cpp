/*!
 * \file PressureData.cpp
 *
 * \brief PressureData module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#include <ctime>
#include "PressureData.h"

PressureData::PressureData() : pressure(0) {
    srand(time(0)); // for simulation random
}


void PressureData::write(Packet &packet) {
    packet.write(pressure);
}

void PressureData::parse(Packet &packet) {
    packet.parse(pressure);
}

void PressureData::print() const {
    std::cout << "Pressure Data : " << pressure << " hPa" << std::endl;
}

void PressureData::updateTx(std::shared_ptr<Connector> connector) {
    pressure = 850 + ((float) rand() / RAND_MAX) * 300;
}

void PressureData::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::DataType ::PRESSURE_DATA, pressure);
}
