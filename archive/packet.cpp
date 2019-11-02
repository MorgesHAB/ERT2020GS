#include <iostream>
#include <vector>

using namespace std;

//////////////// PACKET WRITER //////////////////////
template<typename R, typename T>
void writeY(uint8_t *&p, T t) {
    R r = *reinterpret_cast<R *> (&t);

    for (int i = sizeof(t) - 1; i >= 0; --i)
        *(p++) = r >> (8 * i);
}

template<typename T>
void write(uint8_t *&p, T t) {
    if (sizeof(t) == 1) writeY<uint8_t>(p, t);
    else if (sizeof(t) == 2) writeY<uint16_t>(p, t);
    else if (sizeof(t) == 4) writeY<uint32_t>(p, t);
    else cout << "Error : Inconciliable type..." << endl;
}

void writeS(uint8_t *&p, std::string& msg)  {
    write(p, uint8_t (msg.size()));
    for (auto& character : msg) write(p, character);
}
//////////////// PACKET PARSER //////////////////////
template<typename R, typename T>
void parseY(uint8_t *&p, T &t) {
    R r(0);
    for (int i = sizeof(t) - 1; i >= 0; --i)
        r |= (*(p++) << (8 * i));

    t = *reinterpret_cast<T *> (&r);
}

template<typename T>
void parse(uint8_t *&p, T &t) {
    if (sizeof(t) == 1) parseY<uint8_t>(p, t);
    else if (sizeof(t) == 2) parseY<uint16_t>(p, t);
    else if (sizeof(t) == 4) parseY<uint32_t>(p, t);
    else cout << "Error : Inconciliable type..." << endl;
}

void parseS(uint8_t *&p, std::string& msg)  {
    uint8_t size(0);
    parse(p, size);
    for (int i(0); i < size; ++i) {
        char c;
        parse(p, c);
        msg += c;
    }
}

int main() {
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

    uint8_t p[256];
    uint8_t *tmp(p);
    write(tmp, float(123.45));
    write(tmp, i);
    write(tmp, a);
    write(tmp, b);
    write(tmp, c);
    write(tmp, d);
    write(tmp, e);
    write(tmp, statePacket);
    std::string msg("Hello Everybody, this is the launch session");
    writeS(tmp, msg);
////////////////////////////////////
    tmp = p; // parser pointer
    uint8_t x;
    parse(tmp, fr);
    parse(tmp, ir);
    parse(tmp, ar);
    parse(tmp, br);
    parse(tmp, cr);
    parse(tmp, dr);
    parse(tmp, er);
    parse(tmp, x);
    std::string msgRx;
    parseS(tmp, msgRx);

    cout << fr << endl;
    cout << ir << endl;
    cout << ar << endl;
    cout << br << endl;
    cout << +cr << endl;
    cout << dr << endl;
    cout << er << endl;
    cout << +x << endl;
    cout << "nbr element in packet " << static_cast<int> (tmp - p) << endl;
    // Get state content (bool)
    cout << (((p[static_cast<int> (tmp - p)-1]) >> 7)?"VALVE OPEN": "VALVE CLOSE") << endl;
    cout << msgRx << endl;



    return 0;
}
