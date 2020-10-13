//
// Created by cem on 13/10/2020.
//

#include "PPCommand.h"
#include "PPCommands.h"
#include <ProtocolDefine.h>
#include <connector.h>


void PPCommand::write(Packet &packet) {
    packet.write(command);
}

void PPCommand::parse(Packet &packet) {
    packet.parse(command);
}

void PPCommand::print() const {
    using namespace pp;
    switch (command) {
        case NO_COMMAND : std::cout << "NO COMMAND "; break;
        case START_VALVE_OPERATION: std::cout << "START_VALVE_OPERATION "; break;
        case START_FUELING: std::cout << "START_FUELING "; break;
        case STOP_FUELING: std::cout << "STOP_FUELING "; break;
        case START_HOMING: std::cout << "START_HOMING "; break;
        case ABORT: std::cout << "ABORT "; break;
        default: break;
    }
    std::cout << " command request" << std::endl;
}

bool PPCommand::updateTx(std::shared_ptr<Connector> connector) {
    command = connector->eatData<pp::CommandValue>(ui_interface::PP_COMMAND, pp::NO_COMMAND);
    return (command!=pp::NO_COMMAND);
}

bool PPCommand::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::PP_COMMAND, command);
    return true;
}

std::string PPCommand::log() const {
    return "PP command" + SEPARATOR + std::to_string((int)command);
}
