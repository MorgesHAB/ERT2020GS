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
        INIT,

        AV_GPS,
        AV_STATUS,
        AV_TELEMETRY,
        AV_DEBUG,

        PROPULSION,
        AIR_BRAKES,

        GSE_ORDER,
        GSE_STATUS,
        GSE_IGNITION,

        PL_INFO,
        PL_IMAGE,

        ACK,
        // TEST PACKET
        IMAGE,
        IGNITION_ANSWER,
        TEST,
                            // <-- add new type here

        /////////////////////////////////////////
        TOTAL_NBR_OF_TYPES  // <-- size of the array - keep at the end
    };


    static std::string getDatagramIDName(DatagramID DatagramID) {
        switch (DatagramID) {
            case AV_GPS: return "AV GPS";
            case AV_STATUS: return "AV STATUS";
            case AV_TELEMETRY: return "AV TELEMETRY";
            case AV_DEBUG: return "AV DEBUG";
            case PROPULSION: return "PROPULSION";
            case AIR_BRAKES: return "AIR BRAKES";
            case GSE_ORDER: return "GSE ORDER";
            case GSE_STATUS: return "GSE STATUS";
            case GSE_IGNITION: return "GSE IGNITION";
            case PL_INFO: return "PL INFO";
            case PL_IMAGE: return "PL IMAGE";
            case IMAGE: return "Image";
            case TEST: return "TEST";
            case IGNITION_ANSWER: return "Ignition Response";
            default: return "Unknown";
        }
    }

} // namespace

#endif //DatagramTypes_H
