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
    GPSID, PAYLOAD, AVIONICS, PROPULSION, IMAGE,       // <-- add new type here
    NBR_OF_TYPE  // <-- size of the vector
};

class DataHandler {
public:
    DataHandler();
    virtual ~DataHandler();

    void update(PacketID type);
    void parse(PacketID type);
    void print(PacketID type) const;
    Packet &getPacket(PacketID type);
    const std::vector<Data*> &getDatagram(PacketID type);
    void setPacket(Packet &packet);

    void printLastRxPacket() const;

    PacketID getLastRxID() const;

private:
    std::vector<Datagram*> dataHandler;
    PacketID lastRxID;
};


#endif //DataHandler_H
