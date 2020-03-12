//
// Created by stephanie on 12/03/20.
//

#ifndef ERT2020GS_PLORDER_H
#define ERT2020GS_PLORDER_H

#include <Data.h>

class PLOrder: public Data{
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;
    std::string log() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t order;
};

};

#endif //ERT2020GS_PLORDER_H
