#include <QApplication>
#include <memory>
#include <thread>
#include <iostream>
#include <chrono>
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include "GuiWindow.h"

class A{
public:
void f1(std::shared_ptr<Connector> c){
    unsigned a(0);
    while(c->getData<bool>(ui_interface::RUNNING)){
        c->setData(ui_interface::ALTITUDE,a);
        std::cout << "Data set to : " << a << std::endl;
        a++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Ending receiver thread!" << std::endl;

}
};

int main(int argc, char **argv) {
    //set up everything
    Connector c;

    std::shared_ptr<Connector> the_pointer(&c);
    A a;
    QApplication app(argc, argv);

    GuiWindow w(500, std::shared_ptr<Connector>(&c));
    //run all threads
    std::thread receiver_thread(&A::f1, a, std::shared_ptr<Connector>(&c));



    //end the program
    w.show();
    app.exec();
    receiver_thread.join();
    std::cout << "Ending receiver thread!" << std::endl;
    return 0;
}
