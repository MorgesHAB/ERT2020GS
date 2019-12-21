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

Picture::Picture(uint8_t bytePerPacket, const std::string &fileName, uint16_t width,
                 uint16_t heigth) : File(fileName, bytePerPacket),
                                    width(width), heigth(heigth) {}


void Picture::importFile() {
    //fileName = fileName + std::to_string(++nbrSentImg);
    // Take a picture with the raspicam
    std::string command("raspistill -o " + fileName + " -hf -vf -w " +
                        std::to_string(width) + " -h " + std::to_string(heigth));
    system(command.c_str()); // execute command on RPi terminal
    std::cout << "New picture taken - " << fileName << std::endl;
    File::importFile();
}
