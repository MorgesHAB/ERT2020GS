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

#include <Packet.h>
#include <memory>
#include <connector.h>
#include <Loggable.h>

// Abstract SuperClass
// Requirements methods for communicate a data via the protocol
class Data {
public:
    virtual void write(Packet& packet) = 0;
    virtual void parse(Packet& packet) = 0;

    virtual void print() const = 0;
    virtual std::string log() const { return ""; }

    virtual bool updateTx(std::shared_ptr<Connector> connector) { return true; }
    virtual bool updateRx(std::shared_ptr<Connector> connector) { return true; }

    virtual ~Data() = default;
};


#endif //Data_H
