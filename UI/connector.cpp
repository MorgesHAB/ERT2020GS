#include "connector.h"

Connector::Connector()
{}

void Connector::set_data(DataType type, uint64_t data)
{
    std::atomic_store(&(data_[type]), data);
}

uint64_t Connector::get_data(DataType type){
    return std::atomic_load(&data_[type]);
}
