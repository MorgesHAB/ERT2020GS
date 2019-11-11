/*!
 * \file Data.h
 *
 * \brief Data module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#ifndef Data_H
#define Data_H

#include "Packet.h"

// Abstract SuperClass
// Requirements methods for communicate a data via the protocol
class Data {
public:
    virtual void write(Packet& packet) = 0;
    virtual void parse(Packet& packet) = 0;
    virtual void update() = 0;
    virtual void print() const = 0;
    virtual ~Data() = default;
};


#endif //Data_H
