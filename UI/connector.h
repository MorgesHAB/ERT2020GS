#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <atomic>
#include <array>

namespace data_types {
    enum UintData { ALTITUDE = 0, count };
    enum BoolData { SOLENOID_CLICKED = 0, count };
    enum DoubleData { PRESSURE = 0, count };  
}

using namespace data_types;

class Connector
{
public:
    
    Connector();
    
    void set_data(UintData type, uint64_t data);
    uint64_t get_data(UintData type);

    void set_data(BoolData type, bool data);
    bool get_data(BoolData type);
    
    void set_data(DoubleData type, double data);
    double get_data(DoubleData type);

private:
    std::array<std::atomic_uint64_t, UintData::count> uints_;
    std::array<std::atomic_bool, BoolData::count> bools_;
    std::array<std::atomic_double, DoubleData::count> doubles_;
};



#endif // CONNECTOR_H
