#include "Logger_buffer.h"
#include <iostream>


constexpr size_t DEFAULT_SIZE(1000);

Logger_buffer::Logger_buffer(size_t size) : size(size), ready_(true), position_(0), buffer_(size){ }

Logger_buffer::Logger_buffer() : size(DEFAULT_SIZE), ready_(true), position_(0), buffer_(DEFAULT_SIZE){ }

size_t Logger_buffer::position()
{
    return position_;
}

void Logger_buffer::add(const std::string &value)
{
    if (not ready_)
        std::cerr << "Trying to write into a buffer which is not ready, data will be overridden" << std::endl;
    buffer_[position_] = value;
    ++position_;
    if (position_ >= size) {
        ready_ = false;
    }
}

void Logger_buffer::make_ready_to_fill()
{
    ready_    = true;
    position_ = 0;
}

bool Logger_buffer::is_ready_to_fill() const
{
    return ready_;
}

bool Logger_buffer::is_full() const
{
    return !ready_;
}

std::string &Logger_buffer::operator [] (size_t index)
{
    if (index >= size)
        std::cerr << "INDEX OUT OF BOUNDS" << std::endl;
    return buffer_[index];
}

void Logger_buffer::display() const
{
    for (auto & el : buffer_)
        std::cout << el << std::endl;
}
