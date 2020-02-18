/*!
 * \file Logger.h
 *
 * \brief Logger module interface
 *
 * \author      KESKE Cem - EPFL EL BA3
 * \date        20.12.2019
 */


#define DEBUG

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


class Logger {
public:
    Logger(std::string filename = "");

    void log(Loggable* data);

private:
    std::string time_str();
    Double_buffer buffer;
};


#endif // LOGGER_H
