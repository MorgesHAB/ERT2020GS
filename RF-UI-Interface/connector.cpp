/*!
 * \file connector.h
 *
 * \brief Connector module implementation
 *
 * \author      ISOZ Lionel - EPFL EL BA3
 * \author      KESKE Cem - EPFL EL BA3
 * \date        02.12.2019
 */

#include "connector.h"

constexpr uint64_t OFF_STATE(false);
constexpr uint64_t ON_STATE(true);


Connector::Connector() {
    for (size_t i(0); i < static_cast<size_t>(ui_interface::ARRAY_SIZE); ++i) {
         std::atomic_store(&(dataCollection[i]), OFF_STATE);
    }
    std::atomic_store(&dataCollection[int(ui_interface::RUNNING)], ON_STATE);
}

void Connector::incrementData(ui_interface::DataType type) {
    (&dataCollection[type])->fetch_add(1);
}

const std::string &Connector::getImgPLfilename() const {
    return imgPLfilename;
}

void Connector::setImgPLfilename(const std::string &imgPLfilename) {
    Connector::imgPLfilename = imgPLfilename;
}

void Connector::reset(ui_interface::DataType type) {
    std::atomic_store(&(dataCollection[type]), OFF_STATE);
}
