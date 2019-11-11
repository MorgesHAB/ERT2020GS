#include <iostream>
#include <vector>

using namespace std;

#define PACKET_SIZE     250

class Packet {
public:
//////////////// PACKET WRITER //////////////////////
    template<typename R, typename T>
    void writeY(T t) {
        R r = *reinterpret_cast<R *> (&t);

        for (int i = sizeof(t) - 1; i >= 0; --i)
            *(packetPosition++) = r >> (8 * i);
    }

    template<typename T>
    void write(T t) {
        if (sizeof(t) == 1) writeY<uint8_t>(t);
        else if (sizeof(t) == 2) writeY<uint16_t>(t);
        else if (sizeof(t) == 4) writeY<uint32_t>(t);
        else std::cout << "Error : Inconciliable type..." << std::endl;
    }

    void write(std::string& msg)  {
        write(uint8_t (msg.size()));
        for (auto& character : msg) write(character);
    }
//////////////// PACKET PARSER //////////////////////
    template<typename R, typename T>
    void parseY(T &t) {
        R r(0);
        for (int i = sizeof(t) - 1; i >= 0; --i)
            r |= (*(packetPosition++) << (8 * i));

        t = *reinterpret_cast<T *> (&r);
    }

    template<typename T>
    void parse(T &t) {
        if (sizeof(t) == 1) parseY<uint8_t>(t);
        else if (sizeof(t) == 2) parseY<uint16_t>(t);
        else if (sizeof(t) == 4) parseY<uint32_t>(t);
        else std::cout << "Error : Inconciliable type..." << std::endl;
    }

    void parse(std::string& msg)  {
        uint8_t size(0);
        parse(size);
        for (int i(0); i < size; ++i) {
            char c;
            parse(c);
            msg += c;
        }
    }

    Packet() : packet(new uint8_t[PACKET_SIZE]),
                                     packetPosition(packet) {}

    ~Packet() {
        delete[] packet;
    }

    void restart() {
        packetPosition = packet;
    }
private:
    uint8_t* packet;
    uint8_t* packetPosition;
};


int main() {
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
    return 0;
}
