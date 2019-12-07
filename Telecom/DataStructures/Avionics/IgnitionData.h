/*!
 * \file IgnitionData.h
 *
 * \brief IgnitionData module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#ifndef IgnitionData_H
#define IgnitionData_H

#include <string>
#include <Data.h>

class IgnitionData : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;

private:
    std::string ignition;
};


#endif //IgnitionData_H
