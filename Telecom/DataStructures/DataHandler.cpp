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
    dataPacket.restart();
    for (auto &data : dataHandler) {
        data->update();
        data->write(dataPacket);
    }
}

void DataHandler::parse() {
    for (auto &data : dataHandler) data->parse(dataPacket);
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

DataHandler::~DataHandler() {
    for (auto &data : dataHandler) delete data;
}

const std::vector<Data *> &DataHandler::getDataHandler() const {
    return dataHandler;
}
