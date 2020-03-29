//
// Created by stephanie on 12/03/20.
//

#include <Data.h>

#ifndef ERT2020GS_PLTEMPERATURE_H
#define ERT2020GS_PLTEMPERATURE_H




class PLTemperature : public Data {
public:
    void write(Packet &packet) override;

    void parse(Packet &packet) override;

    void print() const override;

    std::string log() const override;

    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    float temperature;
};

#endif //ERT2020GS_PLTEMPERATURE_H