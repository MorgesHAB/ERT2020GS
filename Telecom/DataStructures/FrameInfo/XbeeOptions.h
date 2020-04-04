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

#define XBEE_TX_OPTIONS_SIZE        14
#define XBEE_RX_OPTIONS_SIZE        12


class XbeeOptions : public Data {
public:
    XbeeOptions();

    void write(Packet& packet) override;
    void parse(Packet& packet) override;

    bool updateRx(std::shared_ptr<Connector> connector) override;

private:
    uint8_t xbeeTransmitOptions[XBEE_TX_OPTIONS_SIZE];
    uint8_t xbeeReceivedOptions[XBEE_RX_OPTIONS_SIZE];
};


#endif //XbeeOptions_H
