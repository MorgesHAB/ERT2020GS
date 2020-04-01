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
#include <Loggable.h>
#include <Logger.h>
#include <DatagramTypes.h>


class Datagram : public Loggable {
public:
    Datagram(DatagramType::DatagramID ID);
    virtual ~Datagram();

    void print() const;
    std::string log_description() const override;
    void log();

    bool updateTx(std::shared_ptr<Connector> connector);
    bool updateRx(Packet *packet, std::shared_ptr<Connector> connector);

    void add(Data* data);
    Packet* getDataPacket();

private:
    DatagramType::DatagramID ID;
    std::vector<Data*> datagram;
    Packet* dataPacket;

    Logger logger;
};


#endif //Datagram_H
