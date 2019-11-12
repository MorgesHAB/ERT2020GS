/*!
 * \file Image.h
 *
 * \brief Image module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019	
 */

#ifndef Image_H
#define Image_H

#include <string>
#include <vector>
#include "Data.h"

class Image : public Data {
public:
    Image(uint8_t bytePerPacket, const std::string &fileName = "picture",
          uint16_t width = 300, uint16_t heigth = 300);

    ~Image() override;

    void write(Packet &packet) override;
    void parse(Packet &packet) override;
    void update() override;
    void print() const override;

private:
    uint8_t bytePerPacket;
    std::string fileName;
    uint16_t width, heigth;
    bool pictureIsSending;
    int nbrSentImg;
    uint16_t packetNbr;
};


#endif //Image_H
