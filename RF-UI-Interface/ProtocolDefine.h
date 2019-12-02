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
    // Qt input informations
    QT_LAUNCH_BUTTON,


    // Header
    PACKET_ID, PACKET_NBR, TIMESTAMP,

    // GPS Data Structure
    ALTITUDE, LONGITUDE, LATITUDE, SPEED, TIME,

    // Pressure Data
    PRESSURE_DATA,



    // !!! THIS MUST BE THE LAST LINE !!!
    // At the end the vector size
    ARRAY_SIZE
};

}
#endif //ProtocolDefine_H
