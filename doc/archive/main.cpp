#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Packet.h"
#include "GPS.h"

using namespace std;

void f();

int main() {
    Packet Xbee;
    GPS gps(46.654268333, 6.961496667, 9985.7, 70.9884, "2017-07-01T08:11:39.000Z");
    gps.write(Xbee);

    cout << setprecision(10);
    GPS gpsData;
    Xbee.restart();
    gpsData.parse(Xbee);
    gpsData.print();

    return 0;
}

void f() {
    Packet post;
    float f(-128.102), fr;
    int i(-1293494), ir;
    uint32_t a(2345), ar;
    uint16_t b(1299), br;
    uint8_t c(234), cr;
    char d('A'), dr;
    bool e(true), er;
    bool OPEN_VALVE(true);
    vector<bool> states = {1, 1, 0, 1, 0, 0, 0, OPEN_VALVE};
    uint8_t statePacket(0);
    for (int i(0); i < 8; ++i) {
        statePacket |= states[i] << i;
    }

    post.write(f);
    post.write(i);
    post.write(a);
    post.write(b);
    post.write(c);
    post.write(d);
    post.write(e);
    post.write(statePacket);
    std::string msg("Hello Everybody, this is the launch session");
    post.write(msg);
////////////////////////////////////
    uint8_t x;
    std::string msgRx;
    post.restart();
    post.parse(fr);
    post.parse(ir);
    post.parse(ar);
    post.parse(br);
    post.parse(cr);
    post.parse(dr);
    post.parse(er);
    post.parse(x);
    post.parse(msgRx);

    cout << fr << endl;
    cout << ir << endl;
    cout << ar << endl;
    cout << br << endl;
    cout << +cr << endl;
    cout << dr << endl;
    cout << er << endl;
    cout << +x << endl;
    //cout << "nbr element in packet " << static_cast<int> (tmp - p) << endl;
    // Get state content (bool)
    //cout << (((p[static_cast<int> (tmp - p)-1]) >> 7)?"VALVE OPEN": "VALVE CLOSE") << endl;
    cout << msgRx << endl;
}