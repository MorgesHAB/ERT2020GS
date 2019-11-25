/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file GSE.cpp
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
        if (argc == 2 && std::string(argv[1]) == "Tx") {
            xbee.send();
            usleep(500000);
        }
        else {
            xbee.receive();
            usleep(1);
        }
    }

    return 0;
}