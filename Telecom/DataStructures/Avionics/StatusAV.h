//
// Created by stephanie on 13/02/20.
//

#ifndef ERT2020GS_STATUSAV_H
#define ERT2020GS_STATUSAV_H

#include <ctime>
#include <Data.h>


class StatusAV: public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;

    void print() const override;
    std::string log() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t id, status;
    float value;
};

#endif //ERT2020GS_STATUSAV_H
