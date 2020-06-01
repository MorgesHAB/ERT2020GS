#include "utilities.h"
#include <string>
#include <ctime>

std::string utilities::datetime_short()
    {
        time_t timestamp(std::time(nullptr));
        char tbuffer[32];
        struct tm * tptr = std::localtime(&timestamp);
        std::strftime(tbuffer, 32, "D%m%d-T%H%M%S", tptr);
        return tbuffer;
    }
std::string utilities::datetime_long() {
        time_t timestamp(std::time(nullptr));
        char tbuffer[32];
        struct tm * tptr = std::localtime(&timestamp);
        std::strftime(tbuffer, 32, "%d %h  %H:%M:%S", tptr);
        return tbuffer;
}

std::string utilities::time() {
    time_t timestamp(std::time(nullptr));
    char tbuffer[32];
    struct tm * tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 32, "%H:%M:%S", tptr);
    return tbuffer;
}
