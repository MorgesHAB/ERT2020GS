#include "connector.h"

/*
void Connector::set_data(DataType type, uint64_t data)
{
    std::atomic_store(&(data_[type]), data);
}
*/
uint64_t Connector::getData(DataType type){
    return std::atomic_load(&dataCollection[type]);
}