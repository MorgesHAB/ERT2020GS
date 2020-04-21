/*!
 * \file Worker.h
 *
 * \brief Worker module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        05.12.2019	
 */

#ifndef Worker_H
#define Worker_H

#include <DataHandler.h>
#include <RFmodem.h>
#include <connector.h>


class Worker {
public:
    Worker(std::shared_ptr<Connector> connector);

    void mainRoutine();

    void RFroutine(DataHandler& dataHandler, RFmodem* rfmodem);

    std::string getSerialport();

private:
    // Connector Pointer
    std::shared_ptr<Connector> connector;
};


#endif //Worker_H
