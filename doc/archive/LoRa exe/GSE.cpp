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

#include <LoRa.h>
#include <DataHandler.h>
#include <Header.h>


int main(int argc, char** argv) {
    // Your RF modem
    LoRa loRa;
    // RF packet handler
    DataHandler dataHandler;

    // ./GSE X        X = Packet Type nbr {1,2,3,4}
    if (argc == 2) {
        DatagramID type = (DatagramID) atoi(argv[1]);
        if (type >= NBR_OF_TYPE || type < 0) {
            std::cout << "Type invalid" << std::endl;
            return 0;
        }
        dataHandler.update(type);
        loRa.send(dataHandler.getPacket(type));
        Header(type).print();
        return 0;
    }

    while (true) {
      //  dataHandler.update(PAYLOAD);
       // loRa.send(dataHandler.getPacket(PAYLOAD));
        dataHandler.update(IMAGE);
        loRa.send(dataHandler.getPacket(IMAGE));
        usleep(100000);
    }

    return 0;
}