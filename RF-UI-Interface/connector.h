/*!
 * \file connector.h
 *
 * \brief Connector module interface
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \author      KESKE Cem - EPFL EL BA3
 * \date        02.12.2019
 */

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <atomic>
#include <array>
#include <string>
#include "ProtocolDefine.h"


class Connector {
public:
    Connector();

    template<typename T>
    void setData(ui_interface::DataType type, T t);

    void incrementData(ui_interface::DataType type);

    template<typename T>
    T getData(ui_interface::DataType type);

    template<typename T>
    T eatData(ui_interface::DataType type, uint64_t val);

    void reset(ui_interface::DataType type);

    const std::string &getImgPLfilename() const;

    void setImgPLfilename(const std::string &imgPLfilename);

private:
    std::array<std::atomic<std::uint64_t>, ui_interface::ARRAY_SIZE> dataCollection;
    std::string imgPLfilename;
};


// Definitions here because of the reference conflicts
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
