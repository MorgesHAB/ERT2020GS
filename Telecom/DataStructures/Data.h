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

/**
 * Abstract SuperClass, mother of all Data that will be transmit via RF
 * A Datagram is composed of all kind of Data that must inherits from this class
 */
class Data {
public:
    /**
     * The order is
     *  Tx :        1) updateTx     2) write
     *  Rx          1) parse        2) updateRx
     *  Warning : the write & parse functions must be symmetrical.
     *            This means that each variables that are written in the packet
     *            must be read in the same order.
     */
    /**
     * Write the specified attributes of a Data instance in a packet
     * @param packet    The packet where data will be written
     */
    virtual void write(Packet& packet) = 0;

    /**
     * Read the same specified attributes of a Data instance from a packet
     * @param packet    The packet from where data will be parsed
     */
    virtual void parse(Packet& packet) = 0;

    /**
     * Update the class attributes before transmitting data
     * @param connector     to exchange data with a GUI
     * @return              true if the packet can be send by a RF modem
     */
    virtual bool updateTx(std::shared_ptr<Connector> connector) { return true; }

    /**
     * Update the class attributes after receiving data
     * @param connector     to exchange data with a GUI
     * @return              true if Data can be processed   eg: logging, print
     */
    virtual bool updateRx(std::shared_ptr<Connector> connector) { return true; }

    /**
     * Print the Data attributes
     */
    virtual void print() const {};

    /**
     * Log the Data attributes
     * @return      The string to log
     */
    virtual std::string log() const { return ""; }

    virtual ~Data() = default;
};


#endif //Data_H
