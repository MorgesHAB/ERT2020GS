/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file XbeeTest.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 */

#include <Xbee.h>
#include <DataHandler.h>
#include <unistd.h>
#include <string>


int main(int argc, char** argv) {
    // Your RF modem
    Xbee xbee;
    // RF packet handler
    DataHandler dataHandler;

    while (true) {
        // ./XbeeTest Tx            // Transmitter Part
        if (argc == 2 && std::string(argv[1]) == "Tx") {
            dataHandler.update(XBEE_TEST);
            xbee.send(dataHandler.getPacket(XBEE_TEST));
            usleep(50000);
        }
        // ./XbeeTest               // Receiver Part
        else {
            if (xbee.receive(dataHandler.getPacket(XBEE_TEST))) {
                dataHandler.parse(XBEE_TEST);
                dataHandler.print(XBEE_TEST);
            }
            usleep(1);
        }
    }

    return 0;
}