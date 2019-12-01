#include <QApplication>
#include <memory>
#include <thread>
#include <iostream>
#include <chrono>
#include "connector.h"
#include "gpswindow.h"

class A{
public:
void f1(std::shared_ptr<Connector> c){
    unsigned a(0);
    while(true){
        c->set_data(Connector::DataType::ALTITUDE,a);
        std::cout << "Data set to : " << a << std::endl;
        a++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
};

int main(int argc, char **argv) {
    //set up everything
    Connector c;
    A a;
    QApplication app(argc, argv);

    GPSWindow w(500, std::shared_ptr<Connector>(&c));
    //run all threads
    std::thread receiver_thread(&A::f1, a, std::shared_ptr<Connector>(&c));


    //end the program
    w.show();
    app.exec();
    return 0;
}
