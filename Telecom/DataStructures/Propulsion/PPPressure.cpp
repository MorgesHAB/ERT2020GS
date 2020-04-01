/*!
 * \file PressureData.cpp
 *
 * \brief PressureData module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#include <ctime>
#include "PPPressure.h"

PPPressure::PPPressure() : pressure(0) {
    srand(time(0)); // for simulation random
}


void PPPressure::write(Packet &packet) {
    packet.write(pressure);
}

void PPPressure::parse(Packet &packet) {
    packet.parse(pressure);
}

void PPPressure::print() const {
    std::cout << "Pressure Data : " << pressure << " hPa" << std::endl;
}

bool PPPressure::updateTx(std::shared_ptr<Connector> connector) {
    pressure = 850 + ((float) rand() / RAND_MAX) * 300;
    return true;
}

bool PPPressure::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::DataType ::PP_PRESSURE, pressure);
    return true;
}
