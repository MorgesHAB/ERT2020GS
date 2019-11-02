#include <iostream>

using namespace std;


template<typename T, typename R>
R selectType(T t) {
    if (sizeof(t) == 1) return new uint8_t;
    if (sizeof(t) == 2) return new uint16_t;
    if (sizeof(t) == 4) return new uint32_t;
    return new int;
}

//useless
void parse(uint8_t *&p, uint32_t &n) {
    n = (*(p++) << 24) | (*(p++) << 16) | (*(p++) << 8) | *(p++);
}
void parse(uint8_t *&p, uint64_t &n) {
     n = (*(p++) << 56) | (*(p++) << 48) | (*(p++) << 40) | (*(p++) << 32) | (*(p++) << 24) | (*(p++) << 16) | (*(p++) << 8) | *(p++);
}

template<typename T>
void parseX(uint8_t *&p, T &t) {
    t = 0;
    for (int i = sizeof(t) - 1; i >=0; --i)
        t |= (*(p++) << (8 * i));
}

void parse(uint8_t* &p, float &f) {
    uint32_t t(0);
    parseX(p, t);
    f = *reinterpret_cast<float *> (&t);
}

void parse(uint8_t* &p, double &d) {
    uint64_t t(0);
    parse(p, t);
    d = *reinterpret_cast<double *> (&t);
}

void parse(uint8_t* &p, int &i) {
    uint32_t t(0);
    parseX(p, t);
    i = *reinterpret_cast<int *> (&t);
}

// PACKET Writer
template<typename T>
void writeX(uint8_t *&p, T t) {
    for (int i = sizeof(t) - 1; i >=0; --i)
        *(p++) = t >> (8 * i);
}
// replace with writeX
void write(uint8_t *&p, uint32_t n) {
    *(p++) = n >> 24;
    *(p++) = n >> 16;
    *(p++) = n >> 8;
    *(p++) = n >> 0;
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
    writeX(p, i32);
}

void write(uint8_t *&p, float f) {
    uint32_t f32 = *reinterpret_cast<uint32_t *> (&f);
    writeX(p, f32);
}

void write(uint8_t *&p, double d) {
    uint64_t d64 = *reinterpret_cast<uint64_t *> (&d);
    writeX(p, d64);
}

int main() {
    float f1 = -1.5;
    float f2 = 128.10203;
    float f3 = 345.28;
    double d = 128;
    int i = -1293494;
    uint8_t p[256];

    uint8_t *tmp(p);
    write(tmp, f1);
    write(tmp, f2);
    write(tmp, i);
    //write(tmp, d);
    write(tmp, f3); // 2 float à la suite
////////////////////////////////////
    tmp = p; // parser pointer
    float f1r, f2r, f3r;
    double dr;
    int ir;
    parse(tmp, f1r);
    parse(tmp, f2r);
    parse(tmp, ir);
    //parse(tmp, dr);
    parse(tmp, f3r);

    cout << f1r << endl;
    cout << f2r << endl;
    cout << ir << endl;
    //cout << dr << endl;
    cout << f3r << endl;

    return 0;
}
