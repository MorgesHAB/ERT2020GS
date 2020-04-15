/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file AVsimulator.cpp
 *
 * \brief simulate the Avionic onboard computer
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        02.04.2020
 */

#include <chrono>
#include <thread>

#include <Xbee.h>
#include <DataHandler.h>
#include <connector.h>
#include <csignal>

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _) {
    (void)_;
    keep_running = 0;
}

int main(int argc, char** argv) {
    std::cout << "Transmit syntax : ./AVsimulator ttyUSB0 Tx" << std::endl;
    std::cout << "Receive syntax :  ./AVsimulator ttyS3 Rx" << std::endl;


    signal(SIGINT, sig_handler);

    bool modeTx((argc == 3) && (std::string(argv[2]) == "Tx"));
    Connector connector;
    std::shared_ptr<Connector> cptr(&connector);

    // Your RF modem
    Xbee xbee("/dev/" + ((argc == 3) ? std::string(argv[1]) : "ttyUSB0"));
    // RF packet handler
    DataHandler dataHandler(cptr);
    using namespace DatagramType;

    while (keep_running) {
        // ./XbeeTest Tx            // Transmitter Part
        if (modeTx) {
            dataHandler.updateTx(AV_TELEMETRY);
            xbee.send(dataHandler.getPacket(AV_TELEMETRY));
            dataHandler.updateTx(AV_GPS);
            xbee.send(dataHandler.getPacket(AV_GPS));
            dataHandler.updateTx(AV_STATUS);
            xbee.send(dataHandler.getPacket(AV_STATUS));

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        // ./XbeeTest               // Receiver Part
        else {
            if (xbee.receive(dataHandler)) {
                dataHandler.printLastRxPacket();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(7));
        }
    }
    return 0;
}