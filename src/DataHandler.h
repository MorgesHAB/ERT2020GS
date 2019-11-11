/*!
 * \file DataHandler.h
 *
 * \brief DataHandler module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#ifndef DataHandler_H
#define DataHandler_H


#include <vector>
#include "Data.h"
#include "Packet.h"

class DataHandler {
public:
    void update();
    void parse();
    void print() const;

    void add(Data * data);
    Packet &getDataPacket();

    virtual ~DataHandler();
private:
    std::vector<Data*> dataHandler;
    Packet dataPacket;
};


#endif //DataHandler_H
