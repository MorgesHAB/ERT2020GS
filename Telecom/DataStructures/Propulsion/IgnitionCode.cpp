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
#define GPIO_IN_KEY             0
#define GPIO_IN_RED_BUTTON      5
// GPIO on the RPi to read the ignition code via the switches
#define GPIO_IN_CODE1           6
#define GPIO_IN_CODE2           13
#define GPIO_IN_CODE3           19
#define GPIO_IN_CODE4           26
//////////////////////////////////////
// This data is composed of boolean states => 4 states for the ignition code
// So to minimize the packet size, we combine all these states in a byte (8 bits)
// Packet :  [ code 1 MSB | code 2 | code 3 | code 4 LSB | - | - | - | - ]


#include <wiringPi.h>
#include "IgnitionCode.h"


IgnitionCode::IgnitionCode() : states(4, false) {
    wiringPiSetupGpio();
    // Configure GPIO OUT for the igniter
    pinMode(GPIO_OUT_IGNITION, OUTPUT);
    digitalWrite(GPIO_OUT_IGNITION, LOW);
    // Configure GPIO pins as an input
    pinMode(GPIO_IN_KEY, INPUT);
    pinMode(GPIO_IN_RED_BUTTON, INPUT);

    pinMode(GPIO_IN_CODE1, INPUT);
    pinMode(GPIO_IN_CODE2, INPUT);
    pinMode(GPIO_IN_CODE3, INPUT);
    pinMode(GPIO_IN_CODE4, INPUT);
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

void IgnitionCode::print() const {
    std::cout << "Tx Ignition code : [ " << states[0] << " " << states[1] << " "
              << states[2] << " " << states[3] << " ]" << std::endl;
}

void IgnitionCode::updateTx(std::shared_ptr<Connector> connector) {
    // run on GST
    // Read Data to print on Gui for visual confirmation of component operation
    connector->setData(ui_interface::IGNITION_KEY_ACTIVATED,
                       digitalRead(GPIO_IN_KEY));
    connector->setData(ui_interface::IGNITION_RED_BUTTON_PUSHED,
                       digitalRead(GPIO_IN_RED_BUTTON));

    states[0] = digitalRead(GPIO_IN_CODE1);
    states[1] = digitalRead(GPIO_IN_CODE2);
    states[2] = digitalRead(GPIO_IN_CODE3);
    states[3] = digitalRead(GPIO_IN_CODE4);
    uint8_t code(states[3] << 3 | states[2] << 2 | states[1] << 1 | states[0]);
    connector->setData(ui_interface::TX_IGNITION_CODE, code);
}

void IgnitionCode::updateRx(std::shared_ptr<Connector> connector) {
    // run on GSE
    std::vector<int> codeRx = {digitalRead(GPIO_IN_CODE1),
                               digitalRead(GPIO_IN_CODE2),
                               digitalRead(GPIO_IN_CODE3),
                               digitalRead(GPIO_IN_CODE4)};

    std::cout << "=> Ignition code read on Rx side : [ " << codeRx[0] << " "
              << codeRx[1] << " " << codeRx[2] << " " << codeRx[3] << " ]" << std::endl;

    // The code "0000" is not allowed (avoid the case if at initialization all is 0)
    if (!(codeRx[0] == 0 && codeRx[1] == 0 && codeRx[2] == 0 && codeRx[3] == 0) &&
        codeRx[0] == states[0] && codeRx[1] == states[1] && codeRx[2] == states[2] &&
        codeRx[3] == states[3]) {
        std::cout << "Code Rx & Tx are identical => GPIO ignition HIGH !!" << std::endl;
        digitalWrite(GPIO_OUT_IGNITION, HIGH);
        connector->setData(ui_interface::IGNITION_STATUS, true);

    } else {
        std::cout << "Code aren't identical : ignition aborted" << std::endl;
        digitalWrite(GPIO_OUT_IGNITION, LOW);
        connector->setData(ui_interface::IGNITION_STATUS, false);
    }
}
