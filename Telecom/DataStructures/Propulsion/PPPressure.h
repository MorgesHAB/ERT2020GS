/*!
 * \file PressureData.h
 *
 * \brief PressureData module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#ifndef PressureData_H
#define PressureData_H

#include <Data.h>

class PPPressure : public Data {
public:
    PPPressure();

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    float pressure;
};


#endif //PressureData_H
