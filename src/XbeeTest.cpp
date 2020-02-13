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

    bool modeTx(argc == 3 && std::string(argv[2]) == "Tx");

    Connector connector;
    std::shared_ptr<Connector> cptr(&connector);

    // Your RF modem
    Xbee xbee("/dev/" + std::string((argc == 2) ? argv[1] : "ttyUSB0"));
    connector.setData(ui_interface::SEND_FILE_REQUEST, modeTx);
    // RF packet handler
    DataHandler dataHandler(cptr);
    using namespace DatagramType;

    while (keep_running) {
        // ./XbeeTest Tx            // Transmitter Part
        if (modeTx) {
            DatagramID ID = static_cast<DatagramID> (rand() % (TX_TYPE_NBR));
            dataHandler.updateTx(ID);
            xbee.send(dataHandler.getPacket(ID));

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