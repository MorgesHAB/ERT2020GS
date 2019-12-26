#define DEBUG

#ifndef LOGGER_H
#define LOGGER_H
#include "loggable.h"
#include "intermediary_queue.h"
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include <array>
#include <iostream>
#include <fstream>
#include <memory>

class Logger
{
public:

    Logger(const std::string & log_file, std::shared_ptr<Connector> connector);
    ~Logger();
    void log(std::shared_ptr<Loggable>);
    void routine();

private:


    static constexpr size_t buffer_size_ = 1000;
    static constexpr size_t safety_margin_ = 10;
    static const uint64_t SLEEP_TIME;


    Intermediary_Queue bridge_;

    std::array<std::string, buffer_size_ + safety_margin_> buffer_;
    std::ofstream output_file_;
    std::shared_ptr<Connector> connector_;
    uint32_t current_index_;
};

#endif // LOGGER_H
