/*!
 * \file Picture.cpp
 *
 * \brief Picture module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019	
 */

/* Image stock diagram
    image[packetNbr]            values : uint8_t*               #comment
    image[0]                    nullptr                         start to count at 1
    image[1]                    uint8_t[bytePerPacket] = [10101101 | 10100011 | .... ]
    ...
    image[packetNbrMissing]     nullptr                         not received
    ...
    image[imgSize / bytePerPacket + 1]                          last index
*/

#include <cstdlib>
#include <fstream>
#include "Picture.h"

Picture::Picture(uint8_t bytePerPacket, const std::string &fileName, uint16_t width,
                 uint16_t heigth) : bytePerPacket(bytePerPacket), fileName(fileName),
                                width(width), heigth(heigth), pictureIsSending(false),
                                nbrSentImg(0), packetNbr(0), imgSize(0) {}

Picture::~Picture() {
    for (auto& part : image) delete[] part;
}

/////////////////// Transmitter Part ///////////////////

void Picture::updateTx(std::shared_ptr<Connector> connector) {
    // manage send img - missing packet request - etc
    static bool first(true);
    if (first) {
        takePicture();
        first = false;
    }
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
        image.push_back(nullptr); // don't use first index
        size_t nbr(1);
        while (!fileIn.eof()) {
            image.push_back(new uint8_t[bytePerPacket]);
            for (size_t i(0); i < bytePerPacket && !fileIn.eof(); ++i) {
                image[nbr][i] = fileIn.get();
            }
            ++nbr;
        }

        imgSize = image.size() * bytePerPacket;
    } else
        std::cerr << "Impossible to read the image file" << std::endl;
}

void Picture::write(Packet &packet) {
    if (pictureIsSending) {
        packet.write(++packetNbr);
        if (packetNbr == 1) packet.write(imgSize);

        image[packetNbr] = new uint8_t[bytePerPacket];
        for (size_t i(0); i < bytePerPacket && i < imgSize; ++i) {
            packet.write(image[packetNbr][i]);
        }
        if (packetNbr == imgSize / bytePerPacket + 1) pictureIsSending = false;
    }
}

/////////////////// Receiver Part ///////////////////

void Picture::print() const {
    std::cout << "Picture Data " << fileName << ".jpg  -- Packet n° " << packetNbr
              << " / " << imgSize / bytePerPacket + 1 << std::endl;
}

void Picture::parse(Packet &packet) {
    packet.parse(packetNbr);
    if (packetNbr == 1) {
        packet.parse(imgSize);
        image.resize(imgSize / bytePerPacket + 1, nullptr);
    }

    image[packetNbr] = new uint8_t[bytePerPacket];
    for (size_t i(0); i < bytePerPacket && i < imgSize; ++i) {
        packet.parse(image[packetNbr][i]);
    }
    // build image V1 condition not good <=> if last packet
    if (packetNbr == imgSize / bytePerPacket + 1) {
        pictureIsSending = false;
        buildImage();
    }
}

void Picture::buildImage() {
    std::ofstream fileOut(fileName + ".jpg", std::ios::out | std::ios::binary);

    if (fileOut) {
        for(size_t i(1); i <= image.size(); ++i) {
            for (size_t j(0); j< bytePerPacket; ++j) {
                if (image[i]) { // if received packet else nullptr
                    fileOut.put(image[i][j]);
                } else {
                    fileOut.put(0); // black ?
                    std::cout << "!!! packet nbr " << i << " not received"
                              << std::endl;
                }
            }
        }

        std::cout << "*** New received picture is available as " << fileName << ".jpg"
                  << std::endl;
        fileOut.close();
    } else
        std::cerr << "Impossible to save the image file" << std::endl;
}

void Picture::sendMissingPacket(Packet &packet) {
    for(size_t i(1); i <= image.size(); ++i) {
        if (!image[i]) packet.write(i);
    }
}
