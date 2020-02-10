#include "log_buffer.h"

#include <iostream>

Log_buffer::Log_buffer(size_t size) : position_(0), defined_size_(size), buffer_(size){ }

void Log_buffer::add(const std::string &value)
{
    if(not ready_)
        std::cerr << "Trying to write into a buffer which is not ready, data will be overridden" << std::endl;

    std::lock_guard<std::mutex> lock(m_mutex_);
    buffer_[position_] = value;
    ++position_;
    if (position_ >= defined_size_) {
        position_ = 0;
        ready_ = false;
    }
}

void Log_buffer::make_ready_to_fill()
{
    ready_ = true;
}

bool Log_buffer::is_ready_to_fill()
{
    return ready_;
}

bool Log_buffer::is_full()
{
    return !ready_;
}

