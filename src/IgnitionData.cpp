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
    ignition = "NMNu{Yh£97Xm_R$0{BP3l/zKxL4QKs3P]W){8YQ5AU]N9mkA3OH}73+/)4Xkz2iTO,hdco65}_i8We4+Q3£19tj£$A.5Z0qw7xcxQZ#L]?m€€2mT67?03d3Dnyi_TuurlGFuWnP6n9d-0rO1µG4{Q}1C<W082K[41%7(05%0vY2(L3sl1qo3p5F{O2WZµ£,2klw^nJMe0p]q}u)957aF$F:%9@!-xu:H!~";
}

void IgnitionData::print() const {
    std::cout << "Ignition Data : " << ignition << std::endl;
}
