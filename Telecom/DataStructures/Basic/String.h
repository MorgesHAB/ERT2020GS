/*!
 * \file String.h
 *
 * \brief String module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        01.12.2019	
 */

#ifndef String_H
#define String_H

#include <Data.h>

class String : public Data {
public:
    explicit String(const std::string &sentence);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

private:
    std::string sentence;
};


#endif //String_H
