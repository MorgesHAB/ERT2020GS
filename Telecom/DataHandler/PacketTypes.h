/*!
 * \file PacketTypes.h
 *
 * \brief Packet Types definition
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        18.11.2019
 */

#ifndef PacketTypes_H
#define PacketTypes_H


namespace packetType {
    // Definition of the content of the packets take place in the
    // DataHandler constructor

    // Don't forget to modify header::print() when adding new packet type
    enum PacketID {
        GPSID, PAYLOAD, AVIONICS, PROPULSION, XBEE_TEST,

        TX_TYPE_NBR,    // tmp use for random packet type send

        IMAGE,
        IGNITION_REQUEST,
        IGNITION_ANSWER,
                            // <-- add new type here

        /////////////////////////////////////////
        TOTAL_NBR_OF_TYPES  // <-- size of the array - keep at the end
    };


    static std::string getPacketIDName(int packetID) {
        switch (packetID) {
            case GPSID: return "GPS";
            case PAYLOAD: return "Payload";
            case AVIONICS: return "Avionics";
            case PROPULSION: return "Propulsion";
            case IMAGE: return "Image";
            case XBEE_TEST: return "Xbee frame";
            case IGNITION_REQUEST: return "Propulsion Ignition Order !";
            case IGNITION_ANSWER: return "Ignition Response";
            default: return "Unknown";
        }
    }

} // namespace

#endif //PacketTypes_H
