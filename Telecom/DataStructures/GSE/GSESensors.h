//
// Created by stephanie on 13/02/20.
//

#ifndef ERT2020GS_GSESENSORS_H
#define ERT2020GS_GSESENSORS_H


#include <Data.h>

class GSESensors: Data {
public:

    void write(Packet &packet) override;
    void parse(Packet& packet) override;

    void print() const override;
    std::string log() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

private:
    float hose_pressure, hose_temp, motor_speed, tank_weight;
    bool hose_status;
};


#endif //ERT2020GS_GSESENSORS_H
