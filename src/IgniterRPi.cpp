/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file IgniterRPi.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 */

#include <Xbee.h>
#include <DataHandler.h>
#include <csignal>
#include <GSE/IgnitionStates.h>

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _) {
    (void)_;
    keep_running = 0;
}

int main(int argc, char** argv) {

    signal(SIGINT, sig_handler);

    Connector connector;
    std::shared_ptr<Connector> cptr(&connector);

    // Your RF modem
    Xbee xbee("/dev/ttyUSB0");
    // RF packet handler
    DataHandler dataHandler(cptr);
    using namespace DatagramType;

    while (keep_running) {
        // Generate fake communication flow during ignition
        DatagramID ID = AV_TELEMETRY;
        dataHandler.updateTx(ID);
        xbee.send(dataHandler.getPacket(ID));

        if (xbee.receive(dataHandler)) {
            dataHandler.printLastRxPacket();
        }

        if (dataHandler.updateTx(GSE_IGNITION)) {
            for (int i(0); i < 5; ++i) {
                xbee.send(dataHandler.getPacket(GSE_IGNITION)); // Send 5 times ignition status
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}