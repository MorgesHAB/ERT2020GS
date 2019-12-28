#include "intermediary_queue.h"
#include <iostream>

void Intermediary_Queue::push(const std::string& value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.push(value);
}

void Intermediary_Queue::pop()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queue.pop();
}

size_t Intermediary_Queue::size()
{
    // std::lock_guard<std::mutex> lock(m_mutex);
    return m_queue.size();
}

std::string Intermediary_Queue::front()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    if(m_queue.empty()){
        std::cerr << "Reached the front element with size = 0 !! (undefined behaviour)" << std::endl;
    }
    return m_queue.front();
}

std::string Intermediary_Queue::pop_front()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string tmp(m_queue.front());
    m_queue.pop();
    return tmp;
}
