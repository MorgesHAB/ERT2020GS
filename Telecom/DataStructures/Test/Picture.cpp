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
    image[0]                    uint8_t[bytePerPacket] = [10101101 | 10100011 | .... ]
    image[1]                    uint8_t[bytePerPacket] = [11101101 | 0000011 | .... ]
    ...
    image[packetNbrMissing]     nullptr                         not received
    ...
    image[nbrTotPacket]         ....                            last index
*/

#include <cstdlib>
#include <fstream>
#include "Picture.h"

Picture::Picture(uint8_t bytePerPacket, const std::string &fileName, uint16_t width,
                 uint16_t heigth) : bytePerPacket(bytePerPacket), fileName(fileName),
                                width(width), heigth(heigth), pictureIsSending(false),
                                nbrSentImg(0), packetNbr(0), nbrTotPacket(0) {}

Picture::~Picture() {
    for (auto& part : image) delete[] part;
    image.clear();
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
    //fileName = fileName + std::to_string(++nbrSentImg);
    // Take a picture with the raspicam
    std::string command("raspistill -o " + fileName + ".jpg -hf -vf -w " +
                        std::to_string(width) + " -h " +
                        std::to_string(heigth));
    //system(command.c_str()); // execute command on RPi terminal
    std::cout << "New picture taken - " << fileName << ".jpg" << std::endl;
    pictureIsSending = true;

    // Store all bytes of the image
    std::ifstream fileIn(fileName + ".jpg", std::ios::in | std::ios::binary);

    if (fileIn) {
        size_t nbr(0);
        while (!fileIn.eof()) {
            image.push_back(new uint8_t[bytePerPacket]);
            for (size_t i(0); i < bytePerPacket && !fileIn.eof(); ++i) {
                image[nbr][i] = fileIn.get();
            }
            ++nbr;
        }

        nbrTotPacket = image.size();
    } else
        std::cerr << "Impossible to read the image file" << std::endl;
}

void Picture::write(Packet &packet) {
    if (pictureIsSending) {
        packet.write(packetNbr);
        if (packetNbr == 0) packet.write(nbrTotPacket);

        for (size_t i(0); i < bytePerPacket; ++i) {
            packet.write(image[packetNbr][i]);
        }
        ++packetNbr;
        if (packetNbr == nbrTotPacket) pictureIsSending = false;
    }
}

/////////////////// Receiver Part ///////////////////

void Picture::print() const {
    std::cout << "Picture Data " << fileName << ".jpg  -- Packet n° " << packetNbr
              << " / " << nbrTotPacket - 1 << std::endl;
}

void Picture::parse(Packet &packet) {
    packet.parse(packetNbr);
    if (packetNbr == 0) {
        packet.parse(nbrTotPacket);
        image.resize(nbrTotPacket, nullptr);
    }
    if (packetNbr < nbrTotPacket) {
        image[packetNbr] = new uint8_t[bytePerPacket];
        for (size_t i(0); i < bytePerPacket; ++i) {
            packet.parse(image[packetNbr][i]);
        }
    }
}

void Picture::updateRx(std::shared_ptr<Connector> connector) {
    // build image V1 condition not good <=> if last packet
    if (packetNbr == nbrTotPacket - 1/*/ bytePerPacket + 1*/) {
        pictureIsSending = false;
        buildImage();
    }
}

void Picture::buildImage() {
    std::ofstream fileOut(fileName + "Rx.jpg", std::ios::out | std::ios::binary);

    if (fileOut) {
        for(size_t i(0); i < nbrTotPacket; ++i) {
            for (size_t j(0); j < bytePerPacket; ++j) {
                if (image[i]) { // if received packet else nullptr
                    fileOut.put(image[i][j]);
                } else {
                    fileOut.put(0); // black ?
                    std::cout << "!!! packet nbr " << i << " not received" << std::endl;
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
