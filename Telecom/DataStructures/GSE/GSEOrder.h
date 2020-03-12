//
// Created by stephanie on 13/02/20.
//

#ifndef ERT2020GS_GSEORDER_H
#define ERT2020GS_GSEORDER_H


#include <Data.h>
#include <GSE/GSEOrderValues.h>

class GSEOrder: public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t order;
};


#endif //ERT2020GS_GSEORDER_H
