//
// Created by stephanie on 13/02/20.
//

#ifndef ERT2020GS_GSESENSORS_H
#define ERT2020GS_GSESENSORS_H


#include <Data.h>

class GSESensors: public Data {
public:

    void write(Packet &packet) override;
    void parse(Packet& packet) override;

    void print() const override;
    std::string log() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint32_t tank_temp, hose_pressure, hose_temperature, rocket_weight, battery_level, main_ignition_current, secondary_ignition_current, main_disconnect_current, secondary_disconnect_current, fill_valve_current, purge_valve_current,  wind_speed;
    bool purge_valve_state, fill_valve_state, main_ignition_state, secondary_ignition_state, main_disconnect_state, secondary_disconnect_state;
};


#endif //ERT2020GS_GSESENSORS_H
