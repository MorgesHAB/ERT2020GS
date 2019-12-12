/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file ProtocolDefine.h
 *
 * \brief User Interface - RF Telecom interface protocol definition
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \author      KESKE Cem - EPFL EL BA3
 * \date        02.12.2019
 */

#ifndef ProtocolDefine_H
#define ProtocolDefine_H

namespace ui_interface {

enum DataType {
    ///General

    RUNNING = 0, //bool             **Every thread listens this boolean and stop executing when it is false.

    /// Qt input informations

    ACTIVE_XBEE, //bool             **This is set to true-false by the Activate-Xbee button.
    IGNITION_CLICKED, //bool        **This is set to true when ignition button is clicked.
                      //            @attention !!! Listener should eat this boolean to be able to detect further clicks !!!

    IGNITION_STATUS, // bool        ** true :  FIRE,  false : ABORTED
    IGNITION_KEY_ACTIVATED, //bool
    IGNITION_RED_BUTTON_PUSHED, //bool
    SEND_IGNITION_PACKET, // bool /!\

    /// PacketNbr

    PACKET_RX_RATE_CTR, //uint32_t  **This is incremented on each packet received, eated by guito find the packet rate.
    RX_PACKET_CTR,//uint32_t        **This is the count of the received packets from the beginning of the program

    /// Header
    PACKET_ID, //uint8_t            **The ID of the last packet received
    TX_PACKET_NR,//uint32_t         **This is the last packet's number.
    TIMESTAMP, //time_t             **The Time of the last packet received

    /// GPS Data Structure (float et time_t)

    ALTITUDE,//float                **The last altitude reading
    LONGITUDE,//float               **The last longitude reading
    LATITUDE,//float                **The last latitude reading
    SPEED,//float                   **The last speed reading
    TIME,//time_t 32                **The time of the last GPS packed received


    /// Pressure Data

    PRESSURE_DATA,//float           **Last pressure reading

    /// Tx ignition code

    TX_IGNITION_CODE, //uint8_t     **Extract first 4 lsb for the code.



    /// !!! THIS MUST BE THE LAST LINE !!!
    /// At the end the array size

    ARRAY_SIZE
};

}
#endif //ProtocolDefine_H
