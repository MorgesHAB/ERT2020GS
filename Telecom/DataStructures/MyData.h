/*!
 * \file MyData.h
 *
 * \brief MyData module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        20.11.2019	
 */

#ifndef MyData_H
#define MyData_H

// Pattern class

#include <Data.h>

class MyData : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void update() override;
    void print() const override;

private:
    float nbr;
    int x;
    char id;
    // ... Your class attributes
};


#endif //MyData_H
