//
// Created by stephanie on 13/02/20.
//

#include <stdint-gcc.h>
#include <string>

#ifndef ERT2020GS_GSEORDERS_H
#define ERT2020GS_GSEORDERS_H


enum GSEOrderValues {
    START_FILLING, //GSE opens fill valve
    STOP_FILLING, //GSE closes fill valve
    PURGE_HOSE, //GSE opens purge valve
    DISCONNECT_HOSE, //GSE activates motor and pulls hose
    OPEN_PURGE_VALVE, //GSE opens purge valve to decrease temp
    SENSOR_VALUES_REQUEST //connected or disconnected

};

static std::string getOrderName(uint8_t order) {
    switch (order) {
        case START_FILLING: return "START FILLING";
        case STOP_FILLING: return "STOP FILLING";
        case PURGE_HOSE: return "PURGE HOSE";
        case DISCONNECT_HOSE: return "DISCONNECT HOSE";
        case OPEN_PURGE_VALVE: return "OPEN PURGE VALVE";
        case SENSOR_VALUES_REQUEST: return "SENSOR VALUES REQUEST";
        default: return "Unknown";
    }
}

#endif //ERT2020GS_GSEORDERS_H
