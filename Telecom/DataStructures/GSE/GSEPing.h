//
// Created by cem on 13/10/2020.
//

#ifndef ERT2020GS_GSEPING_H
#define ERT2020GS_GSEPING_H

#include <Data.h>
class GSEPing : public Data {

public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;

    void print() const override;
    std::string log() const override;

    ~GSEPing() override = default;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;
};


#endif //ERT2020GS_GSEPING_H
