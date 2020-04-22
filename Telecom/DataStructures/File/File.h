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
    /**
     * Data that manage to transmit a file
     * @param fileName          The filename to transmit
     * @param bytePerPacket     Number of pure file data per packet
     *                          default is the maximum value
     *                          /!\ This max depends of many parameters (protocol, software,...)
     */
    explicit File(const std::string &fileName, uint8_t bytePerPacket = 220); // The real max is 222
    virtual ~File() override;

    void write(Packet& packet) override;
    void parse(Packet& packet) override;
    void print() const override;

    bool updateTx(std::shared_ptr<Connector> connector) override;
    bool updateRx(std::shared_ptr<Connector> connector) override;

    virtual bool importFile();
    void exportFile(std::string filenameAdd = "");

protected:
    std::string fileName;

private:
    // The packet number type
    // choose uint8_t, uint16_t, uint32_t according to your needs Number max 2^16
    // use uint16_t for basic file eg: image    use uint32_t for video
    typedef uint32_t Number;    // => 2^32 possible number

    FileTransmissionStates myState, receivedState;

    uint8_t bytePerPacket;

    Number packetNbr;
    Number nbrTotPacket;
    Number lastPacketNbr;
    Number missingNbrIterator;

    uint8_t nbrByteInLastPacket;

    std::vector<uint8_t*> file;

    std::vector<Number> missingPacketNbr;

    int nbrRxFileCounter;

    bool sendingData;
};


#endif //File_H
