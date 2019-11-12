/*!
 * \file GST.cpp
 *
 * \brief Ground Station Transceiver
 *
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        04.11.2019	
 */

#include <LoRa.h>
#include <DataHandler.h>
#include <GPS.h>
#include <PressureData.h>
#include <IgnitionData.h>
#include <States.h>
#include <Picture.h>


int main() {
    // Your RF modem
    LoRa loRa;

    // What's in my RF Packet ? give the data in the same order as in Tx serialisation
    DataHandler dataHandler;
    //dataHandler.add(new GPS);
    dataHandler.add(new PressureData);
    //dataHandler.add(new IgnitionData);
    dataHandler.add(new States({0, 0, 0, 0, 0, 0, 0, 0}));
    // dataHandler.add(new CPUData);
    // dataHandler.add(new TemperatureData); // etc...

    std::cout << "\nLoRa Reception is active... waiting for RF packet..." << std::endl;

    while (true) {
        if (loRa.receive(dataHandler.getDataPacket())) {
            std::cout << "LoRa last RSSI : " << loRa.getRSSI() << " dBm" << std::endl;
            dataHandler.parse();
            dataHandler.print();
        }
        usleep(10); //microseconds
    }
    return 0;
}