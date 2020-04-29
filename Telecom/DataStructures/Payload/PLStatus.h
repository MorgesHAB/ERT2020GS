//
// Created by stephanie on 12/03/20.
//

#ifndef ERT2020GS_PLSTATUS_H
#define ERT2020GS_PLSTATUS_H

#include <Data.h>

class PLStatus: public Data{
public:
    void write(Packet &packet) override;

    void parse(Packet &packet) override;

    void print() const override;

    std::string log() const override;

    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t status; //TODO: create file with status
};

#endif //ERT2020GS_PLSTATUS_H
