#include "connector.h"

constexpr bool OFF_STATE(false);
constexpr bool ON_STATE(true);


Connector::Connector() {
    for (size_t i(0); i < static_cast<size_t>(ui_interface::ARRAY_SIZE); ++i) {
        setData(static_cast<ui_interface::DataType>(i), OFF_STATE);
    }
    setData(ui_interface::RUNNING, ON_STATE);
}

void Connector::incrementData(ui_interface::DataType type) {
    (&dataCollection[type])->fetch_add(1);
}
