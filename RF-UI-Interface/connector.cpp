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

void Connector::setData(ui_interface::StringType type, std::string s) {
    //std::atomic_store(&(dataCollection[type]), reinterpret_cast<uint64_t&> (s));

   // std::atomic_store(&(stringCollection[type]), &s);
}

std::string Connector::getData(ui_interface::StringType type) {
    return "a"; //std::move(std::atomic_load(&stringCollection[type]));
}

const std::string &Connector::getImgPLfilename() const {
    return imgPLfilename;
}

void Connector::setImgPLfilename(const std::string &imgPLfilename) {
    Connector::imgPLfilename = imgPLfilename;
}
