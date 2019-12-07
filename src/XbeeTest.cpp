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

#include <chrono>
#include <thread>
//#include <unistd.h>

#include <Xbee.h>
#include <DataHandler.h>
#include <connector.h>
#include <string>
#include <csignal>

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _) {
    (void)_;
    keep_running = 0;
}

int main(int argc, char** argv) {

    signal(SIGINT, sig_handler);

    bool modeTx(argc == 2 && std::string(argv[1]) == "Tx");

    Connector connector;
    std::shared_ptr<Connector> cptr(&connector);

    // Your RF modem
    Xbee xbee("/dev/ttyS3");
    // RF packet handler
    DataHandler dataHandler(cptr);
    //usleep(10000000);
    while (keep_running) {
        // ./XbeeTest Tx            // Transmitter Part
        if (modeTx) {
            PacketID ID = static_cast<PacketID> (rand() % NBR_OF_TYPE);
            dataHandler.updateTx(ID);
            xbee.send(dataHandler.getPacket(ID));

            //dataHandler.update(XBEE_TEST);
            //xbee.send(dataHandler.getPacket(XBEE_TEST));
           // return 0;
            //usleep(1000);
            std::this_thread::sleep_for(std::chrono::microseconds(1000));
        }
        // ./XbeeTest               // Receiver Part
        else {
           /* if (xbee.receive(dataHandler.getPacket(XBEE_TEST))) {
                dataHandler.parse(XBEE_TEST);
                dataHandler.print(XBEE_TEST);
            }*/
            if (xbee.receive(dataHandler)) {
                dataHandler.printLastRxPacket();
            }
            //usleep(100); //  TODO
            //std::this_thread::sleep_for(std::chrono::milliseconds(7));
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
    }

    return 0;
}