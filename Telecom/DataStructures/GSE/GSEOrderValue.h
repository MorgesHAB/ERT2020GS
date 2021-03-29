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
        MAIN_DISCONNECT_ON,
        MAIN_DISCONNECT_OFF,
        SECONDARY_DISCONNECT_ON,
        SECONDARY_DISCONNECT_OFF,
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
            case MAIN_DISCONNECT_ON:
                return "MAIN DISCONNECT ON";
            case MAIN_DISCONNECT_OFF:
                return "MAIN DISCONNECT OFF";
            case SECONDARY_DISCONNECT_ON:
                return "SECONDARY DISCONNECT ON";
            case SECONDARY_DISCONNECT_OFF:
                return "SECONDARY DISCONNECT OFF";
            case CLOSE_PURGE:
                return "CLOSE PURGE VALVE";
            default:
                return "Unknown";
        }
    }
}

#endif //ERT2020GS_GSEORDERS_H
