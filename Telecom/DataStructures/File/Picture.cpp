/*!
 * \file Picture.cpp
 *
 * \brief Picture module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019
 */

#include <cstdlib>
#include "Picture.h"

Picture::Picture(const std::string &fileName, uint8_t bytePerPacket, uint16_t width,
                 uint16_t height) : File(fileName, bytePerPacket),
                                    width(width), height(height), imgCapturedNbr(0) {}


bool Picture::importFile() {
    // pictureName1.jpg , pictureName2.jpg , ... pictureNameN.jpg
    fileName.replace(0, fileName.rfind('.'),
            fileName.substr(0, fileName.rfind('.')) + std::to_string(++imgCapturedNbr)); // <--replace with
    // Take a picture with the raspicam
    std::string command("raspistill -o " + fileName + " -hf -vf -w " +
                        std::to_string(width) + " -h " + std::to_string(height));
    system(command.c_str()); // execute command on RPi terminal
    std::cout << "New picture taken - " << fileName << std::endl;
    return File::importFile();
}
