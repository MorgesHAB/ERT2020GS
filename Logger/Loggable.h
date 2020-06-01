/*!
 * \file Loggable.h
 *
 * \brief Loggable module interface
 *
 * \author      KESKE Cem - EPFL EL BA3
 * \date        20.12.2019
 */

#ifndef LOGGABLE_H
#define LOGGABLE_H

#include <string>

static const std::string SEPARATOR = "\t";

/**
 * @brief The Loggable class An interface class for all the data which are loggable.
 */
class Loggable {
public:
    virtual std::string log_description() const = 0; //don't forget to move when returning for efficiency reasons
    virtual ~Loggable() = default;
};

#endif // LOGGABLE_H
