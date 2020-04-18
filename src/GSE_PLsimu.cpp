/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file GSE_PLsimu.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * Manage the ignition on the GSE side
 * Send an image / Picture if a request is received
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 */

#include <Xbee.h>
#include <DataHandler.h>
#include <csignal>

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _) {
    (void)_;
    keep_running = 0;
}

int main(int argc, char** argv) {
    std::cout << "Syntax : ./GSE_PLsimu [serialPort] [nbr packet/sec] [if noise 'ON']" << std::endl;
    std::cout << "Syntax eg : ./GSE_PLsimu ttyUSB0 20 ON \n" << std::endl;

    signal(SIGINT, sig_handler);

    Connector connector;
    std::shared_ptr<Connector> cptr(&connector);

    // Your RF modem
    Xbee xbee("/dev/" + std::string((argc >= 2) ? argv[1] : "ttyUSB0"));
    // RF packet handler
    DataHandler dataHandler(cptr);
    using namespace DatagramType;

    uint32_t nbrPacketSec((argc >= 3) ? atoi(argv[2]) : 20);
    bool noiseON(argc == 4 && std::string(argv[3]) == "ON");

    while (keep_running) {
        if (xbee.receive(dataHandler))
            dataHandler.printLastRxPacket();

        // Generate fake communication flow during ignition
        if (noiseON) {
            DatagramID ID = AV_TELEMETRY;
            dataHandler.updateTx(ID);
            xbee.send(dataHandler.getPacket(ID));
        }

        // GSE ignition response
        if (dataHandler.updateTx(GSE_IGNITION))
            xbee.send(dataHandler.getPacket(GSE_IGNITION));

        // Payload Image transmission
        if (dataHandler.updateTx(PL_IMAGE))
            xbee.send(dataHandler.getPacket(PL_IMAGE));

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / nbrPacketSec));
    }

    return 0;
}