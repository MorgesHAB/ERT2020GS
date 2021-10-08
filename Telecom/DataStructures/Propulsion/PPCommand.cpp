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
        case IGNITION : std::cout << "IGNITION"; break;
        case ARM: std::cout << "ARM"; break;
        case DISARM: std::cout << "DISARM"; break;
        case OPEN_VENTING: std::cout << "OPEN VENTING"; break;
        case CLOSE_VENTING: std::cout << "CLOSE VENTING"; break;
        case START_CALIBRATION: std::cout << "START CALIBRATION"; break;
        case RECOVER: std::cout << "RECOVER"; break;
        case ABORT: std::cout << "ABORT "; break;
        default: break;
    }
    std::cout << " command request" << std::endl;
}

bool PPCommand::updateTx(std::shared_ptr<Connector> connector) {
    command = connector->eatData<pp::CommandValue>(ui_interface::PP_COMMAND, pp::NO_COMMAND);

    bool shouldPing = connector->getData<unsigned int>(ui_interface::PP_REPLY_PING) >= 5;
    if (shouldPing) {
        connector->eatData<unsigned int>(ui_interface::PP_REPLY_PING, 0);
    }
    return (command!=pp::NO_COMMAND || shouldPing);
}

bool PPCommand::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::PP_COMMAND, command);
    return true;
}

std::string PPCommand::log() const {
    return "PP command" + SEPARATOR + std::to_string((int)command);
}
