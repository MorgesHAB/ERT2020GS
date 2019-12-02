#include "connector.h"
/*
template<typename T>
T Connector::get_data(ui_interface::DataType type) {
    return std::move(std::atomic_load<T>(&data_[type]));
}

template<typename T>
void Connector::set_data(ui_interface::DataType type, T t) {
    std::atomic_store(&(data_[type]), reinterpret_cast<uint64_t>(t));
}

template<typename T>
T Connector::eat_data(ui_interface::DataType type) {
    return std::move(std::atomic_exchange<T>(&(data_[type]), 0));
}
*/