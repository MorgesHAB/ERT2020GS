/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file GST.cpp
 *
 * \brief Ground Station Transceiver
 *
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019	
 */

#include <LoRa.h>
#include <DataHandler.h>


int main() {
    // Your RF modem
    LoRa loRa;
    // RF packet handler
    DataHandler dataHandler;

    std::cout << "\nLoRa Reception is active... waiting for RF packet..." << std::endl;

    dataHandler.update(GPSID);
    loRa.send(dataHandler.getPacket(GPSID));
    // Automatic detection of the packet type - then auto parse
    while (true) {
        if (loRa.receive(dataHandler)) {
            dataHandler.printLastRxPacket();
            uint8_t id(dataHandler.getLastRxID());
            usleep(500000);
            dataHandler.update((PacketID) ((++id) % NBR_OF_TYPE));
            loRa.send(dataHandler.getPacket((PacketID) (id % NBR_OF_TYPE)));
        }
        usleep(10); //microseconds
    }
    return 0;
}
