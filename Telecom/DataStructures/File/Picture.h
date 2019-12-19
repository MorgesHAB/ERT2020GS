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
    explicit Picture(uint8_t bytePerPacket,
                     const std::string &fileName = "picture",
                     uint16_t width = 300,
                     uint16_t heigth = 300);

    void updateTx(std::shared_ptr<Connector> connector) override;

    void takePicture();

private:
    uint16_t width, heigth;
};


#endif //Picture_H
