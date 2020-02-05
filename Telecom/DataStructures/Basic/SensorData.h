/*!
 * \file SensorData.h
 *
 * \brief SensorData module interface
 *
 * Generic class to transmit some data
 * eg: float, int, uint32-16-8, char etc
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
    SensorData(ui_interface::DataType name) : name(name) {}

    void write(Packet& packet) override {
        packet.write(data);
    }

    void parse(Packet& packet) override {
        packet.parse(data);
    }

    void print() const override {
        std::cout << "Generic Data received - value : " << data << std::endl;
    }

    void updateRx(std::shared_ptr<Connector> connector) override {
        connector->setData(name, data);
    }

    void updateTx(std::shared_ptr<Connector> connector) {
        // just for Test - this class is only use at reception
        data = ((double) rand()/ RAND_MAX) * 1000;
    }

private:
    Tdata data;
    ui_interface::DataType name;
};


#endif //SensorData_H