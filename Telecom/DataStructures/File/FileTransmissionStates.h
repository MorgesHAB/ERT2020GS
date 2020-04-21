/*!
 * \file FileTransmissionStates.h
 *
 * \brief FileTransmissionStates module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        05.02.2020	
 */

#ifndef FileTransmissionSates_H
#define FileTransmissionSates_H

#include <string>

enum FileTransmissionStates {
    // Common State
    SLEEP,
    ABORT,
    // Rx State
    SEND_FILE_REQUEST_TO_TX,
    WAITING_PACKET,
    SEND_MISSING_PACKET_REQUEST,
    ALL_RECEIVED,
    // Tx State
    INIT,
    SENDING_PACKET,
    WAITING_MISSING_PACKET_REQUEST,
    SENDING_MISSING_PACKET
};

static std::string getStateName(int state) {
    switch (state) {
        case SLEEP: return "SLEEP";
        case ABORT: return "ABORT";
        case SEND_FILE_REQUEST_TO_TX: return "SEND FILE REQUEST TO TX";
        case WAITING_PACKET: return "WAITING PACKET";
        case SEND_MISSING_PACKET_REQUEST: return "SEND MISSING PACKET REQUEST";
        case ALL_RECEIVED: return "ALL RECEIVED";
        case INIT: return "INIT";
        case SENDING_PACKET: return "SENDING PACKET";
        case WAITING_MISSING_PACKET_REQUEST: return "WAITING MISSING PACKET REQUEST";
        case SENDING_MISSING_PACKET: return "SENDING MISSING PACKET";
        default: return "Unknown";
    }
}


#endif //FileTransmissionSates_H
