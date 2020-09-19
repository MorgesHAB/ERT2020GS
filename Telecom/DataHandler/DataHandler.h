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
#include <DatagramTypes.h>
#include <Datagram.h>


class DataHandler {
public:
    DataHandler(std::shared_ptr<Connector> connector);
    virtual ~DataHandler();

    bool updateTx(DatagramType::DatagramID type);
    bool updateRx(Packet* packet);

    void print(DatagramType::DatagramID type) const;

    Packet* getPacket(DatagramType::DatagramID type);

    void printLastRxPacket() const;
    void logLastRxPacket();

private:
    std::shared_ptr<Connector> connector;
    std::vector<Datagram*> dataHandler;
    DatagramType::DatagramID lastRxID;
};


#endif //DataHandler_H
