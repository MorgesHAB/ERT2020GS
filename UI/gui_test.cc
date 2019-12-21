

#include <QApplication>
#include <memory>
#include <thread>
#include <iostream>
#include <chrono>
#include <ctime>
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include "GuiWindow.h"

class A {
public:
    void
    f1(std::shared_ptr<Connector> c)
    {
        float a(0);

        while (c->getData<bool>(ui_interface::RUNNING)) {
            c->incrementData(ui_interface::CORRUPTED_PACKET_CTR);
            c->incrementData(ui_interface::PACKET_RX_RATE_CTR);
            c->incrementData(ui_interface::PACKET_RX_RATE_CTR);
            c->incrementData(ui_interface::PACKET_RX_RATE_CTR);
            c->incrementData(ui_interface::RX_PACKET_CTR);
            c->incrementData(ui_interface::RX_PACKET_CTR);
            c->incrementData(ui_interface::RX_PACKET_CTR);
            c->incrementData(ui_interface::TX_PACKET_NR);
            c->incrementData(ui_interface::TX_PACKET_NR);
            c->incrementData(ui_interface::TX_PACKET_NR);
            // if(((int)a )%10==0){
            c->incrementData(ui_interface::TX_PACKET_NR);
            c->incrementData(ui_interface::TX_PACKET_NR);
            c->incrementData(ui_interface::TX_PACKET_NR);

            c->incrementData(ui_interface::TX_PACKET_NR);

            c->incrementData(ui_interface::TX_PACKET_NR);
            // }

            c->setData(ui_interface::PRESSURE_DATA, a);
            c->setData(ui_interface::ALTITUDE, a);
            c->setData(ui_interface::LONGITUDE, a);
            // c->setData(ui_interface::TIMESTAMP, std::time(nullptr));
            std::cout << "Data set to : " << a << std::endl;
            a++;
            if ((int) a == 3) {
                c->setData(ui_interface::IGNITION_STATUS, true);
            }
            c->setData(ui_interface::TX_IGNITION_CODE, (uint8_t) a);
            
	    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        std::cout << "Ending receiver thread!" << std::endl;
    } // f1
};

int
main(int argc, char ** argv)
{
    // set up everything

    std::shared_ptr<Connector> c(std::make_shared<Connector>());
    A a;
    std::thread receiver_thread(&A::f1, a, c);

    {
    QApplication app(argc, argv);
    GuiWindow w(c);
    // run all threads



    // end the program
    w.show();
    app.exec();
    }
    receiver_thread.join();
    return 0;
}
