/*!
 * \file RFmodem.h
 *
 * \brief RFmodem module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        23.12.2019	
 */

#ifndef RFmodem_H
#define RFmodem_H

#include <Packet.h>
#include <DataHandler.h>

// Superclass for a RF transceiver

class RFmodem {
public:

    virtual void send(Packet *packet) = 0;
    virtual bool receive(DataHandler &dataHandler) = 0;
    virtual int getRSSI() { return 0; }
    virtual bool isOpen() { return true; }


    virtual ~RFmodem() = default;
};


#endif //RFmodem_H
