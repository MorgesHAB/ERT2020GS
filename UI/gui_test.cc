#include <QApplication>
#include <memory>
#include <thread>
#include <iostream>
#include <chrono>
#include <ctime>
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include "GuiWindow.h"

class A{
public:
void f1(std::shared_ptr<Connector> c){
    float a(0);
    while(c->getData<bool>(ui_interface::RUNNING)){
        c->setData(ui_interface::PRESSURE_DATA,a);
        c->setData(ui_interface::TIMESTAMP, std::time(nullptr));
        std::cout << "Data set to : " << a << std::endl;
        a++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Ending receiver thread!" << std::endl;
}
};

int main(int argc, char **argv) {
    //set up everything

    std::shared_ptr<Connector> c(std::make_shared<Connector>());


    A a;
    QApplication app(argc, argv);

    GuiWindow w(500, c);
    //run all threads
    std::thread receiver_thread(&A::f1, a, c);



    //end the program
    w.show();
    app.exec();
    receiver_thread.join();
    return 0;
}
