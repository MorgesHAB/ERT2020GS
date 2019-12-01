/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file GUI.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019
 */

#include <QApplication>
#include <DataHandler.h>
#include <Xbee.h>
#include <memory>
#include <thread>
#include "connector.h"
#include "gpswindow.h"

int main(int argc, char** argv) {
    // Your RF modem
    Xbee xbee;
    //set up everything
    Connector c;
    // RF packet handler
    DataHandler dataHandler;

    QApplication app(argc, argv);

    GPSWindow w(500, std::shared_ptr<Connector>(&c));
    //run all threads
    std::thread t1(&Xbee::receive, &xbee, dataHandler);
    //end the program
    w.show();

    app.exec();

    t1.join();

    return 0;
}