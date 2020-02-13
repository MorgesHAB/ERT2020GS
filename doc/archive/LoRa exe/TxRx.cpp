/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file TxRx.cpp
 *
 * \brief Ground Station Transceiver
 *
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 *
 * This test program can be use to test the communication between two LoRa modem
 * Start the first LoRa with :     ./TxRx
 * On the 2nd one run :            ./TxRx 0        // start to send packet type 0
 * Now let the two modem communicate automatically. They will exchange some
 * datagram together. In fact if one received the DatagramID n it will send the n + 1
 * DatagramID
 *
 */

#include <LoRa.h>
#include <DataHandler.h>


int main(int argc, char** argv) {
    // Your RF modem
    LoRa loRa;
    // RF packet handler
    DataHandler dataHandler;

    std::cout << "\nLoRa Reception is active... waiting for RF packet..." << std::endl;

    // ./TxRx X        X = Packet Type nbr {1,2,3,4}
    if (argc == 2) {
        DatagramID type = (DatagramID) atoi(argv[1]);
        if (type >= TOTAL_NBR_OF_TYPES || type < 0) {
            std::cout << "Type invalid" << std::endl;
            return 0;
        }
        dataHandler.update(type);
        loRa.send(dataHandler.getPacket(type));
    }

    // Automatic detection of the packet type - then auto parse
    while (true) {
        if (loRa.receive(dataHandler)) {
            dataHandler.printLastRxPacket();
            uint8_t id(dataHandler.getLastRxID());
            usleep(500000);
            dataHandler.update((DatagramID) ((++id) % NBR_OF_TYPE));
            loRa.send(dataHandler.getPacket((DatagramID) (id % NBR_OF_TYPE)));
        }
        usleep(10); //microseconds
    }
    return 0;
}
