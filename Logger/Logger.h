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
#include "double_buffer.h"
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

    virtual void log(Loggable* data);

    static size_t total_logger_count();

    virtual ~Logger() = default;

protected:

    Double_buffer buffer;
};


#endif // LOGGER_H
