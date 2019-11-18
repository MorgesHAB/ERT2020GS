/*!
 * \file DataHandler.h
 *
 * \brief DataHandler module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019	
 */

#ifndef DataHandler_H
#define DataHandler_H


#include <vector>
#include "Datagram.h"

enum PacketType {
    GPS, PAYLOAD, AVIONICS, PROPULSION,
    NBR_OF_TYPE = 4
};

class DataHandler {
public:
    DataHandler();
    virtual ~DataHandler();

    void update(PacketType type);
    void parse(PacketType type);
    void print(PacketType type) const;
    Packet &getPacket(PacketType type);

private:
    std::vector<Datagram*> dataHandler;
};


#endif //DataHandler_H
