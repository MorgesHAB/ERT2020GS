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
    virtual ~Xbee();

    void send(Packet *packet);
    bool receive(Packet *packet);
    bool receive(DataHandler &dataHandler);
    void mainRoutine(DataHandler &dataHandler);
    //int getRSSI();

private:
    serial::Serial serialPort;
};


#endif //XBee_H
