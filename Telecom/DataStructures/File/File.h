/*!
 * \file File.h
 *
 * \brief File module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        17.12.2019	
 */

#ifndef File_H
#define File_H

#include <Data.h>
#include <File/FileTransmissionStates.h>
#include <vector>
#include <fstream>


class File : public Data {
public:
    File(const std::string &fileName, uint16_t bytePerPacket);
    virtual ~File() override;

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

    virtual bool importFile();
    void exportFile();

protected:
    std::string fileName;

private:
    FileTransmissionStates myState, receivedState;

    uint16_t bytePerPacket;

    uint16_t packetNbr;
    uint32_t nbrTotPacket;
    uint32_t lastPacketNbr;
    uint16_t missingNbrIterator;

    uint8_t nbrByteInLastPacket;

    std::vector<uint8_t*> file;

    std::vector<uint16_t> missingPacketNbr;
    
    bool sendingData;
};


#endif //File_H
