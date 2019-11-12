/*!
 * \file Image.cpp
 *
 * \brief Image module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019	
 */

#include <cstdlib>
#include <fstream>
#include "Image.h"

Image::Image(uint8_t bytePerPacket, const std::string &fileName, uint16_t width,
             uint16_t heigth) : bytePerPacket(bytePerPacket), fileName(fileName),
                                width(width), heigth(heigth), pictureIsSending(false),
                                nbrSentImg(0), packetNbr(0) {}

void Image::write(Packet &packet) {
    static std::ifstream fileIn(fileName + ".jpg", std::ios::in);

    packet.write(++packetNbr);
    for (uint8_t i(0); i < bytePerPacket; ++i) {
        uint8_t byte;
        if (fileIn >> byte) packet.write(byte);
        else {
            pictureIsSending = false;
            break;
        }
    }
}

void Image::parse(Packet &packet) {
    static std::ofstream fileOut(fileName + ".jpg", std::ios::out | std::ios::app);

    packet.parse(packetNbr);
    for (uint8_t i(0); i < bytePerPacket; ++i) {
        uint8_t byte;
        packet.parse(byte);
        fileOut << byte;
    }
}

void Image::update() {
    if (!pictureIsSending) {
        fileName = fileName + std::to_string(++nbrSentImg);
        // Take a picture with the raspicam
        std::string command("raspistill -o " + fileName + ".jpg -hf -vf -w " +
                            std::to_string(width) + " -h " +
                            std::to_string(heigth));
        system(command.c_str());
        std::cout << "New picture taken - " << fileName << ".jpg" << std::endl;
        pictureIsSending = true;
    }
}

void Image::print() const {
    std::cout << "Image Data cf " << fileName << ".jpg  -- Packet n° " << packetNbr
              << std::endl;
}
