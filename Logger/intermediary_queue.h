#ifndef INTERMEDIARY_QUEUE_H
#define INTERMEDIARY_QUEUE_H
#include <queue>
#include <thread>
#include <mutex>
#include <string>

//This queue implementation may contain unnecessary locks, but still we think it's the safest way

class Intermediary_Queue
{
public:
    void push(const std::string& value);

    std::string front(); //consumer must ask for the size before this

    std::string pop_front();

    void pop();

    size_t size();


private:
    std::queue<std::string> m_queque;
    mutable std::mutex m_mutex;
};
#endif // INTERMEDIARY_QUEUE_H
