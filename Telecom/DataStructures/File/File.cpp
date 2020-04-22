/*!
 * \file File.cpp
 *
 * \brief File module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        17.12.2019	
 */

#include "File.h"

File::File(const std::string &fileName, uint8_t bytePerPacket)
        : fileName(fileName), myState(SLEEP), receivedState(SLEEP),
          bytePerPacket(bytePerPacket), packetNbr(0), nbrTotPacket(0),
          lastPacketNbr(0), missingNbrIterator(0),
          nbrByteInLastPacket(0), sendingData(false), nbrRxFileCounter(0) {}

File::~File() {
    for (auto& part : file) delete[] part;
    file.clear();
}


void File::print() const {
    std::cout << "MyState : " << getStateName(myState) << "\t ReceivedState : "
              << getStateName(receivedState) << std::endl;
    switch (receivedState) {
        case SEND_FILE_REQUEST_TO_TX:
            std::cout << "A File transmission request have been received" << std::endl;
            break;
        case SEND_MISSING_PACKET_REQUEST:
            std::cout << "A missing packet request have been received" << std::endl;
            break;
        case ALL_RECEIVED:
            std::cout << "ACK : Every Packet have been received correctly" << std::endl;
            std::cout << "SLEEP mode activated - waiting for another request" << std::endl;
            break;
        case ABORT:
            std::cout << "Tx sent an Aborted state => Transmission stop - SLEEP mode" << std::endl;
            break;
        case SENDING_MISSING_PACKET:
            std::cout << "!!!!!MISSING PACKET SENT AGAIN" << std::endl;
        case SENDING_PACKET:
            std::cout << "Received File Data " << fileName << " -- Packet n° " << packetNbr
                      << " / " << nbrTotPacket - 1 << std::endl;
            break;
        default:
            break;
    }
}

bool File::updateTx(std::shared_ptr<Connector> connector) {
    // File Receiver Gui button check
    if (connector->eatData<bool>(ui_interface::FILE_TRANSMISSION_ABORT_ORDER, false))
        myState = ABORT;
    if (myState == WAITING_PACKET) {
        if (connector->eatData<bool>(ui_interface::FTX_SEND_MISSING_REQUEST, false))
            myState = SEND_MISSING_PACKET_REQUEST;
        if (connector->eatData<bool>(ui_interface::FTX_SAVE_FILE, false))
            exportFile("Save");
    }

    switch (myState) { // if myState was ... then ...
        /////// On the File Receiver // updated only if need to send request (connector order)
        case SLEEP:
            if (connector->eatData<bool>(ui_interface::SEND_FILE_REQUEST, false)) {
                myState = SEND_FILE_REQUEST_TO_TX;
                sendingData = true;
                connector->setData(ui_interface::FTX_FILE_TX_SENT, true);
            }
            break;
        case WAITING_PACKET:
            sendingData = false;
            break;
        case SEND_MISSING_PACKET_REQUEST:
            sendingData = true;
            missingPacketNbr.clear();
            for (Number i(0); i < nbrTotPacket && missingPacketNbr.size() < bytePerPacket / sizeof(Number); ++i) {
                if (!file[i]) missingPacketNbr.push_back(i);
            }
            if (missingPacketNbr.empty()) {
                myState = ALL_RECEIVED;
                connector->setData(ui_interface::FTX_ALL_RECEIVED, true);
            }
            else {
                lastPacketNbr = missingPacketNbr.back();
                connector->setData(ui_interface::FTX_MISSING_REQUEST_SENT, true);
                break;
            }
        case ALL_RECEIVED:
            std::cout << "ACK : Every Packet have been received correctly" << std::endl;
            exportFile("Rx" + std::to_string(++nbrRxFileCounter));
            connector->setImgPLfilename(fileName);
            connector->setData(ui_interface::FILE_TRANSMISSION_ALL_RECEIVED, true);
            connector->setData(ui_interface::FTX_ACK_SENT, true);
            break;
        case ABORT:
            sendingData = true; // send abort
            break;
        /////// On the File Transmitter : update FSM state only at Reception
        case WAITING_MISSING_PACKET_REQUEST:
            sendingData = false;
            break;
        default:
            break;
    }

    connector->setData(ui_interface::FILE_TRANSMISSION_MY_STATE, myState);
    connector->setData(ui_interface::FILE_TRANSMISSION_RECEIVED_STATE, receivedState);

    return sendingData;
}

void File::write(Packet &packet) {
    packet.write((uint8_t) myState);

    // After writing state processing
    switch (myState) {
        /////// On the File Receiver
        case ALL_RECEIVED:
        case ABORT:
            myState = SLEEP;
            sendingData = false;
            break;
        case SEND_MISSING_PACKET_REQUEST:
            packet.write(lastPacketNbr);
            for (auto& nbr : missingPacketNbr) packet.write(nbr);
            myState = WAITING_PACKET;
            break;
        /////// On the File Transmitter
        case INIT:
            packet.write(nbrTotPacket);
            packet.write(fileName);
            myState = SENDING_PACKET;
            break;
        case SENDING_MISSING_PACKET:
            packetNbr = missingPacketNbr[missingNbrIterator];
            // no break
        case SENDING_PACKET:
            packet.write(packetNbr);
            if (packetNbr == nbrTotPacket - 1) {    // last packet
                packet.write(nbrByteInLastPacket);
                for (uint32_t i(0); i < nbrByteInLastPacket; ++i)
                    packet.write(file[packetNbr][i]);
            } else {
                for (uint32_t i(0); i < bytePerPacket; ++i)
                    packet.write(file[packetNbr][i]);
            }
            if (packetNbr == lastPacketNbr) myState = WAITING_MISSING_PACKET_REQUEST;

            ++packetNbr;
            ++missingNbrIterator; // not use before missing process
            break;
        case SEND_FILE_REQUEST_TO_TX: // Sent
            myState = WAITING_PACKET;
            break;
        default:
            break;
    }
}


void File::parse(Packet &packet) {
    uint8_t statetmp;
    packet.parse(statetmp);
    receivedState = (FileTransmissionStates) statetmp;

    switch (receivedState) {
        /////// On the File Transmitter
        case SEND_MISSING_PACKET_REQUEST:
            missingNbrIterator = 0;
            missingPacketNbr.clear();
            packet.parse(lastPacketNbr);
            Number nbr;
            do {
                packet.parse(nbr);
                missingPacketNbr.push_back(nbr);
            } while (nbr != lastPacketNbr);
            break;
        /////// On the File Receiver
        case INIT:
             // TODO while not init
            packet.parse(nbrTotPacket);
            packet.parse(fileName);
            file.resize(nbrTotPacket, nullptr);
            lastPacketNbr = nbrTotPacket - 1;
            break;
        case SENDING_MISSING_PACKET:
        case SENDING_PACKET:
            packet.parse(packetNbr);
            if (packetNbr < nbrTotPacket) { //security seg fault
                file[packetNbr] = new uint8_t[bytePerPacket];

                if (packetNbr == nbrTotPacket - 1) {    // last packet
                    packet.parse(nbrByteInLastPacket);
                    for (uint32_t i(0); i < nbrByteInLastPacket; ++i)
                        packet.parse(file[packetNbr][i]);
                } else {
                    for (uint32_t i(0); i < bytePerPacket; ++i)
                        packet.parse(file[packetNbr][i]);
                }

                if (packetNbr == lastPacketNbr) // max Nbr or last of missing
                    myState = SEND_MISSING_PACKET_REQUEST;
            }
            break;
        default:
            break;
    }
}

bool File::updateRx(std::shared_ptr<Connector> connector) {
    if (connector->eatData<bool>(ui_interface::FILE_TRANSMISSION_ABORT_ORDER, false))
        myState = ABORT;

    switch (receivedState) {
        /////// On the File Transmitter
        case SEND_MISSING_PACKET_REQUEST:
            myState = SENDING_MISSING_PACKET;
            sendingData = true;
            break;
        case SEND_FILE_REQUEST_TO_TX:
            if (myState == SLEEP) {
                if (importFile()) {
                    myState = INIT;
                    sendingData = true;
                } else {
                    myState = ABORT;
                }
            }
            break;
        case ALL_RECEIVED:
            packetNbr = nbrTotPacket -1; // for Gui nice printing
        case ABORT:
            sendingData = false;
            myState = SLEEP;
            packetNbr = 0;
            break;
        case SENDING_MISSING_PACKET:
        case SENDING_PACKET:
            connector->incrementData(ui_interface::FTX_RX_PACKET_CTR);
            break;
        default:
            break;
    }
    connector->setData(ui_interface::FILE_TRANSMISSION_TOTAL_PACKETS, nbrTotPacket - 1);
    connector->setData(ui_interface::FILE_TRANSMISSION_CURRENT_PACKET, packetNbr);
    connector->setData(ui_interface::FILE_TRANSMISSION_MY_STATE, myState);
    connector->setData(ui_interface::FILE_TRANSMISSION_RECEIVED_STATE, receivedState);
    connector->setData(ui_interface::FTX_PL_RESPONSE, true);
    return true;
}


bool File::importFile() {
    // Store all bytes of the file
    std::ifstream fileIn(fileName, std::ios::in | std::ios::binary); // read in binary
    file.clear();
    if (fileIn) {
        Number nbr(0);
        while (!fileIn.eof()) {
            file.push_back(new uint8_t[bytePerPacket]);
            nbrByteInLastPacket = 0;
            for (Number i(0); i < bytePerPacket && !fileIn.eof(); ++i) {
                file[nbr][i] = fileIn.get();
                ++nbrByteInLastPacket;
            }
            ++nbr;
        }
        --nbrByteInLastPacket;
        nbrTotPacket = file.size();
        lastPacketNbr = nbrTotPacket - 1;
        return true;
    } else {
        std::cerr << "Impossible to read the file" << std::endl;
        return false;
    }
}

void File::exportFile(std::string filenameAdd) {
    fileName.replace(0, fileName.rfind('.'), fileName.substr(0, fileName.rfind('.')) +
                                             filenameAdd); // <--replace with
    std::ofstream fileOut(fileName, std::ios::out | std::ios::binary);

    if (fileOut) {
        auto last(bytePerPacket);
        for(Number i(0); i < nbrTotPacket; ++i) {
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
