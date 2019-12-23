#include "intermediary_queue.h"


void Intermediary_Queue::push(const std::string& value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queque.push(value);
}

void Intermediary_Queue::pop()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_queque.pop();
}

size_t Intermediary_Queue::size()
{
    // std::lock_guard<std::mutex> lock(m_mutex);
    return m_queque.size();
}

std::string Intermediary_Queue::front()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_queque.front();
}

std::string Intermediary_Queue::pop_front()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::string tmp(m_queque.front());
    m_queque.pop();
    return tmp;
}
