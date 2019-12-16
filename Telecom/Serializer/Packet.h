/*!
 * \file    Packet.h
 *
 * This class manage to write and parse every needed type of Data in a RF packet \n
 * RF packet : uint8_t packet[MAX_SIZE] \n
 *
 * Utilisation :
 * call the methods write(Type t) and parse(Type t) for the following type :
 *  - float - int - char - bool - string - uint32_t - uint16_t - uint8_t
 *  Doesn't work for type - double
 *
 *
 *  Compilation requirement : \n
 *  These code files need to be compiled with -std=c++11 option \n
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.11.2019
 */

#ifndef PACKET_H
#define PACKET_H

#include <iostream>

#define PACKET_SIZE_ALLOC_TX_PART       250

class Packet {
public:
    explicit Packet(size_t size = PACKET_SIZE_ALLOC_TX_PART);
    virtual ~Packet();
    void restart();
    void write(std::string& msg);
    void parse(std::string& msg);

    template<typename T>
    void write(T t);
    template<typename T>
    void parse(T &t);

    uint8_t *getPacket();
    uint8_t getSize() const;
    void printDebug() const;
private:
    template<typename R, typename T>
    void writeY(T t);
    template<typename R, typename T>
    void parseY(T &t);

    uint8_t* packet;
    uint8_t* packetPosition;
    size_t size;
};

// Template functions definitions (not in .cpp file because of link errors)

template<typename T>
void Packet::write(T t) {
    uint8_t size(sizeof(t));
    if (getSize() + size > PACKET_SIZE_ALLOC_TX_PART) {
        std::cout << "Error : Packet is full - bigger than " << PACKET_SIZE_ALLOC_TX_PART
                  << "\nA packet reorganization is required." << std::endl;
        exit(0);
    }
    else if (size == 1) writeY<uint8_t>(t);
    else if (size == 2) writeY<uint16_t>(t);
    else if (size == 4) writeY<uint32_t>(t);
    else if (size == 8) writeY<uint64_t>(t); // don't work on Rpi
    else std::cout << "Error : Inconciliable type..." << std::endl;
}

template<typename T>
void Packet::parse(T &t) {
    uint8_t size(sizeof(t));
    if (size == 1) parseY<uint8_t>(t);
    else if (size == 2) parseY<uint16_t>(t);
    else if (size == 4) parseY<uint32_t>(t);
    else if (size == 8) parseY<uint64_t>(t);  // don't work on Rpi
    else std::cout << "Error : Inconciliable type..." << std::endl;
}


template<typename R, typename T>
void Packet::writeY(T t)  {
    R r = reinterpret_cast<R&> (t);

    for (int i = sizeof(t) - 1; i >= 0; --i)
        *(packetPosition++) = r >> (8 * i);
}

template<typename R, typename T>
void Packet::parseY(T &t) {
    R r(0);
    for (int i = sizeof(t) - 1; i >= 0; --i)
        r |= (*(packetPosition++) << (8 * i));

    t = reinterpret_cast<T&> (r);
}


#endif //PACKET_H
