/*!
 * \file XbeeOptions.h
 *
 * \brief XbeeOptions module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        29.11.2019	
 */

#ifndef XbeeOptions_H
#define XbeeOptions_H

#include <Data.h>

#define XBEE_FRAME_OPTIONS_SIZE     14


class XbeeOptions : public Data {
public:
    XbeeOptions();

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void update() override;
    void print() const override;

private:
    uint8_t XBEE_FRAME_OPTIONS[XBEE_FRAME_OPTIONS_SIZE];
};


#endif //XbeeOptions_H
