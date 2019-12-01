#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <atomic>
#include <array>


class Connector
{
public:
    enum DataType { ALTITUDE, count };

    Connector();
    void set_data(DataType type, uint64_t data);
    uint64_t get_data(DataType type);

private:
    std::array<std::atomic_uint64_t, DataType::count> data_;
};



#endif // CONNECTOR_H
