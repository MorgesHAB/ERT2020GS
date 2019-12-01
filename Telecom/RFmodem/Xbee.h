/*!
 * \file XBee.h
 *
 * \brief XBee module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.11.2019	
 */

#ifndef XBee_H
#define XBee_H

#include <serial/serial.h>
#include <Packet.h>
#include <DataHandler.h>

class Xbee {
public:
    Xbee();

    void send(Packet &packet);
    bool receive(Packet &packet);
    void mainRoutine(DataHandler& dataHandler);
    //int getRSSI();
    virtual ~Xbee();

private:
    serial::Serial serialPort;
};


#endif //XBee_H
