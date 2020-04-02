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

        /// Avionic Datagram
            AV_GPS,
            AV_STATUS,
            AV_TELEMETRY,
            AV_DEBUG,

        /// GSE Datagram
            GSE_ORDER,
            GSE_STATUS,
            GSE_IGNITION,

        /// Payload Datagram
            PL_IMAGE,
            PL_STATE,
            PL_GPS,
            PL_ORDER,

        /// Propulsion Datagram
            PROPULSION,

        /// Air Brakes Datagram
            AIR_BRAKES,

        /// [Subsystem Name] Datagram
        /// ...
                            // <-- add new type here

        /// TEST PACKET
            ACK,
            IGNITION_ANSWER,
            TEST,

                            // <-- add new type here

        /////////////////////////////////////////
        TOTAL_NBR_OF_TYPES  // <-- size of the array - keep at the end
    };


    static std::string getDatagramIDName(uint8_t DatagramID) {
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
            case PL_STATE: return "PL STATE";
            case PL_IMAGE: return "PL IMAGE";
            case PL_GPS: return "PL GPS";
            case PL_ORDER: return "PL ORDER";
            case TEST: return "TEST";
            case IGNITION_ANSWER: return "Ignition Response";
            default: return "Unknown";
        }
    }

} // namespace

#endif //DatagramTypes_H
