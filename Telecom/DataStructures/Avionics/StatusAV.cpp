//
// Created by stephanie on 13/02/20.
//

#include <iomanip>
#include "StatusAV.h"
#include <Avionics/StateValues.h>

void StatusAV::write(Packet &packet) {
    packet.write(id);
    packet.write(value);
    packet.write(status);
}

void StatusAV::parse(Packet &packet) {
    packet.parse(id);
    packet.parse(value);
    packet.parse(status);
}

void StatusAV::print() const {
    std::cout << std::setprecision(10);
    std::cout << "----- AV STATUS DATA --------------" << std::endl;
    std::cout << "id: " << id << std::endl
              << "value: " << value  << std::endl
              << "status: " <<  avionic::getAVStateName(status) << std::endl;
}

std::string StatusAV::log() const {
    return std::move("AVState" + SEPARATOR +
                     avionic::getAVStateName(status) + SEPARATOR +
                     std::to_string(value) + SEPARATOR);
}

bool StatusAV::updateTx(std::shared_ptr<Connector> connector) {
    status = rand() % 9;
    return true;
}

bool StatusAV::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::STATUS_AV_ID, id);
    connector->setData(ui_interface::STATUS_AV_VALUE, value);
    connector->setData(ui_interface::STATUS_AV_STATE, status);
    // Store AV Status
    using namespace avionic;
    switch (status) {
        case SLEEP: connector->setData(ui_interface::SLEEP_REACHED, true);
            break;
        case CALIBRATION: connector->setData(ui_interface::CALIBRATION_REACHED, true);
            break;
        case IDLE: connector->setData(ui_interface::IDLE_REACHED, true);
            break;
        case LIFTOFF: connector->setData(ui_interface::LIFTOFF_REACHED, true);
            break;
        case COAST: connector->setData(ui_interface::COAST_REACHED, true);
            break;
        case PRIMARY_EVENT: connector->setData(ui_interface::PRIMARY_EVENT_REACHED, true);
            break;
        case SECONDARY_EVENT: connector->setData(ui_interface::SECONDARY_EVENT_REACHED, true);
            break;
        case TOUCH_DOWN: connector->setData(ui_interface::TOUCH_DOWN_REACHED, true);
            break;
    }
    return true;
}
