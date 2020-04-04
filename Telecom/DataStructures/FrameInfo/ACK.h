/*!
 * \file ACK.h
 *
 * \brief ACK module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.04.2020	
 */

#ifndef ACK_H
#define ACK_H

#include <Data.h>

// This Data need to be put just after header

class ACK : public Data {
public:
    ACK(ui_interface::DataType indexName);

    void write(Packet& packet) override;
    void parse(Packet& packet) override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t ackvalue;
    ui_interface::DataType indexName;
};


#endif //ACK_H
