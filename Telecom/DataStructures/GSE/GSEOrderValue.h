//
// Created by stephanie on 13/02/20.
//

#include <string>

#ifndef ERT2020GS_GSEORDERS_H
#define ERT2020GS_GSEORDERS_H

namespace gse {

    enum GSEOrderValue {
        NO_ORDER = 0,
        OPEN_FILLING, //GSE opens fill valve
        CLOSE_FILLING, //GSE closes fill valve
        OPEN_PURGE, //GSE opens purge valve
        CLOSE_PURGE, //GSE opens purge valve to decrease temp
        DISCONNECT_HOSE, //GSE activates motor and pulls hose
        SENSOR_VALUES_REQUEST, //connected or disconnected
        TOTAL_ORDER_COUNT
    };

    static std::string getOrderName(uint8_t order) {
        switch (order) {
            case OPEN_FILLING:
                return "OPEN FILLING VALVE";
            case CLOSE_FILLING:
                return "CLOSE FILLING VALVE";
            case OPEN_PURGE:
                return "OPEN PURGE VALVE";
            case DISCONNECT_HOSE:
                return "DISCONNECT HOSE";
            case CLOSE_PURGE:
                return "CLOSE PURGE VALVE";
            case SENSOR_VALUES_REQUEST:
                return "SENSOR VALUES REQUEST";
            default:
                return "Unknown";
        }
    }
}

#endif //ERT2020GS_GSEORDERS_H
