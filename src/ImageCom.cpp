/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file ImageCom.cpp
 *
 * \brief Image communication main for the Transmitter
 * Send an image / Picture if a request is received
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
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

    signal(SIGINT, sig_handler);

    Connector connector;
    std::shared_ptr<Connector> cptr(&connector);

    // Your RF modem
    Xbee xbee("/dev/" + std::string((argc == 2) ? argv[1] : "ttyUSB0"));
    // RF packet handler
    DataHandler dataHandler(cptr);
    using namespace DatagramType;

    while (keep_running) {
        if (xbee.receive(dataHandler)) dataHandler.printLastRxPacket();

        if (connector.getData<bool>(ui_interface::SENDING_DATA)) {
            dataHandler.updateTx(PL_IMAGE);
            xbee.send(dataHandler.getPacket(PL_IMAGE));
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}