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
# include "../RF-UI-Interface/connector.h"
# include "../RF-UI-Interface/ProtocolDefine.h"
# include <stdlib.h>
# include <unordered_map>
# include <array>
# include <iostream>
# include <fstream>
# include <memory>

class Logger
{
public:


    static Logger& logger();


    /**
     * @brief log
     * @param data
     */
    static void log(std::shared_ptr<Loggable> data);

    /**
     * @brief thread_index
     * @return The index of the thread in the vector caller_threads_. Adds the thread
     * in the list and creates its buffers if the thread is not in the list.
     */
    size_t thread_index(std::thread::id);

private:

    Logger(const std::string & log_file, std::shared_ptr<Connector> connector);

    ~Logger();
    }


#endif // LOGGER_H

