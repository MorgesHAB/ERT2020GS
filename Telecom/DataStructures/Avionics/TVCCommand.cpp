#include "TVCCommands.h"
#include "TVCCommand.h"
#include <ProtocolDefine.h>
#include <connector.h>


void TVCCommand::write(Packet &packet) {
    packet.write(command);
}

void TVCCommand::parse(Packet &packet) {
    packet.parse(command);
}

void TVCCommand::print() const {
    using namespace tvc_commands;
    switch (command) {
        case NO_COMMAND : std::cout << "NO COMMAND "; break;
        case BOOT: std::cout << "BOOT"; break;
        case SHUTDOWN: std::cout << "SHUTDOWN"; break;
        case RECOVER: std::cout << "RECOVER"; break;
        case ABORT: std::cout << "ABORT "; break;
        default: break;
    }
    std::cout << " command request" << std::endl;
}

bool TVCCommand::updateTx(std::shared_ptr<Connector> connector) {
    command = connector->eatData<tvc_commands::CommandValue>(ui_interface::TVC_COMMAND, tvc_commands::NO_COMMAND);
    return (command!=tvc_commands::NO_COMMAND);
}

bool TVCCommand::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::TVC_COMMAND, command);
    return true;
}

std::string TVCCommand::log() const {
    return "TVC command" + SEPARATOR + std::to_string((int)command);
}
