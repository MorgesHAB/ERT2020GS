//
// Created by cem on 13/10/2020.
//

#ifndef ERT2020GS_PPDATA_H
#define ERT2020GS_PPDATA_H

#include <Data.h>
class PPData : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;

    void print() const override;
    std::string log() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

    
private:
    uint16_t pressure_1, pressure_2, status;
    int16_t temperature_1, temperature_2, temperature_3;
};

#endif //ERT2020GS_PPDATA_H
