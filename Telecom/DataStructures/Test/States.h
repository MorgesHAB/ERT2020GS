/*!
 * \file States.h
 *
 * \brief States module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        12.11.2019	
 */

#ifndef States_H
#define States_H


#include <vector>
#include <Data.h>


class States : public Data {
public:
    explicit States(const std::vector<bool> &states);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

private:
    std::vector<bool> states;
};


#endif //States_H
