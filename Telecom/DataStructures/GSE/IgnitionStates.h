/*!
 * \file IgnitionStates.h
 *
 * \brief IgnitionStates module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.03.2020	
 */

#ifndef IgnitionStates_H
#define IgnitionStates_H

#include <string>

namespace ignit {

    enum IgnitionState {
        SLEEP,
        // GSE States
        WRONG_CODE_RECEIVED,
        ARMED,
        IGNITION_ON,
        // GST States
        WAITING_ARMED_VALIDATION,
        WAITING_IGNITION_VALIDATION,
    };

    //For GUI
    static std::string getIgnitionState(uint8_t state) {
        switch (state) {
            case SLEEP: return "SLEEP";
            case WRONG_CODE_RECEIVED: return "Wrong Code on GSE";
            case ARMED: return "ARMED";
            case IGNITION_ON: return "IGNITION ON !!";
            case WAITING_ARMED_VALIDATION: return "Waiting Armed validation";
            case WAITING_IGNITION_VALIDATION: return "Waiting Ignition validation";
            default: return "Unknown";
        }
    }

} // namespace


#endif //IgnitionStates_H
