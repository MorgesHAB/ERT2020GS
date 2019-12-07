/*!
 * \file Datagram.h
 *
 * \brief Datagram module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#ifndef Datagram_H
#define Datagram_H


#include <vector>
#include <Data.h>
#include <Packet.h>

class Datagram {
public:
    Datagram();
    virtual ~Datagram();

    void print() const;

    void updateTx(std::shared_ptr<Connector> connector);
    void updateRx(Packet *packet, std::shared_ptr<Connector> connector);

    void add(Data* data);
    Packet* getDataPacket();

private:
    std::vector<Data*> datagram;
    Packet* dataPacket;
};


#endif //Datagram_H
