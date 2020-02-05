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
#include <PacketTypes.h>
#include <Datagram.h>

class DataHandler {
public:
    DataHandler(std::shared_ptr<Connector> connector);
    virtual ~DataHandler();

    void updateTx(packetType::PacketID type);
    bool updateRx(Packet* packet);

    void print(packetType::PacketID type) const;

    Packet* getPacket(packetType::PacketID type);

    void printLastRxPacket() const;
    void logLastRxPacket() const;

private:
    std::shared_ptr<Connector> connector;

    std::vector<Datagram*> dataHandler;
    packetType::PacketID lastRxID;
};


#endif //DataHandler_H
