//
// Created by stephanie on 13/02/20.
//

#ifndef ERT2020GS_STATEVALUES_H
#define ERT2020GS_STATEVALUES_H

namespace avionic {

    enum StateValues {
        SLEEP,
        CALIBRATION,
        IDLE,
        FILLING,
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
            case FILLING: return "FILLING";
            case LIFTOFF: return "LIFTOFF";
            case COAST: return "COAST";
            case PRIMARY_EVENT: return "PRIMARY EVENT";
            case SECONDARY_EVENT: return "SECONDARY EVENT";
            case TOUCH_DOWN: return "TOUCH DOWN";
            default: return "Unknown";
        }
    }
} // namespace


#endif //ERT2020GS_STATEVALUES_H
