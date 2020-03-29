/*!
 * \file Template.h
 *
 * \brief MyData module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        20.11.2019
 *
 *  Thus you must define your own Data Structures in order
 *  to put them in your own Datagram
 *
 */

#ifndef MyData_H
#define MyData_H

// Pattern class

#include <Data.h>

class MyData : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    float nbr;
    int x;
    char id;
    // ... Your class attributes
};


#endif //MyData_H
