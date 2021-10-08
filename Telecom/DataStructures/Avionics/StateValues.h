//
// Created by stephanie on 13/02/20.
//

#ifndef ERT2020GS_STATEVALUES_H
#define ERT2020GS_STATEVALUES_H

#include <string>

namespace avionic {

    enum StateValues {
        SLEEP,
        CALIBRATION,
        IDLE,
        OPEN_FILL_VALVE,
        CLOSE_FILL_VALVE,
        OPEN_PURGE_VALVE,
        DISCONNECT_HOSE,
        LIFTOFF,
        COAST,
        PRIMARY_EVENT,
        SECONDARY_EVENT,
        TOUCH_DOWN
    };

    //For GUI
    static std::string getAVStateName(uint8_t state) {
        switch (state) {
            case SLEEP: return "SLEEP";
            case CALIBRATION: return "CALIBRATION";
            case IDLE: return "IDLE";
            case OPEN_FILL_VALVE: return "OPEN FILL VALVE";
            case CLOSE_FILL_VALVE: return "CLOSE FILL VALVE";
            case OPEN_PURGE_VALVE: return "OPEN PURGE VALVE";
            case DISCONNECT_HOSE: return "DISCONNECT HOSE";
            case LIFTOFF: return "LIFTOFF";
            case COAST: return "COAST";
            case PRIMARY_EVENT: return "1. EVENT";
            case SECONDARY_EVENT: return "2. EVENT";
            case TOUCH_DOWN: return "TOUCHDOWN";
            default: return "Unknown";
        }
    }
} // namespace


#endif //ERT2020GS_STATEVALUES_H
