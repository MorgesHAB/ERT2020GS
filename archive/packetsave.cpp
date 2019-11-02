#include <iostream>

using namespace std;

uint8_t parse8(uint8_t *p) {
    return static_cast<uint8_t> (*(p++));
}

uint16_t parse16(uint8_t *p) {
    return static_cast<uint16_t> (*(p++) << 8) | *(p++);
}

uint32_t parse32(uint8_t *p) {
    return static_cast<uint32_t> (*(p++) << 24) | (*(p++) << 16) | (*(p++) << 8) | *(p++);
}

void parse(uint8_t *&p, uint32_t &n) {
    n =  static_cast<uint32_t> (*(p++) << 24) | (*(p++) << 16) | (*(p++) << 8) | *(p++);
}

void parse(uint8_t *p, uint64_t &n) {
    n = static_cast<uint64_t> (*(p++) << 56) | (*(p++) << 48) | (*(p++) << 40) | (*(p++) << 32) | (*(p++) << 31) | (*(p++) << 16) | (*(p++) << 8) | *(p++);
}

uint64_t parse64(uint8_t *p) {
    return static_cast<uint64_t> (*(p++) << 56) | (*(p++) << 48) | (*(p++) << 40) | (*(p++) << 32) | (*(p++) << 31) | (*(p++) << 16) | (*(p++) << 8) | *(p++);
}

void parse(uint8_t* &p, float &f) {
    uint32_t t;
    parse(p, t);
    f = *reinterpret_cast<float *> (&t);
}

void parse(uint8_t* &p, double &d) {
    uint64_t t;
    parse(p, t);
    d = *reinterpret_cast<float *> (&t);
}

float parseFloat(uint8_t* &p) {
    uint32_t t(parse32(p));
    return *reinterpret_cast<float *> (&t);
}

double parseDouble(uint8_t* &p) {
    uint64_t t(parse64(p));
    return *reinterpret_cast<double *> (&t);
}

// PACKET Writer
void write(uint8_t *&p, uint16_t n) {
    *(p++) = n >> 8;
    *(p++) = n;
}

void write(uint8_t *&p, uint32_t n) {
    *(p++) = n >> 24;
    *(p++) = n >> 16;
    *(p++) = n >> 8;
    *(p++) = n;
}

void write(uint8_t *&p, uint64_t n) {
    *(p++) = n >> 56;
    *(p++) = n >> 48;
    *(p++) = n >> 40;
    *(p++) = n >> 32;
    *(p++) = n >> 24;
    *(p++) = n >> 16;
    *(p++) = n >> 8;
    *(p++) = n;
}

void write(uint8_t *&p, int i) {
    uint32_t i32 = *reinterpret_cast<uint32_t *> (&i);
    write(p, i32);
}

void write(uint8_t *&p, float f) {
    uint32_t f32 = *reinterpret_cast<uint32_t *> (&f);
    write(p, f32);
}

void write(uint8_t *&p, double d) {
    uint64_t d64 = *reinterpret_cast<uint64_t *> (&d);
    write(p, d64);
}

struct Packet {
    uint8_t a;
    uint8_t b;
    char c;
    uint8_t d;
    float e;
    double f;

    void convertTo(uint8_t *packet8) {
        *(packet8++) = a;
        *(packet8++) = b;
        *(packet8++) = c;
        *(packet8++) = d;
        *(packet8++) = e;
        *packet8 = f;
    }
};

int main() {

    uint8_t packet8[256];
    Packet packet = {3, 4, 'c', 8, 4.24, 234.789};

    packet.convertTo(packet8);
    for (size_t i = 0; i < 6; i++) {
        //cout << "packet[" << i << "] =  " << +packet8[i] << endl;
    }

    uint8_t p[] = {191, 192, 0, 0}; // = -1.5
//  uint16_t x(parse16(p));
//  cout << +x << endl;
    uint32_t y(parse32(p));
    //cout << +y << endl;
    //float f = static_cast<float> (y);
    //cout << f << endl;

    //float f3(parseFloat(p));
    //cout << f3 << endl;

    float f1 = -1.5;
    float f2 = 10.78;
    double d = 128.10203;
    int i = 126;
    uint8_t p2[256];

    uint8_t *tmp(p2);
    write(tmp, f1);
    write(tmp, f2); // 2 float à la suite
    write(tmp, d);
////////////////////////////////////
    uint8_t *tmp2(p2);
    float f1r, f2r;
    double dr;
    parse(tmp2, f1r);
    parse(tmp2, f2r);
    parse(tmp2, dr);
    //float f1Rx(parseFloat(tmp2));
    //float f2Rx(parseFloat(tmp2));
    //double dRx(parse64(tmp2));
    cout << f1r << endl;
    cout << f2r << endl;
    cout << dr << endl;

    return 0;
}
