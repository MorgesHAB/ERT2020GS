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


#include "Data.h"
#define MSG_SIZE         31

class XbeeOptions : public Data {
public:
    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void update() override;
    void print() const override;

private:
    uint8_t msg[MSG_SIZE] = {0x7E, 0x00, 0x1B, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
                             0xFE, 0x00, 0x43, 0x55, 0x55, 0x55, 0x55, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                             0x00, 0x14, 0x35};
/*    uint8_t XBEE_FRAME_OPTIONS[XBEE_FRAME_OPTIONS_SIZE] = {
            XBEE_TX_FRAME_TYPE,  // Frame type
            0x00,           // Frame ID
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,     // 64 bit dest address
            0xff, 0xfe,           // 16 bits dest address (0xff fe = broadcast)
            0x00,           // Broadcast radius (0 = max)
            0x43 };          // Transmit options (disable ACK and Route discovery)
*/
};


#endif //XbeeOptions_H
