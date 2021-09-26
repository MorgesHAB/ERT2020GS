#ifndef ERT2020GS_TVCSTATUSVALUE_H
#define ERT2020GS_TVCSTATUSVALUE_H

#include <string>

namespace tvc_status {
    enum Value{
        IDLE = 0,
        BOOT,
        COMPUTE,
        SHUTDOWN,
        ABORT,
        ERROR
    };

    const int nb_status = 6;

    const std::string status_name[nb_status] = {
        "IDLE",
        "BOOT",
        "COMPUTE",
        "SHUTDOWN",
        "ABORT",
        "RECOVER"
    };
}

#endif //ERT2020GS_TVCSTATUSVALUE_H
