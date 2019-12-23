/*!
 * \file Header.h
 *
 * \brief Header module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        22.11.2019	
 */

#ifndef Header_H
#define Header_H

#include <ctime>
#include <Packet.h>
#include <Data.h>


class Header : public Data {
public:
    explicit Header(uint8_t packetID);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t myDelimiter[4] = {'E', 'P', 'F', 'L'};
    uint8_t packetID;
    static uint32_t packetNbr;  // common to all datagram
    std::time_t timestamp;
};


#endif //Header_H
