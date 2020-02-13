//
// Created by stephanie on 13/02/20.
//

#include <stdint-gcc.h>

#ifndef ERT2020GS_STATEVALUES_H
#define ERT2020GS_STATEVALUES_H

#endif //ERT2020GS_STATEVALUES_H

enum StateValues {
    CALIBRATION,
    IDLE,
    LIFTOFF,
    COAST,
    PRIMARY_EVENT,
    SECONDARY_EVENT,
    TOUCH_DOWN
};

//For GUI
static std::string getStateName(uint8_t state) {
    switch (state) {
        case CALIBRATION: return "CALIBRATION";
        case IDLE: return "IDLE";
        case LIFTOFF: return "LIFTOFF";
        case COAST: return "COAST";
        case PRIMARY_EVENT: return "PRIMARY EVENT";
        case SECONDARY_EVENT: return "SECONDARY EVENT";
        case TOUCH_DOWN: return "TOUCH DOWN";
        default: return "Unknown";
    }
}