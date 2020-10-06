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
    explicit Header(uint8_t DatagramID);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;

    void print() const override;
    std::string log() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    const uint8_t myDelimiter[4] = {'E', 'P', 'F', 'L'};
    uint8_t myRxDelimiter[4] = {'-', '-','-','-'};
    uint8_t datagramID;
    uint32_t packetNumber;
    uint32_t timestamp; // [ms]
};


#endif //Header_H
