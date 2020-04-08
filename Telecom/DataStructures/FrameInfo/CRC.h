/*!
 * \file CRC.h
 *
 * \brief CRC module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        29.11.2019	
 */

#ifndef CRC_H
#define CRC_H

#include <Data.h>


class CRC : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;

private:
    uint8_t CRC;
};


#endif //CRC_H
