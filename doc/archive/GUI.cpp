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
#include <DataHandler.h>
#include <Xbee.h>
#include <connector.h>
#include <GuiWindow.h>
#include <Worker.h>

class A {
public:
    void f1(std::shared_ptr<Connector> c) {
        Xbee xbee;
        DataHandler dataHandler;

        while (true) {
            if (xbee.receive(dataHandler.getPacket(XBEE_TEST))) {
                //if (true) {
                dataHandler.parse(XBEE_TEST);
                dataHandler.print(XBEE_TEST);
                //dataHandler.update(XBEE_TEST);
                dataHandler.writeConnector(XBEE_TEST, c);
            }
        }
    }
};

int main(int argc, char** argv) {
    // Your RF modem
    Xbee xbee;
    //set up everything
    Connector c;

    // RF packet handler
    DataHandler dataHandler;
    A a;
    QApplication app(argc, argv);

    GPSWindow w(500, std::shared_ptr<Connector>(&c));
    //run all threads
    //std::thread t1(&Xbee::mainRoutine, xbee);
    std::thread t1(&A::f1, a, std::shared_ptr<Connector>(&c));

    std::thread t2(&Worker::mainRoutine, Worker(std::shared_ptr<Connector> (&c)));

    w.show();

    app.exec();

    t1.join();

    return 0;
}
