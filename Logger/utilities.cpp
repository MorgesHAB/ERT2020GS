#include "utilities.h"
#include <string>
#include <ctime>

std::string utilities::time_short()
    {
        time_t timestamp(std::time(nullptr));
        char tbuffer[32];
        struct tm * tptr = std::localtime(&timestamp);
        std::strftime(tbuffer, 32, "D%m%e-T%H%M%S", tptr);
        return tbuffer;
    }
std::string utilities::time_long() {
        time_t timestamp(std::time(nullptr));
        char tbuffer[32];
        struct tm * tptr = std::localtime(&timestamp);
        std::strftime(tbuffer, 32, "%m/%e %H:%M:%S", tptr);
        return tbuffer;
}
