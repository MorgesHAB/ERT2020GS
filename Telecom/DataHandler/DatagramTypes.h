#include <string>

/*!
 * \file DatagramTypes.h
 *
 * \brief Packet Types definition
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019
 */

#ifndef DatagramTypes_H
#define DatagramTypes_H


namespace DatagramType {
    // Definition of the content of the packets take place in the
    // DataHandler constructor

    // Don't forget to modify header::print() when adding new packet type
    enum DatagramID {
        INIT, // ID = 0 not used

        //TODO This may change for project 2021, no ability to add a random packet ID without using empty enums
        /// Avionic Datagram

            AV_GPS,                 //ID: 0x01
            AV_STATUS,              //ID: 0x02
            AV_TELEMETRY,           //ID: 0x03
            AV_DEBUG,               //ID: 0x04




        /// GSE Datagram
            EMPTY5,              //ID: 0x05
            EMPTY6,              //ID: 0x06
            GSE_IGNITION,        //ID: 0x07

        /// Payload Datagram
            EMPTY8,              //ID: 0x08
            GSE_ORDER,           //ID: 0x09
            GSE_SENSORS,         //ID: 0x0a
            GSE_PING,            //ID: 0x0b
            PP_COMMAND,          //ID: 0x0c
            PP_DATA,             //ID: 0x0d

        /// TVC Datagram
            TVC_COMMAND,         //ID: 0x0e
            TVC_STATUS,          //ID: 0xef

        /// Air Brakes Datagram
            EMPTY16,
            EMPTY17,
            EMPTY18,
            EMPTY19,
            PL_TEMP,
            PL_BNO_SENSOR,
            PL_BME_SENSOR,
            PL_GPS,
            PL_ORDER,
            PL_STATE,
            PL_IMAGE,

        /// [Subsystem Name] Datagram
        /// ...
                            // <-- add new type here

        /// TEST PACKET
            TEST,

                            // <-- add new type here

                                            //ID: 0x11
                                            //ID: 0x12
                                            //ID: 0x13
                                            //ID: 0x14
                                            //ID: 0x15
                                            //ID: 0x16
                                            //ID: 0x17
                                            //ID: 0x18
                                            //ID: 0x19
                                            //ID: 0x1a
                                            //ID: 0x1b
                                            //ID: 0x1c
                                            //ID: 0x1d
                                            //ID: 0x1e
                                            //ID: 0x1f
                                            //ID: 0x20
                                            //ID: 0x21
                                            //ID: 0x22
                                            //ID: 0x23
                                            //ID: 0x24
                                            //ID: 0x25
                                            //ID: 0x26
                                            //ID: 0x27
                                            //ID: 0x28
                                            //ID: 0x29
                                            //ID: 0x2a
                                            //ID: 0x2b
                                            //ID: 0x2c
                                            //ID: 0x2d
                                            //ID: 0x2e
                                            //ID: 0x2f
                                            //ID: 0x30
                                            //ID: 0x31
                                            //ID: 0x32
                                            //ID: 0x33
                                            //ID: 0x34
                                            //ID: 0x35
                                            //ID: 0x36
                                            //ID: 0x37
                                            //ID: 0x38
                                            //ID: 0x39
                                            //ID: 0x3a
                                            //ID: 0x3b
                                            //ID: 0x3c
                                            //ID: 0x3d
                                            //ID: 0x3e
                                            //ID: 0x3f
                                            //ID: 0x40
                                            //ID: 0x41
                                            //ID: 0x42
                                            //ID: 0x43
                                            //ID: 0x44
                                            //ID: 0x45
                                            //ID: 0x46
                                            //ID: 0x47
                                            //ID: 0x48
                                            //ID: 0x49
                                            //ID: 0x4a
                                            //ID: 0x4b
                                            //ID: 0x4c
                                            //ID: 0x4d
                                            //ID: 0x4e
                                            //ID: 0x4f
                                            //ID: 0x50
                                            //ID: 0x51
                                            //ID: 0x52
                                            //ID: 0x53
                                            //ID: 0x54
                                            //ID: 0x55
                                            //ID: 0x56
                                            //ID: 0x57
                                            //ID: 0x58
                                            //ID: 0x59
                                            //ID: 0x5a
                                            //ID: 0x5b
                                            //ID: 0x5c
                                            //ID: 0x5d
                                            //ID: 0x5e
                                            //ID: 0x5f
                                            //ID: 0x60
                                            //ID: 0x61
                                            //ID: 0x62
                                            //ID: 0x63
                                            //ID: 0x64
                                            //ID: 0x65
                                            //ID: 0x66
                                            //ID: 0x67
                                            //ID: 0x68
                                            //ID: 0x69
                                            //ID: 0x6a
                                            //ID: 0x6b
                                            //ID: 0x6c
                                            //ID: 0x6d
                                            //ID: 0x6e
                                            //ID: 0x6f
                                            //ID: 0x70
                                            //ID: 0x71
                                            //ID: 0x72
                                            //ID: 0x73
                                            //ID: 0x74
                                            //ID: 0x75
                                            //ID: 0x76
                                            //ID: 0x77
                                            //ID: 0x78
                                            //ID: 0x79
                                            //ID: 0x7a
                                            //ID: 0x7b
                                            //ID: 0x7c
                                            //ID: 0x7d
                                            //ID: 0x7e
                                            //ID: 0x7f
                                            //ID: 0x80
                                            //ID: 0x81
                                            //ID: 0x82
                                            //ID: 0x83
                                            //ID: 0x84
                                            //ID: 0x85
                                            //ID: 0x86
                                            //ID: 0x87
                                            //ID: 0x88
                                            //ID: 0x89
                                            //ID: 0x8a
                                            //ID: 0x8b
                                            //ID: 0x8c
                                            //ID: 0x8d
                                            //ID: 0x8e
                                            //ID: 0x8f
                                            //ID: 0x90
                                            //ID: 0x91
                                            //ID: 0x92
                                            //ID: 0x93
                                            //ID: 0x94
                                            //ID: 0x95
                                            //ID: 0x96
                                            //ID: 0x97
                                            //ID: 0x98
                                            //ID: 0x99
                                            //ID: 0x9a
                                            //ID: 0x9b
                                            //ID: 0x9c
                                            //ID: 0x9d
                                            //ID: 0x9e
                                            //ID: 0x9f
        /////////////////////////////////////////
        TOTAL_NBR_OF_TYPES  // <-- size of the array - keep at the end
    };


    static std::string getDatagramIDName(uint8_t DatagramID) {
        switch (DatagramID) {
            case AV_GPS: return "AV-GPS";
            case AV_STATUS: return "AV-STATUS";
            case AV_TELEMETRY: return "AV-TELEMETRY";
            case AV_DEBUG: return "AV-DEBUG";
            case TVC_COMMAND: return "TVC-COMMAND";
            case TVC_STATUS: return "TVC-STATUS";
            case PP_COMMAND: return "PP-COMMAND";
            case PP_DATA: return "PP-DATA";
            //case AIR_BRAKES: return "AIR-BRAKES";
            case GSE_ORDER: return "GSE-ORDER";
            case GSE_SENSORS: return "GSE-SENSORS";
            case GSE_IGNITION: return "GSE-IGNITION";
            case GSE_PING: return "GSE-PING";
            case PL_STATE: return "PL-STATE";
            case PL_IMAGE: return "PL-IMAGE";
            case PL_GPS: return "PL-GPS";
            case PL_ORDER: return "PL-ORDER";
            case PL_BME_SENSOR: return "PL-BME-SENSOR";
            case PL_BNO_SENSOR: return "PL-BNO-SENSOR";
            case TEST: return "TEST";
            default: return "Unknown";
        }
    }

} // namespace

#endif //DatagramTypes_H

