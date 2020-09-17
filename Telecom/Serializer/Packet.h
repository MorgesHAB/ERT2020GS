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
 *
 * \editor      KESKE Cem   - EPFL EL BA5
 * \date        18.09.2020
 */

#ifndef PACKET_H
#define PACKET_H

#include <iostream>

#define PACKET_SIZE_ALLOC_TX_PART       255             // Xbee maximum size

class Packet {
public:
    /**
     * At Tx the size will be calculated automatically by calling write functions
     * At Rx the size is specified
     * Warning : depending on your module, there may be a maximum limit eg: 256 Bytes
     * @param packetSize
     */
    explicit Packet(size_t packetSize = PACKET_SIZE_ALLOC_TX_PART);
    virtual ~Packet();

    /**
     * write Data in the packet
     * @tparam T    The basic type of your Data  eg: float, int, char, bool, uint16_t
     * @param t     The variable containing the data you want to write
     */
    template<typename T>
    void write(T t);
    /**
     * read tha Data in the packet
     * @tparam T    The basic type of your Data  eg: float, int, char, bool, uint16_t
     * @param t     The variable where data will be stored
     */
    template<typename T>
    void parse(T &t);

    /**
     * overloaded function for sending strings
     * Protocol : write string size (1 byte) + write char by char
     * @param msg       The variable containing a sentence to send
     */
    void write(std::string &msg);

    /**
     * overloaded function for receiving strings
     * @param msg       The variable where the string will be stored
     */
    void parse(std::string &msg);

    /**
     * Get the packet containing your data - will be use by your RF library for Tx & Rx
     * @return      pointer on the packet
     */
    uint8_t *getPacket();

    /**
     * Get you packet size, used for Tx
     * Size is encapsulated data, the user does not take care of it
     * @return      packet size (bytes)
     */
    uint8_t getSize() const;

    /**
     * Print packet raw data - byte per byte
     */
    void printDebug() const;

    void restart();         // not used

private:
    /**
     * Write a Data in an array of byte (uint8_t) => use binary shifting 1-2-4-8 bytes
     * @tparam R    The type of data according to which the data will be encoded
     * @tparam T    The base data type
     * @param t     The data you want to write
     */
    template<typename R, typename T>
    void writeY(T t);
    /**
     * Parse a sequence of byte (uint8_t) and concatenates to a sequence of bytes
     * and then to the specified data type T
     * @tparam R    The data type according to which the data will be encoded 1-2-4-8 bytes
     * @tparam T    The base data type
     * @param t     The variable where data will be stored
     */
    template<typename R, typename T>
    void parseY(T &t);

    uint8_t* packet;            //!< byte array
    uint8_t* packetPosition;    //! byte array current index
    size_t packetSize;          //! use for reception
};


// Template functions definitions (not in .cpp file because of link errors)
template<typename T>
void Packet::write(T t) {
    uint8_t size(sizeof(t));
    if (getSize() + size > PACKET_SIZE_ALLOC_TX_PART) {
        std::cerr << "Error : Packet is full size: " << +getSize() + size << " - bigger than "
                  << PACKET_SIZE_ALLOC_TX_PART
                  << "\nA packet reorganization is required." << std::endl;
        exit(0);
    }
    else if (size == 1) writeY<uint8_t>(t);
    else if (size == 2) writeY<uint16_t>(t);
    else if (size == 4) writeY<uint32_t>(t);
    else if (size == 8) writeY<uint64_t>(t); // doesn't work on Rpi
    else std::cout << "Error : Incompatible type ..." << std::endl;
}

template<typename T>
void Packet::parse(T &t) {
    uint8_t size(sizeof(t));
    if (size == 1) parseY<uint8_t>(t);
    else if (size == 2) parseY<uint16_t>(t);
    else if (size == 4) parseY<uint32_t>(t);
    else if (size == 8) parseY<uint64_t>(t);  // donesn't work on Rpi
    else std::cout << "Error : Incompatible type ..." << std::endl;
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
