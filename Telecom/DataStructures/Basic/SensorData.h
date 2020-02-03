/*!
 * \file SensorData.h
 *
 * \brief SensorData module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        03.02.2020	
 */

#ifndef SensorData_H
#define SensorData_H

#include <Data.h>

template<typename Tdata>
class SensorData : public Data {
public:

    void write(Packet& packet) override {
        packet.write(data);
    }

    void parse(Packet& packet) override {
        packet.parse(data);
    }

    void print() const override {
        std::cout << "Generic Data received - value  " << data << std::endl;
    }

    void updateRx(std::shared_ptr<Connector> connector) override {
        Data::updateRx(connector);
    }

private:
    Tdata data;
};


#endif //SensorData_H
