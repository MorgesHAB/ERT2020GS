#include "Logger.h"
#include "utilities.h"

static std::atomic<size_t> logger_ctr(0);

Logger::Logger(std::string filename) : buffer(filename + utilities::datetime_short() + "-ID"
                                              + std::to_string(++logger_ctr) + ".log"){ }

Logger::Logger(size_t buffer_size, std::string filename) :
    buffer(buffer_size, filename + utilities::datetime_short() + "-ID"
           + std::to_string(++logger_ctr) + ".log"){ }


void Logger::log(Loggable * data)
{
    buffer.add(data->log_description());
}

size_t Logger::total_logger_count()
{
    return logger_ctr;
}
