//
// Created by cem on 13/10/2020.
//

#ifndef ERT2020GS_PPCOMMANDS_H
#define ERT2020GS_PPCOMMANDS_H

#include <string>

namespace pp {
    enum CommandValue{
        NO_COMMAND = 0,
        IGNITION,
        ARM,
        DISARM,
        OPEN_VENTING,
        CLOSE_VENTING,
        START_CALIBRATION,
        RECOVER,
        ABORT,
    };

    const int nb_status = 10;
    const std::string status_value[nb_status] = {
        "IDLE",
        "CALIBRATION",
        "ARMED",
        "COUNTDOWN",
        "IGNITION",
        "THRUST",
        "SHUTDOWN",
        "GLIDE",
        "ABORT",
        "ERROR" 
    };
}

#endif //ERT2020GS_PPCOMMANDS_H
