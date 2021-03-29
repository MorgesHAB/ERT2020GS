/*!
 *      ______ _____ _______      _____  _____     ___   ___ ___   ___
 *     |  ____|  __ \__   __|    / ____|/ ____|   |__ \ / _ \__ \ / _ \
 *     | |__  | |__) | | |      | |  __| (___        ) | | | | ) | | | |
 *     |  __| |  _  /  | |      | | |_ |\___ \      / /| | | |/ /| | | |
 *     | |____| | \ \  | |      | |__| |____) |    / /_| |_| / /_| |_| |
 *     |______|_|  \_\ |_|       \_____|_____/    |____|\___/____|\___/
 *
 * \file ERT2020GS.cpp
 *
 * \brief Ground Support Equipment Transceiver
 *
 * \author      ISOZ Lionel, KESKE Cem - EPFL EL BA3
 * \date        04.11.2019
 *   <img src="bellalui.png" width=600>
 */

#include <memory>
#include <thread>
#include <chrono>
#include <QApplication>
#include <GuiWindow.h>
#include <GraphWindow.h>
#include <TerminalWindow.h>
#include <SecondWindow.h>
#include <connector.h>
#include <Worker.h>


int main(int argc, char **argv) {
    //set up everything
    
    std::shared_ptr<Connector> connector(std::make_shared<Connector>());

    //std::shared_ptr<Connector> fake_connector(std::make_shared<Connector>());

    QApplication app(argc, argv);
    
    GuiWindow guiWindow(connector);

    GraphWindow graphWindow(connector) ;

    TerminalWindow terminalWindow(connector) ;

    //run all threads
    std::thread t1(&Worker::mainRoutine, Worker(connector));

    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    guiWindow.show();
    graphWindow.show();
    terminalWindow.show();

    std::this_thread::sleep_for(std::chrono::milliseconds(300));
	
    //secWindow.show();

    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    app.exec();

    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    t1.join();

    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    
    return 0;
}
