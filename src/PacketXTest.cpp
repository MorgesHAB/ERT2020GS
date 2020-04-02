/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file PacketXTest.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * Test the transmission of a specified packet
 * Syntax :
 *              ./TestPacket [Mode Tx or Rx] [DatagramID nbr] [Serial port]
 *  eg :        ./TestPacket Tx 3 ttyUSB0
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        03.02.2020
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
    std::cout << "Syntax : ./PacketTest [Tx or Rx] [DatagramID] [serial port]" << std::endl;
    std::cout << "Syntax ex : ./PacketTest Tx 3 ttyS3" << std::endl;
    
    using namespace DatagramType;

    signal(SIGINT, sig_handler);

    std::string port("/dev/ttyUSB0");
    bool modeTx(false);
    DatagramID ID(INIT);

    switch (argc) {
        case 4:
            port = "/dev/" + std::string(argv[3]);
        case 3:
            ID = (DatagramID) atoi(argv[2]);
        case 2:
            modeTx = std::string(argv[1]) == "Tx";
            break;
        default:
            std::cout << "Bad syntax" << std::endl;
            return 0;
    }

    Connector connector;
    std::shared_ptr<Connector> cptr(&connector);

    // Your RF modem
    Xbee xbee(port);
    // RF packet handler
    DataHandler dataHandler(cptr);
    using namespace DatagramType;

    while (keep_running) {
        // ./XbeeTest Tx            // Transmitter Part
        if (modeTx) {
            dataHandler.updateTx(ID);
            xbee.send(dataHandler.getPacket(ID));

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        // ./XbeeTest               // Receiver Part
        else {
            if (xbee.receive(dataHandler)) {
                dataHandler.printLastRxPacket();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    return 0;
}