/*!
 * \file File.cpp
 *
 * \brief File module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        17.12.2019	
 */

#include "File.h"

File::File(const std::string &fileName, uint16_t bytePerPacket)
        : fileName(fileName), bytePerPacket(bytePerPacket),
          myState(SLEEP), receivedState(SLEEP),
          packetNbr(0), nbrTotPacket(0), lastPacketNbr(0), missingNbrIterator(0),
          nbrByteInLastPacket(0), nbrSentFile(0) {}

File::~File() {
    for (auto& part : file) delete[] part;
    file.clear();
}


void File::print() const {
    std::cout << "File Data " << fileName << " -- Packet n° " << packetNbr
              << " / " << nbrTotPacket - 1 << std::endl;
}

void File::updateTx(std::shared_ptr<Connector> connector) {
    switch (myState) {
        /////// On the File Receiver // updated only if need to send request (connector order)
        case SLEEP:
            myState = SEND_FILE_REQUEST_TO_TX;
            break;
        case SEND_FILE_REQUEST_TO_TX: // Sent
            myState = WAITING_PACKET;
            break;
        case SEND_MISSING_PACKET_REQUEST:
            myState = WAITING_PACKET;
            break;
        default:
            break;
    }
    /////// On the File Transmitter : update FSM state only at Reception
    if (myState == WAITING_MISSING_PACKET_REQUEST)
        connector->setData(ui_interface::SENDING_DATA, false);
}

void File::write(Packet &packet) {
    /////// On the File Receiver
    packet.write((uint8_t) myState);
    // After writing state processing
    switch (myState) {
        /////// On the File Receiver
        case SEND_MISSING_PACKET_REQUEST:
            sendMissingPacketRequest(packet);
            break;
        /////// On the File Transmitter
        case SENDING_MISSING_PACKET:
            packetNbr = missingPacketNbr[missingNbrIterator];
            // no break
        case SENDING_PACKET:
            packet.write(packetNbr);
            if (packetNbr == 0) packet.write(nbrTotPacket);
            if (packetNbr == nbrTotPacket - 1) packet.write(nbrByteInLastPacket);

            for (size_t i(0); i < bytePerPacket; ++i) {
                packet.write(file[packetNbr][i]);
            }
            if (packetNbr == lastPacketNbr) myState = WAITING_MISSING_PACKET_REQUEST;

            ++packetNbr;
            ++missingNbrIterator; // not use before missing process
            break;
        default:
            break;
    }
}

// Order : parse then updateRx
void File::parse(Packet &packet) {
    uint8_t statetmp;
    packet.parse(statetmp);
    receivedState = (State) statetmp;

    switch (receivedState) {
        /////// On the File Transmitter
        case SEND_MISSING_PACKET_REQUEST:
            manageRxMissingPacketRequest(packet);
            break;
        /////// On the File Receiver
        case SENDING_MISSING_PACKET:
        case SENDING_PACKET:
            packet.parse(packetNbr);
            if (packetNbr == 0) { // TODO while not received packet 0
                packet.parse(nbrTotPacket);
                file.resize(nbrTotPacket, nullptr);
                lastPacketNbr = nbrTotPacket - 1;
            }
            if (packetNbr < nbrTotPacket) { //security seg fault
                file[packetNbr] = new uint8_t[bytePerPacket];
                if (packetNbr == nbrTotPacket - 1) packet.parse(nbrByteInLastPacket);

                for (size_t i(0); i < bytePerPacket; ++i) {
                    packet.parse(file[packetNbr][i]);
                }
                if (packetNbr == lastPacketNbr) { // max Nbr or last of missing
                    myState = SEND_MISSING_PACKET_REQUEST;
                }
            }
            break;
        default:
            break;
    }
}

void File::updateRx(std::shared_ptr<Connector> connector) {
    switch (myState) {
        /////// On the File Receiver
        case ALL_RECEIVED:
            std::cout << "ACK : Every Packet have been received correctly"
                      << std::endl;
            exportFile();
            myState = SLEEP;
            break;
        case SEND_MISSING_PACKET_REQUEST:
            connector->setData(ui_interface::SEND_FILE_REQUEST, true);
            break;
        default:
            break;
    }
    switch (receivedState) {
        /////// On the File Receiver
        case SEND_MISSING_PACKET_REQUEST:
            myState = SENDING_MISSING_PACKET;
            break;
        /////// On the File Transmitter
        case SEND_FILE_REQUEST_TO_TX:
            if (myState == SLEEP) {
                importFile(); // TODO Manage error open file
                myState = SENDING_PACKET;
                connector->setData(ui_interface::SENDING_DATA, true);
            }
        case SENDING_MISSING_PACKET:
            connector->setData(ui_interface::SENDING_DATA, true);
            break;
        case ALL_RECEIVED:
            connector->setData(ui_interface::SENDING_DATA, false);
            myState = SLEEP;
            break;
        default:
            break;
    }
}


void File::sendMissingPacketRequest(Packet &packet) {
    bool allReceived(true);
    // Assuming totpacketNbr < 2^16
    for(uint16_t i(0); i < bytePerPacket / 2 || i < nbrTotPacket; ++i) {
        if (!file[i]) {
            packet.write(i);
            allReceived = false;
            lastPacketNbr = i;
        }
    }
    packet.write(lastPacketNbr);
    myState = SEND_MISSING_PACKET_REQUEST;
    if (allReceived) myState = ALL_RECEIVED;
}

void File::manageRxMissingPacketRequest(Packet &packet) {
    missingNbrIterator = 0;
    missingPacketNbr.clear();

    for(uint16_t i(0); i < bytePerPacket / 2 || i < nbrTotPacket; ++i) {
        packet.parse(i);
        missingPacketNbr.push_back(i);
    }
    packet.parse(lastPacketNbr);
}


void File::importFile() {
    // Store all bytes of the file
    std::ifstream fileIn(fileName, std::ios::in | std::ios::binary);

    if (fileIn) {
        size_t nbr(0);
        while (!fileIn.eof()) {
            file.push_back(new uint8_t[bytePerPacket]);
            nbrByteInLastPacket = 0;
            for (size_t i(0); i < bytePerPacket && !fileIn.eof(); ++i) {
                file[nbr][i] = fileIn.get();
                ++nbrByteInLastPacket;
            }
            ++nbr;
        }
        --nbrByteInLastPacket;
        nbrTotPacket = file.size();
        lastPacketNbr = nbrTotPacket - 1;
    } else
        std::cerr << "Impossible to read the file" << std::endl;
}

void File::exportFile() {
    fileName.replace(0, fileName.find('.'),
                     fileName.substr(0, fileName.find('.')) + "Rx"); // <--replace with
    std::ofstream fileOut(fileName, std::ios::out | std::ios::binary);

    if (fileOut) {
        size_t last(bytePerPacket);
        for(size_t i(0); i < nbrTotPacket; ++i) {
            if (i == nbrTotPacket - 1) last = nbrByteInLastPacket;
            if (file[i]) { // if received packet else nullptr
                for (size_t j(0); j < last; ++j) fileOut.put(file[i][j]);
            } else {
                for (size_t j(0); j < last; ++j) fileOut.put(0); // black ?
                std::cerr << "!!! packet nbr " << i << " not received !!" << std::endl;
            }
        }
        std::cout << "*** New received file is available as " << fileName << std::endl;
        fileOut.close();
    } else
        std::cerr << "Impossible to save data the file -> All data lost" << std::endl;
}