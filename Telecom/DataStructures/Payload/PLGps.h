//
// Created by stephanie on 12/03/20.
//

#ifndef ERT2020GS_PLGPS_H
#define ERT2020GS_PLGPS_H

#include <Data.h>

class PLGps: public Data{
public:
    void write(Packet &packet) override;

    void parse(Packet &packet) override;

    void print() const override;

    std::string log() const override;

    bool updateRx(std::shared_ptr<Connector> connector) override;

private:

    uint8_t satelliteNbr;
    float hdop, latitude, longitude, altitude;
};


#endif //ERT2020GS_PLGPS_H
