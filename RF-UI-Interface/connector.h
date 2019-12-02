#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <atomic>
#include <array>
#include <ProtocolDefine.h>


class Connector {
public:
    template<typename T>
    void setData(DataType type, T t);
    template<typename T>
    void getData(DataType type, T &t);
    template<typename T>
    void eatData(DataType type, T &t, uint64_t val);


private:
    std::array<std::atomic_uint64_t, DataType::VECTOR_SIZE> dataCollection;
};


 // Definitions here because reference conflicts
template<typename T>
void Connector::setData(DataType type, T t) {
    std::atomic_store(&(dataCollection[type]), *(reinterpret_cast<uint64_t*> (&t)));
}

template<typename T>
void Connector::getData(DataType type, T &t) {
    uint64_t tmp(std::atomic_load(&dataCollection[type]));
    t = *reinterpret_cast<T*> (&tmp);
}

template<typename T>
void Connector::eatData(DataType type, T &t, uint64_t val) {
    getData(type, t);
    setData(type, val);
}


#endif // CONNECTOR_H
