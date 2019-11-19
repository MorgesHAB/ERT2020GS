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

enum PacketID {
    GPSID, PAYLOAD, AVIONICS, PROPULSION,
    NBR_OF_TYPE = 4
};

class DataHandler {
public:
    DataHandler();
    virtual ~DataHandler();

    void update(PacketID type);
    void parse(PacketID type);
    void print(PacketID type) const;
    Packet &getPacket(PacketID type);

private:
    std::vector<Datagram*> dataHandler;
};


#endif //DataHandler_H
