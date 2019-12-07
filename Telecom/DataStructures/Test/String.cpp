/*!
 * \file String.cpp
 *
 * \brief String module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.12.2019	
 */

#include "String.h"

String::String(const std::string &sentence) : sentence(sentence) {}

void String::write(Packet &packet) {
    packet.write(sentence);
}

void String::parse(Packet &packet) {
packet.parse(sentence);
}

void String::print() const {
    std::cout << "Sentence : " << sentence << std::endl;
}