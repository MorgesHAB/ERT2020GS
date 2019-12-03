/*!
 * \file IgnitionData.cpp
 *
 * \brief IgnitionData module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \date        11.11.2019	
 */

#include "IgnitionData.h"

void IgnitionData::write(Packet &packet) {
    packet.write(ignition);
}

void IgnitionData::parse(Packet &packet) {
    packet.parse(ignition);
}

void IgnitionData::update() {
    ignition = "NMNu{Yh£97Xm_R$0{BP3l/zKxL4QKs3P]W){8YQ5AU]N9mkA3OH}73+/)4Xkz2iTO";
}

void IgnitionData::print() const {
    std::cout << "Ignition Data : " << ignition << std::endl;
}

void IgnitionData::writeConnector(std::shared_ptr<Connector> connector) {

}
