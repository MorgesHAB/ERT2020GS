/*!
 * \file ACKManager.h
 *
 * \brief ACKManager module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        13.02.2020	
 */

#ifndef ACKManager_H
#define ACKManager_H

#include <Data.h>
#include <DatagramTypes.h>

class ACKManager : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t ACK;
    DatagramType::DatagramID IDtoACK;
};


#endif //ACKManager_H
