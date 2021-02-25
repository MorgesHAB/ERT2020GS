//
// Created by cem on 13/10/2020.
//

#include "GSEPing.h"

static constexpr uint8_t ECHO_VALUE = 0xCA;

void GSEPing::write(Packet& packet){
    packet.write(ECHO_VALUE);
}
void GSEPing::parse(Packet& packet){
    uint8_t val;
    packet.parse(val);
}

void GSEPing::print() const{
    std::cout << "GSE Echo Packet received" << std::endl;

}
std::string GSEPing::log() const {
    return std::move("GSE_PING packet");
}


bool GSEPing::updateTx(std::shared_ptr<Connector> connector){
    return(connector->eatData<bool>(ui_interface::GSE_PING, false));
}
bool GSEPing::updateRx(std::shared_ptr<Connector> connector){
    connector->setData(ui_interface::GSE_PING_ACK, true);
    return true;
}