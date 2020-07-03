#ifndef aa
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
#include "../Logger/utilities.h"
#include "../Telecom/DataStructures/Avionics/StateValues.h"

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
    return std::to_string(a) + dataname;
}

class A {
public:
    void f2(std::shared_ptr<Connector> c){
        while(c->getData<bool>(ui_interface::RUNNING)){
        std::cout << "another loop" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    void
    f1(std::shared_ptr<Connector> c)
    {
        float a(0);

        bool test_av = false;

        // AV STATES TEST
        if(test_av){
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        c->setData(ui_interface::SLEEP_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::SLEEP);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::CALIBRATION_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::CALIBRATION);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::IDLE_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::IDLE);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::FILLING_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::FILLING);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::LIFTOFF_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::LIFTOFF);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::COAST_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::COAST);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::PRIMARY_EVENT_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::PRIMARY_EVENT);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::SECONDARY_EVENT_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::SECONDARY_EVENT);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        c->setData(ui_interface::TOUCH_DOWN_REACHED, true);
        c->setData(ui_interface::STATUS_AV_STATE, avionic::TOUCH_DOWN);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        }




        while (c->getData<bool>(ui_interface::RUNNING)) {
            c->setData(ui_interface::GPS_ALTITUDE, (float)23.23);
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
            c->setData(ui_interface::T_ACCELEROMETER_X, (float)(a+ 0.1));
            c->setData(ui_interface::T_ACCELEROMETER_Z, (float)(a+ 0.0001));
            // c->setData(ui_interface::TIMESTAMP, std::time(nullptr));
            c->setData(ui_interface::RSSI_VALUE, int(a));
            std::cout << "Data set to : " << a << std::endl;
            a++;
            if ((int) a == 3) {
                c->setData(ui_interface::IGNITION_STATUS, true);
            }
            c->setData(ui_interface::TX_IGNITION_CODE, (uint8_t) a);

            c->setData(ui_interface::SERIALPORT_STATUS,((int)a)%3);
            c->setData(ui_interface::ALTITUDE_MAX,a);
            c->setData(ui_interface::GPS_ALTITUDE,a);


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
    GuiWindow firstwin(c);
    //SecondWindow secondwin(c);
    // run all threads

    //std::cout << utilities::datetime_long() << std::endl;
    // end the program
    firstwin.show();
    //secondwin.show();
    app.exec();
    }
    receiver_thread.join();
    return 0;
}
#endif
