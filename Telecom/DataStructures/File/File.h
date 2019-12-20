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
#include <vector>
#include <fstream>

class File : public Data {
public:
    File(const std::string &fileName, uint16_t bytePerPacket);
    virtual ~File() override;

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    void updateTx(std::shared_ptr<Connector> connector) override;
    void updateRx(std::shared_ptr<Connector> connector) override;

    void importFile();
    void exportFile();

    void sendMissingPacket(Packet &packet);

protected:
    std::string fileName;

    enum State {
        SLEEP, SEND_FILE_REQUEST_TO_TX,
        SENDING_FILE,
        SENDING_MISSING_PACKET, SENDING_MISSING_PACKET_FIRST,
        ALL_RECEIVED,
        READY_TO_SEND_NEW_FILE
    } state;

private:
    uint16_t bytePerPacket;

    uint16_t packetNbr;
    size_t nbrTotPacket;
    size_t lastPacketNbr;
    uint16_t missingNbrIterator;

    uint8_t nbrByteInLastPacket;
    size_t nbrSentFile;

    std::vector<uint8_t*> file;

    std::vector<uint16_t> missingPacketNbr;
};


#endif //File_H
