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

#include <File/File.h>


class Picture : public File {
public:
    explicit Picture(const std::string &fileName = "picture.jpg",
                     uint8_t bytePerPacket = 220,
                     uint16_t width = 500,
                     uint16_t height = 500);

    bool importFile() override ;

private:
    uint16_t width, height;
    uint16_t imgCapturedNbr;
};


#endif //Picture_H
