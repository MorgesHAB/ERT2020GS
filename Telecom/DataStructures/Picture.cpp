/*!
 * \file Picture.cpp
 *
 * \brief Picture module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019	
 */

#include <cstdlib>
#include <fstream>
#include "Picture.h"

Picture::Picture(uint8_t bytePerPacket, const std::string &fileName, uint16_t width,
                 uint16_t heigth) : bytePerPacket(bytePerPacket), fileName(fileName),
                                width(width), heigth(heigth), pictureIsSending(false),
                                nbrSentImg(0), packetNbr(0), imgSize(0) {}

void Picture::write(Packet &packet) {
    if (pictureIsSending) {
        packet.write(++packetNbr);
        if (packetNbr == 1) packet.write(imgSize);

        for (size_t i((packetNbr - 1) * bytePerPacket);
             i < packetNbr * bytePerPacket && i < imgSize; ++i) {
            packet.write(image[i]);
        }
        if (packetNbr == imgSize / bytePerPacket + 1) pictureIsSending = false;
    }
}

void Picture::parse(Packet &packet) {
    if (pictureIsSending) {
        packet.parse(packetNbr);
        if (packetNbr == 1) {
            packet.parse(imgSize);
            image.resize(imgSize);
            RxPacket.resize(imgSize / bytePerPacket + 1);
        }
        RxPacket[packetNbr] = true;
        for (size_t i((packetNbr - 1) * bytePerPacket);
             i < packetNbr * bytePerPacket && i < imgSize; ++i) {
            packet.parse(image[i]);
        }
        // build image V1 condition not good // if last packet
        if (packetNbr == imgSize / bytePerPacket + 1) {
            pictureIsSending = false;
            buildImage();
        }
    }
}

void Picture::update() {
    static bool first(true);
    if (first) {
        takePicture();
        first = false;
    }
}

void Picture::print() const {
    std::cout << "Picture Data " << fileName << ".jpg  -- Packet n° " << packetNbr
              << " / " << imgSize / bytePerPacket + 1 << std::endl;
}

void Picture::takePicture() {
    fileName = fileName + std::to_string(++nbrSentImg);
    // Take a picture with the raspicam
    std::string command("raspistill -o " + fileName + ".jpg -hf -vf -w " +
                        std::to_string(width) + " -h " +
                        std::to_string(heigth));
    system(command.c_str());
    std::cout << "New picture taken - " << fileName << ".jpg" << std::endl;
    pictureIsSending = true;

    // Store all bytes of the image
    std::ifstream fileIn(fileName + ".jpg", std::ios::in | std::ios::binary);

    if (fileIn) {
        while (!fileIn.eof()) image.push_back(fileIn.get());

        imgSize = image.size(); // entire division
    } else
        std::cerr << "Impossible to read the image file" << std::endl;
}

void Picture::buildImage() {
    for(size_t i(1); i <= imgSize / bytePerPacket + 1; ++i)
        if (!RxPacket[i])
            std::cout << "packet " << i << " not received" << std::endl;

    std::ofstream fileOut(fileName + ".jpg", std::ios::out | std::ios::binary);

    if (fileOut) {
        for (size_t i(0); i < imgSize; ++i) fileOut.put(image[i]);

        std::cout << "*** New received picture is available as " << fileName << ".jpg"
                  << std::endl;
        fileOut.close();
    } else
        std::cerr << "Impossible to save the image file" << std::endl;
}
