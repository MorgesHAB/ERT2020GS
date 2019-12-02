#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <atomic>
#include <array>

#include "ProtocolDefine.h"

class Connector {
public:
    Connector() = default;
    
    template<typename T>
    void set_data(ui_interface::DataType type, T t);

    template<typename T>
    T get_data(ui_interface::DataType type);

    /**
     * Returns the data contained in the corresponding
     * type leaving its value as '0'.
     */
    template<typename T>
    T eat_data(ui_interface::DataType type);

private:
    std::array<std::atomic_uint64_t, ui_interface::count> data_;
};




#endif // CONNECTOR_H
