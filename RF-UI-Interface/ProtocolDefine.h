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
        //                              @attention !!! Listener should eat this boolean to be able to detect further clicks !!!

        /// RF modem
        LAST_RSSI, // uint8_t           **Reports the RSSI in -dBm of the last received RF data packet.

        /// Ignition
        IGNITION_STATUS, // bool        ** true :  FIRE,  false : ABORTED
        IGNITION_KEY_1_ACTIVATED, //bool
        IGNITION_KEY_2_ACTIVATED, //bool
        IGNITION_RED_BUTTON_PUSHED, //bool
        IGNITION_SENT, // bool to eat

        /// PacketNbr
        PACKET_RX_RATE_CTR, //uint32_t  **This is incremented on each packet received, eated by guito find the packet rate.
        RX_PACKET_CTR,//uint32_t        **This is the count of the received packets from the beginning of the program
        CORRUPTED_PACKET_CTR,//uint64_t **The count of the corrupted packets received. Incremented by RX.

        /// Header
        PACKET_ID, //uint8_t            **The ID of the last packet received
        TX_PACKET_NR,//uint32_t         **This is the last packet's number.
        TIMESTAMP, //time_t             **The Time of the last packet received

        /// GPS Data Structure
        GPS_ALTITUDE,//float                **The last altitude reading
        GPS_LONGITUDE,//float               **The last longitude reading
        GPS_LATITUDE,//float                **The last latitude reading
        GPS_HDOP, // float
        GPS_SAT_NBR, // uint8_t

        // Telemetry Avionic Data
        T_ACCELEROMETER_X, T_ACCELEROMETER_Y, T_ACCELEROMETER_Z,  //float
        T_EULER_X, T_EULER_Y, T_EULER_Z,  //float
        T_TEMPERATURE,  //float
        T_PRESSURE,  //float
        T_SPEED,  //float
        T_ALTITUDE,  //float

        // MetaData
        ALTITUDE_MAX,

        /// Pressure Data
        PP_PRESSURE,//float           **Last pressure reading

        AIR_BRAKES_ANGLE, // float

        // TEST
        TEST_SENSOR_DATA,       // print just for test it's a generic DataType

        /// Tx ignition code
        TX_IGNITION_CODE, //uint8_t     **Extract first 4 lsb for the code.


        /// File transmission
        SEND_FILE_REQUEST, //bool       **true if button on the gui is clicked, eated by Telecom thread
        // File transmitting States
        FILE_TRANSMISSION_MY_STATE, // enum in DataStructures/File
        FILE_TRANSMISSION_RECEIVED_STATE,
        FILE_TRANSMISSION_ALL_RECEIVED, // bool to EAT - for activation of warning window
        SENDING_DATA, //bool      **true when data sending (for Lionel - not print on Gui)

        /// Avionics status variables
        STATUS_AV_ID,
        STATUS_AV_VALUE,
        STATUS_AV_STATE, // enum in DataStructures/Avionics/StateValues.h

        /// GSE orders
        GSE_ORDER_VALUE, //enum in DataStructures/GSE/GSEOrderValues.h

        /// GSE sensors
        GSE_HOSE_PRESSURE,
        GSE_HOSE_TEMP,
        GSE_HOSE_STATUS,
        GSE_MOTOR_SPEED,
        GSE_TANK_WEIGHT,

        /// !!! THIS MUST BE THE LAST LINE !!!
        /// The size of the connected data array
        ARRAY_SIZE
    };

}
#endif //ProtocolDefine_H
