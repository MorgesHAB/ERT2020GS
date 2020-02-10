#ifndef LOG_BUFFER_H
#define LOG_BUFFER_H

#include <string>
#include <mutex>
#include <vector>
#include <atomic>

class Log_buffer
{
public:
    Log_buffer(size_t size);
    void add(const std::string& value);
    void make_ready_to_fill();
    bool is_ready_to_fill();
    bool is_full();
    std::string & operator[](size_t); //Attention this does not lock mutex
private:
    std::atomic<bool> ready_;
    std::atomic<size_t> position_;
    const size_t defined_size_;
    std::vector<std::string> buffer_;
    mutable std::mutex m_mutex_;
};

#endif
