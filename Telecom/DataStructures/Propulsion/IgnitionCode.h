/*!
 * \file IgnitionCode.h
 *
 * \brief IgnitionCode module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.12.2019	
 */

#ifndef IgnitionCode_H
#define IgnitionCode_H

#include <vector>
#include <Data.h>

class IgnitionCode : public Data {
public:
    IgnitionCode(int gpio1, int gpio2, int gpio3, int gpio4);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void update() override;
    void print() const override;

private:
    int gpio1, gpio2, gpio3, gpio4;
    std::vector<bool> states;
};


#endif //IgnitionCode_H
