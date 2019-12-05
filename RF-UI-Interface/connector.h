#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <atomic>
#include <array>
#include <ProtocolDefine.h>


class Connector {
public:
    template<typename T>
    void setData(ui_interface::DataType type, T t);

    template<typename T>
    T getData(ui_interface::DataType type);

    template<typename T>
    T eatData(ui_interface::DataType type, uint64_t val);

private:
    std::array<std::atomic_uint64_t, ui_interface::DataType::ARRAY_SIZE> dataCollection;
};


 // Definitions here because reference conflicts
template<typename T>
void Connector::setData(ui_interface::DataType type, T t) {
    std::atomic_store(&(dataCollection[type]), reinterpret_cast<uint64_t&> (t));
}

template<typename T>
T Connector::getData(ui_interface::DataType type) {
    uint64_t tmp(std::atomic_load(&dataCollection[type]));
    return std::move(reinterpret_cast<T&> (tmp));
}

template<typename T>
T Connector::eatData(ui_interface::DataType type, uint64_t val) {
    uint64_t tmp(std::atomic_exchange(&dataCollection[type], val));
    return std::move(reinterpret_cast<T&> (tmp));
}


#endif // CONNECTOR_H
