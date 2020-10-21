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
#define GPIO_IN_KEY_1           24  //WHITE-ORANGE
#define GPIO_IN_KEY_2           25  //WHITE-BLUE
#define GPIO_IN_RED_BUTTON      23  //BLUE 
// GPIO output of the red button LED
#define GPIO_OUT_LED_BUTTON     22 //WHITE-BROWN EXT
// GPIO on the RPi to read the ignition code via the switches
// Code order on the dipswitch from left to right : code 3 | code 2 | code 1 | code 0
#define GPIO_IN_CODE0           8 //WHITE-GREEN
#define GPIO_IN_CODE1           11 //GREEN
#define GPIO_IN_CODE2           9 //WHITE-BROWN
#define GPIO_IN_CODE3           10 //PURPLE

#define SHUTDOWN_TIME           10000000 // on RPi should be 10000
//////////////////////////////////////
// This data is composed of boolean states => 4 states for the ignition code
// So to minimize the packet size, we combine all these states in a byte (8 bits)
// Packet :  [ - | - | - | - | code 3 | code 2 | code 1 | code 0 LSB  ]

#ifdef RUNNING_ON_RPI
#include <wiringPi.h>
#endif

#include "IgnitionCode.h"
#include "GSEOrderValue.h"

static const uint8_t MAIN_IGNITION_ON = 0x0C;
static const uint8_t MAIN_IGNITION_OFF = 0x0D;


// #define RUNNING_ON_RPI
using namespace ignit;

IgnitionCode::IgnitionCode() : code({false}), ignitionCode(0), order(MAIN_IGNITION_ON) {
#ifdef RUNNING_ON_RPI
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
#endif
}

bool IgnitionCode::updateTx(std::shared_ptr<Connector> connector) {

#ifdef RUNNING_ON_RPI
    // run on GST
    // Read Data to print on Gui for visual confirmation of component operation
    bool key1(digitalRead(GPIO_IN_KEY_1)), key2(digitalRead(GPIO_IN_KEY_2));
    connector->setData(ui_interface::IGNITION_KEY_1_ACTIVATED, key1);
    connector->setData(ui_interface::IGNITION_KEY_2_ACTIVATED, key2);
    if (key1 && key2 &&
        connector->getData<bool>(ui_interface::IGNITION_CLICKED)) {
        digitalWrite(GPIO_OUT_LED_BUTTON, HIGH);
    } else {
        digitalWrite(GPIO_OUT_LED_BUTTON, LOW);
    }
    bool redButtonPressed(digitalRead(GPIO_IN_RED_BUTTON));
    connector->setData(ui_interface::IGNITION_RED_BUTTON_PUSHED,
                       redButtonPressed);

    code[0] = digitalRead(GPIO_IN_CODE0);
    code[1] = digitalRead(GPIO_IN_CODE1);
    code[2] = digitalRead(GPIO_IN_CODE2);
    code[3] = digitalRead(GPIO_IN_CODE3);
    std::cout << code[0] << code[1] << code[2] << code[3] << std::endl;
    ignitionCode = code[3] << 3 | code[2] << 2 | code[1] << 1 | code[0];
    connector->setData(ui_interface::TX_IGNITION_CODE, ignitionCode);

    // true if send Ignition packet
    if (key1 && key2 && redButtonPressed &&
        connector->eatData<bool>(ui_interface::IGNITION_CLICKED, false)) {
        return true;    // Ignition will be sent
    }
    return false;
#endif
}

void IgnitionCode::write(Packet &packet) {
    packet.write(order);
    packet.write(ignitionCode);
}


void IgnitionCode::parse(Packet &packet) {
    packet.parse(order);
    packet.parse(ignitionCode);
    for (uint8_t i(0); i < code.size(); ++i) {
        code[i] = ignitionCode & (1 << i);
    }
}

bool IgnitionCode::updateRx(std::shared_ptr<Connector> connector) {
#ifdef RUNNING_ON_RPI
/*

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
        codeRx[0] == code[0] && codeRx[1] == code[1] && codeRx[2] == code[2] &&
        codeRx[3] == code[3]) {
        switch (myState) {
            case WRONG_CODE_RECEIVED:
            case SLEEP:
                if (receivedState == WAITING_ARMED_VALIDATION) {
                    myState = ARMED;
                    std::cout << "Code are identical => Armed !!" << std::endl;
                }
                digitalWrite(GPIO_OUT_IGNITION, LOW); // safe
                break;
            case ARMED:
                if (receivedState == WAITING_IGNITION_VALIDATION) {
                    std::cout << "Code Rx & Tx are identical => GPIO ignition HIGH !!" << std::endl;
                    myState = IGNITION_ON;
                    digitalWrite(GPIO_OUT_IGNITION, HIGH); // /!\ Ignition !!!!!!!!
                    ignitionTime = clock();
                }
            default:
                break;
        }
    } else {
        std::cout << "Code aren't identical : ignition aborted" << std::endl;
        digitalWrite(GPIO_OUT_IGNITION, LOW);
        myState = WRONG_CODE_RECEIVED;
    }

    return true;
    */
    
#endif
}

void IgnitionCode::print() const {
    std::cout << "Tx Ignition code : [ " << code[3] << " " << code[2] << " "
              << code[1] << " " << code[0] << " ]" << std::endl;
}
