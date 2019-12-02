/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file LoRaTest.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 */

#include <LoRa.h>
#include <DataHandler.h>
#include <unistd.h>
#include <string>


int main(int argc, char** argv) {
    // Your RF modem
    LoRa loRa;
    // RF packet handler
    DataHandler dataHandler;

    while (true) {
        // ./LoRaTest Tx            // Transmitter Part
        if (argc == 2 && std::string(argv[1]) == "Tx") {
            dataHandler.update(XBEE_TEST);
            loRa.send(dataHandler.getPacket(XBEE_TEST));
            usleep(50000);
        }
        // ./LoRaTest               // Receiver Part
        else {
            if (loRa.receive(dataHandler.getPacket(XBEE_TEST))) {
                dataHandler.parse(XBEE_TEST);
                dataHandler.print(XBEE_TEST);
            }
            usleep(1);
        }
    }

    return 0;
}