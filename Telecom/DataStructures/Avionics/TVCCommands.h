#ifndef ERT2020GS_TVCCOMMANDS_H
#define ERT2020GS_TVCCOMMANDS_H

#include <string>

namespace tvc_commands {
    enum CommandValue{
        NO_COMMAND = 0,
        BOOT,
        SHUTDOWN,
        ABORT,
        RECOVER
    };

    const int nb_status = 10;
    const std::string status_value[nb_status] = {
        "NO COMMAND",
        "BOOT",
        "SHUTDOWN",
        "ABORT",
        "RECOVER"
    };
}

#endif //ERT2020GS_TVCCOMMANDS_H
