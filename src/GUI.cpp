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
 * \author      ISOZ Lionel, KESKE Cem - EPFL EL BA3
 * \date        04.11.2019
 */

#include <memory>
#include <thread>
#include <QApplication>
#include <gpswindow.h>
#include <connector.h>
#include <Worker.h>


int main(int argc, char **argv) {
    //set up everything
    Connector connector;

    QApplication app(argc, argv);

    GPSWindow window(500, std::shared_ptr<Connector>(&connector));

    //run all threads
    std::thread t1(&Worker::mainRoutine, Worker(std::shared_ptr<Connector>(&connector)));

    window.show();

    app.exec();

    t1.join();

    return 0;
}
