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
# define LOGGER_H
# include "Loggable.h"
# include "Logger_buffer.h"
#include "double_buffer.h"
# include "../RF-UI-Interface/connector.h"
# include "../RF-UI-Interface/ProtocolDefine.h"
# include <stdlib.h>
# include <unordered_map>
# include <thread>
# include <array>
# include <iostream>
# include <fstream>
# include <memory>

namespace Logger {

enum Source{RECEIVER, GUI, SOME_SOURCE, SOME_OTHER_SOURCE, size};

std::array<Double_buffer, Source::size> buffers;

    void log(const Loggable & data, Source src){

        buffers[src].add(data.log_description());
    }
}


#endif // LOGGER_H

