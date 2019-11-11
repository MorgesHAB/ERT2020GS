/*!
 * \file DataHandler.cpp
 *
 * \brief DataHandler module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#include "DataHandler.h"

void DataHandler::update() {
    for (auto &data : dataHandler) {
        data->update();
        dataPacket.restart();
        data->write(dataPacket);
    }
}

void DataHandler::parse() {
    for (auto &data : dataHandler) {
        dataPacket.restart();
        data->parse(dataPacket);
    }
}

void DataHandler::print() const {
    for (auto &data : dataHandler) data->print();
}

Packet &DataHandler::getDataPacket() {
    return dataPacket;
}

void DataHandler::add(Data *data) {
    dataHandler.push_back(data);
}
