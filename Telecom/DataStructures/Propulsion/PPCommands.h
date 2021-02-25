//
// Created by cem on 13/10/2020.
//

#ifndef ERT2020GS_PPCOMMANDS_H
#define ERT2020GS_PPCOMMANDS_H

namespace pp {
    enum CommandValue{
        NO_COMMAND = 0,
        START_VALVE_OPERATION,
        START_FUELING,
        STOP_FUELING,
        START_HOMING,
        ABORT
    };
}

#endif //ERT2020GS_PPCOMMANDS_H
