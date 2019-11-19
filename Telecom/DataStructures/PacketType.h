/*!
 * \file PacketType.h
 *
 * \brief PacketType module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019	
 */

#ifndef PacketType_H
#define PacketType_H

#include "Data.h"


class PacketType : public Data {
public:
    explicit PacketType(uint8_t type);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void update() override;
    void print() const override;

private:
    uint8_t type;
};


#endif //PacketType_H
