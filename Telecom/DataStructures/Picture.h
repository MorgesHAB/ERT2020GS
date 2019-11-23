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

#define DEF_PICTURE_NAME        "picture"
#define DEF_PICTURE_HEIGHT      300
#define DEF_PICTURE_WIDTH       300

#include <string>
#include <vector>
#include <Data.h>

class Picture : public Data {
public:
    explicit Picture(uint8_t bytePerPacket,
                     const std::string &fileName = DEF_PICTURE_NAME,
                     uint16_t width = DEF_PICTURE_WIDTH,
                     uint16_t heigth = DEF_PICTURE_HEIGHT);

    virtual ~Picture();

    void write(Packet &packet) override;
    void parse(Packet &packet) override;
    void update() override;
    void print() const override;

    void takePicture();
    void buildImage();
    void sendMissingPacket(Packet &packet);

private:
    uint8_t bytePerPacket;
    std::string fileName;
    uint16_t width, heigth;
    bool pictureIsSending;
    int nbrSentImg;
    uint16_t packetNbr;
    size_t imgSize;

    std::vector<uint8_t*> image;
};


#endif //Picture_H
