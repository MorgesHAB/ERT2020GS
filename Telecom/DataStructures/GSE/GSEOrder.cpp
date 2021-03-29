//
// Created by stephanie on 13/02/20.
//

#include "GSEOrder.h"

void GSEOrder::write(Packet &packet) {
    packet.write(order);
}

void GSEOrder::parse(Packet &packet) {
    packet.parse(order);
}

void GSEOrder::print() const {
    using namespace gse;
    switch (order) {
        case OPEN_FILLING:
            std::cout << "OPEN FILLING VALVE order request" << std::endl;
            break;
        case CLOSE_FILLING:
            std::cout << "CLOSE FILLING VALVE order request" << std::endl;
            break;
        case OPEN_PURGE:
            std::cout << "OPEN PURGE VALVE order request" << std::endl;
            break;
        case MAIN_DISCONNECT_ON:
            std::cout << "MAIN DISCONNECT ON requested" << std::endl;
            break;
        case MAIN_DISCONNECT_OFF:
            std::cout << "MAIN DISCONNECT OFF requested" << std::endl;
            break;
        case CLOSE_PURGE:
            std::cout << "CLOSE PURGE VALVE order request" << std::endl;
            break;
        default:
            break;
    }

}

bool GSEOrder::updateTx(std::shared_ptr<Connector> connector) {
    order = connector->eatData<gse::GSEOrderValue>(ui_interface::GSE_ORDER, gse::NO_ORDER);
    return (order!=gse::NO_ORDER);
}

bool GSEOrder::updateRx(std::shared_ptr<Connector> connector) {
    std::cout << "Order set" << std::endl;
    connector->setData(ui_interface::GSE_ORDER_ACK, order);
    return true;
}

std::string GSEOrder::log() const {
    return "GSE order" + SEPARATOR + std::to_string((int)order);
}

