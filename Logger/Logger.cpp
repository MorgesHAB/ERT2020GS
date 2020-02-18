#include "Logger.h"

static std::atomic<size_t> logger_ctr(0);

Logger::Logger(std::string filename) : buffer(filename + time_str() + "-ID" + std::to_string(++logger_ctr) +  ".log") {}

void Logger::log(const Loggable &data)
{
    buffer.add(data.log_description());
}

std::string Logger::time_str()
{
    time_t timestamp(std::time(nullptr));
    char tbuffer[32];
    struct tm * tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 32, "D%m%e-T%M%M%S", tptr);
    return tbuffer;
}
