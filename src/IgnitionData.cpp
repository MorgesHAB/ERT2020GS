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
    ignition = "H.3l[Vx72_97J<{.p|Q35$g~7Z157,3m&a+µc}!UHm2/IEby677C>}1cX8{MpvS1y<YCkYzBB#0mxM6(2S95^b%#hUF9v=+pycrUHF46A€P3o8DT7fv3eA=t6G_x46BPVTodEf|4o3&W!&Ksjl,?qf}YH=JS~:KH41=wTHl7d;)O60P99tWw+G7+g<$7^Q~3I/1Jtu7488faV3Ce€£636fF)3cJeDG5P3qF3{JPm[zL5a4bjxw(Zok$mt*p6}f+?y|JeP7B[£nC5R+£X_986[U9b4[96|~6-0yK=fi4:KP2|";
}

void IgnitionData::print() const {
    std::cout << "Ignition Data : " << ignition << std::endl;
}
