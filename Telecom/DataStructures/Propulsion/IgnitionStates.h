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

namespace ignit {

    enum IgnitionState {
        SLEEP,
        WRONG_CODE_RECEIVED,
        ARMED,
        IGNITION_ON
    };

} // namespace


#endif //IgnitionStates_H
