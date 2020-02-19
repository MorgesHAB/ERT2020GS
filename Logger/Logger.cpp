#include "Logger.h"
#include "../UI/utilities.h"

static std::atomic<size_t> logger_ctr(0);

Logger::Logger(std::string filename) : buffer(filename + utilities::time_short() + "-ID" + std::to_string(++logger_ctr) +  ".log") {}

void Logger::log(Loggable* data)
{
    buffer.add(data->log_description());
}

