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

#include <chrono>
#include <thread>

#include <DataHandler.h>
#include <connector.h>
#include <csignal>
#include <LoRa.h>

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
    LoRa loRa;
    connector.setData(ui_interface::SEND_FILE_REQUEST, modeTx);
    // RF packet handler
    DataHandler dataHandler(cptr);
    using namespace DatagramType;

    while (keep_running) {
        // ./XbeeTest Tx            // Transmitter Part
        if (modeTx) {
            dataHandler.updateTx(AV_TELEMETRY);
            loRa.send(dataHandler.getPacket(AV_TELEMETRY));

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
            // ./XbeeTest               // Receiver Part
        else {
            if (loRa.receive(dataHandler)) {
                dataHandler.printLastRxPacket();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    return 0;
}