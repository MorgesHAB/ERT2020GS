//
// Created by disoz on 19.03.2020.
//

#include "../RF-UI-Interface/connector.h"
#include <memory>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


int main(int argc, char **argv) {
    //set up everything
    std::shared_ptr<Connector> connector(std::make_shared<Connector>());

    float altitude(123.01);

    while (true) {
        altitude =  500 + ((float) rand()/ RAND_MAX) * 1000;
        connector->setData(ui_interface::T_ALTITUDE, altitude);
        if (altitude > connector->getData<float>(ui_interface::ALTITUDE_MAX))
            connector->setData(ui_interface::ALTITUDE_MAX, altitude);

        cout << "altitude : " << connector->getData<float>(ui_interface::T_ALTITUDE)
             << "  alt max : " << connector->getData<float>(ui_interface::ALTITUDE_MAX)
             << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }

    return 0;
}

