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

    void update();
    void parse();
    void print() const;
    void writeConnector(std::shared_ptr<Connector> connector);
    void readConnector(std::shared_ptr<Connector> connector);

    void add(Data* data);
    Packet* getDataPacket();
    void setPacket(Packet * packet);

    virtual ~Datagram();
private:
    std::vector<Data*> datagram;
    Packet* dataPacket;
};


#endif //Datagram_H
