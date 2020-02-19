
#include <QApplication>
#include <memory>
#include <thread>
#include <iostream>
#include <chrono>
#include <ctime>
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include "GuiWindow.h"
#include "../Logger/Logger.h"

class Data: public Loggable{
public:
    Data(std::string dataname): dataname(dataname){}
    virtual ~Data() override{}
    std::string log_description() const override;
    std::string dataname;
};

std::string Data::log_description() const {
    static int a = 0;
    ++a;
    return std::to_string(a);
}

class A {
public:
    void f2(std::shared_ptr<Connector> c){
        while(c->getData<bool>(ui_interface::RUNNING)){
        std::cout << "another looooop" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
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

            c->setData(ui_interface::T_PRESSURE, a);
            c->setData(ui_interface::T_ALTITUDE, a);
            c->setData(ui_interface::T_ACCELEROMETER_Y, a);
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
