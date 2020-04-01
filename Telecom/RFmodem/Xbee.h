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
#include <RFmodem.h>


class Xbee : public RFmodem {
public:
    Xbee(std::string port);
    virtual ~Xbee();

    void send(Packet *packet) override ;
    bool receive(Packet *packet);
    bool receive(DataHandler &dataHandler) override;

    int getRSSI() override;
    bool isOpen() override;

private:
    serial::Serial serialPort;
};


#endif //XBee_H
