/*!
 * \file IgnitionCode.cpp
 *
 * \brief IgnitionCode module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        07.12.2019	
 */
// Configuration of the GPIO pin of the Raspberry Pi 4
//  /!\ it's the nbr in BCM format, not the pin number
// GPIO which activates the relay which activates the igniter
#define GPIO_OUT_IGNITION       20
// GPIO input on the Ground Station
#define GPIO_IN_KEY_1           11
#define GPIO_IN_KEY_2           10
#define GPIO_IN_RED_BUTTON      9
// GPIO output of the red button LED
#define GPIO_OUT_LED_BUTTON     23
// GPIO on the RPi to read the ignition code via the switches
// Code order on the dipswitch from left to right : code 3 | code 2 | code 1 | code 0
#define GPIO_IN_CODE0           25
#define GPIO_IN_CODE1           24
#define GPIO_IN_CODE2           27
#define GPIO_IN_CODE3           22
//////////////////////////////////////
// This data is composed of boolean states => 4 states for the ignition code
// So to minimize the packet size, we combine all these states in a byte (8 bits)
// Packet :  [ - | - | - | - | code 3 | code 2 | code 1 | code 0 LSB  ]

#ifdef RUNNING_ON_RPI
#include <wiringPi.h>

#include "IgnitionCode.h"


IgnitionCode::IgnitionCode() : states(4, false), ignitionState(ignit::SLEEP) {
    wiringPiSetupGpio();
    // Configure GPIO OUT for the igniter
    pinMode(GPIO_OUT_IGNITION, OUTPUT);
    digitalWrite(GPIO_OUT_IGNITION, LOW);
    // Configure the red button LED
    pinMode(GPIO_OUT_LED_BUTTON, OUTPUT);
    digitalWrite(GPIO_OUT_LED_BUTTON, LOW);
    // Configure GPIO pins as an input
    pinMode(GPIO_IN_KEY_1, INPUT);
    pinMode(GPIO_IN_KEY_2, INPUT);
    pinMode(GPIO_IN_RED_BUTTON, INPUT);

    pinMode(GPIO_IN_CODE0, INPUT);
    pinMode(GPIO_IN_CODE1, INPUT);
    pinMode(GPIO_IN_CODE2, INPUT);
    pinMode(GPIO_IN_CODE3, INPUT);
}

void IgnitionCode::updateTx(std::shared_ptr<Connector> connector) {
    // run on GST
    // Read Data to print on Gui for visual confirmation of component operation
    bool key1(digitalRead(GPIO_IN_KEY_1)), key2(digitalRead(GPIO_IN_KEY_2));
    connector->setData(ui_interface::IGNITION_KEY_1_ACTIVATED, key1);
    connector->setData(ui_interface::IGNITION_KEY_2_ACTIVATED, key2);
    if (key1 && key2 && connector->getData<bool>(ui_interface::IGNITION_CLICKED)) {
        digitalWrite(GPIO_OUT_LED_BUTTON, HIGH);
    } else {
        digitalWrite(GPIO_OUT_LED_BUTTON, LOW);
    }
    connector->setData(ui_interface::IGNITION_RED_BUTTON_PUSHED,
                       digitalRead(GPIO_IN_RED_BUTTON));

    states[0] = digitalRead(GPIO_IN_CODE0);
    states[1] = digitalRead(GPIO_IN_CODE1);
    states[2] = digitalRead(GPIO_IN_CODE2);
    states[3] = digitalRead(GPIO_IN_CODE3);
    uint8_t code(states[3] << 3 | states[2] << 2 | states[1] << 1 | states[0]);
    connector->setData(ui_interface::TX_IGNITION_CODE, code);
}

void IgnitionCode::write(Packet &packet) {
    uint8_t statePacket(0);
    for (uint8_t i(0); i < states.size(); ++i) {
        statePacket |= states[i] << i;
    }
    packet.write(statePacket);
}


void IgnitionCode::parse(Packet &packet) {
    uint8_t statePacket(0);
    packet.parse(statePacket);
    for (uint8_t i(0); i < states.size(); ++i) {
        states[i] = statePacket & (1 << i);
    }
}

void IgnitionCode::updateRx(std::shared_ptr<Connector> connector) {
    // run on GSE
    using namespace ignit;
    std::vector<int> codeRx = {digitalRead(GPIO_IN_CODE0),
                               digitalRead(GPIO_IN_CODE1),
                               digitalRead(GPIO_IN_CODE2),
                               digitalRead(GPIO_IN_CODE3)};

    std::cout << "=> Ignition code read on Rx side : [ " << codeRx[3] << " "
              << codeRx[2] << " " << codeRx[1] << " " << codeRx[0] << " ]" << std::endl;

    // The code "0000" is not allowed (avoid the case if at initialization all is 0)
    if (!(codeRx[0] == 0 && codeRx[1] == 0 && codeRx[2] == 0 && codeRx[3] == 0) &&
        codeRx[0] == states[0] && codeRx[1] == states[1] && codeRx[2] == states[2] &&
        codeRx[3] == states[3]) {
        switch (ignitionState) {
            case WRONG_CODE_RECEIVED:
            case SLEEP:
                ignitionState = ARMED;
                digitalWrite(GPIO_OUT_IGNITION, LOW); // safe
                break;
            case ARMED:
                std::cout << "Code Rx & Tx are identical => GPIO ignition HIGH !!" << std::endl;
                ignitionState = IGNITION_ON;
                connector->setData(ui_interface::IGNITION_STATUS, ignitionState);
                digitalWrite(GPIO_OUT_IGNITION, HIGH); // /!\ Ignition !!!!!!!!
                ignitionState = SLEEP;
            default:
                break;
        }
    } else { //TODO: Send packet too!
        std::cout << "Code aren't identical : ignition aborted" << std::endl;
        digitalWrite(GPIO_OUT_IGNITION, LOW);
        ignitionState = WRONG_CODE_RECEIVED;
        connector->setData(ui_interface::IGNITION_STATUS, ignitionState);
    }
}

void IgnitionCode::print() const {
    std::cout << "Tx Ignition code : [ " << states[3] << " " << states[2] << " "
              << states[1] << " " << states[0] << " ]" << std::endl;
}

#endif
