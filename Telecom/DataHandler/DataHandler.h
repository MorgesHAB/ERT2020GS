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
#include <Datagram.h>

// TODO namespace
enum PacketID {   // Don't forget to modify header::print() when adding new packet type
    GPSID, PAYLOAD, AVIONICS, PROPULSION, IMAGE, XBEE_TEST,
    PROPULSION_TEST, IGNITION_ANSWER,        // <-- add new type here

    NBR_OF_TYPE  // <-- size of the array - keep at the end
};

class DataHandler {
public:
    DataHandler(std::shared_ptr<Connector> connector);
    virtual ~DataHandler();

    void updateTx(PacketID type);
    void updateRx(Packet* packet);

    void print(PacketID type) const;

    Packet* getPacket(PacketID type);

    void printLastRxPacket() const;

private:
    std::shared_ptr<Connector> connector;

    std::vector<Datagram*> dataHandler;
    PacketID lastRxID;
    size_t packetRxCounter;
    size_t ignorePacketRxCounter;
};


#endif //DataHandler_H
