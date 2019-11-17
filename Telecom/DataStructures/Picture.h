/*!
 * \file Picture.h
 *
 * \brief Picture module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019	
 */

#ifndef Picture_H
#define Picture_H

#include <string>
#include <vector>
#include <Data.h>

class Picture : public Data {
public:
    Picture(uint8_t bytePerPacket, const std::string &fileName = "picture",
          uint16_t width = 300, uint16_t heigth = 300);

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


#endif //Picture_H
