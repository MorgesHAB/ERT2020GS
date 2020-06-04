/*!
 * \file Logger.h
 *
 * \brief Logger module interface
 *
 * \author      KESKE Cem - EPFL EL BA3
 * \date        20.12.2019
 */



#ifndef LOGGER_H
#define LOGGER_H

#include "Loggable.h"
#include "Logger_buffer.h"
#include "Double_buffer.h"
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include <unordered_map>
#include <thread>
#include <array>
#include <iostream>
#include <fstream>


/**
 * @brief The Logger class This class can be used to log instances of Loggable. Each loggable object will be associated to a new .log file.
 */
class Logger {
public:
    Logger(std::string filename = "");

    /**
     * @brief Logger
     * @param buffer_size The size of the buffer. 10^6 packets/sec tested succesfully 100% with a size of 1000.
     * @param filename The beginning of the name of the .log file.
     */
    Logger(size_t buffer_size, std::string filename = "");

    virtual void log(Loggable* data);

    static size_t total_logger_count();

    virtual ~Logger() = default;

protected:

    Double_buffer buffer;
};


#endif // LOGGER_H
