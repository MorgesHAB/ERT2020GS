#include "logger.h"
#include <chrono>

const uint64_t Logger::SLEEP_TIME(2); // in milliseconds

inline std::string beautify(std::string log_string) // force copy !! this is very important to avoid data races
{
    log_string += " logged";
    return log_string;
}

Logger::Logger(const std::string & log_file, std::shared_ptr<Connector> connector) : output_file_(log_file), connector_(
        connector), current_index_(0)
{
    if (!output_file_) {
        std::cout << "Log file \"" << log_file
                  << "\" can't be opened !! Data will be lost !!" << std::endl;
    }
}

Logger::~Logger()
{
    output_file_.close();
}

void Logger::log(std::shared_ptr<Loggable> data)
{
    bridge_.push(data->log_description());
}

void Logger::routine()
{
    #ifdef DEBUG
    std::cout << "In logger routine" << std::endl;
    #endif
    while (connector_->getData<bool>(ui_interface::RUNNING)) {
        if (bridge_.size() >= 1) {
            buffer_[current_index_] = beautify(bridge_.pop_front());
            current_index_++;
            #ifdef DEBUG
            std::cout << "Index is now : " < current_index_ << std::endl;
            #endif
        }
        if (current_index_ > buffer_size_) {
            for (size_t i(0); i < current_index_; i++) {
                output_file_ << buffer_[i];
            }
            #ifdef DEBUG
            std::cout << "Flushing, index is zero again." << std::endl;
            #endif
            current_index_ = 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    }
}
