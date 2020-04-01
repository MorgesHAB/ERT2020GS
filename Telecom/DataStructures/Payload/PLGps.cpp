//
// Created by stephanie on 12/03/20.
//

#include "PLGps.h"

void PLGps::write(Packet &packet) {
    packet.write(satelliteNbr);
    packet.write(hdop);
    packet.write(latitude);
    packet.write(longitude);
    packet.write(altitude);
}

void PLGps::parse(Packet &packet) {
    packet.parse(satelliteNbr);
    packet.parse(hdop);
    packet.parse(latitude);
    packet.parse(longitude);
    packet.parse(altitude);
}

void PLGps::print() const {

}

std::string PLGps::log() const {
   return std::move( "GPS PAYLOAD" + SEPARATOR +
                             std::to_string(latitude) + SEPARATOR +
                             std::to_string(longitude) + SEPARATOR +
                             std::to_string(altitude) + SEPARATOR +
                             std::to_string(hdop) + SEPARATOR +
                             std::to_string(satelliteNbr) + SEPARATOR);
}

bool PLGps::updateRx(std::shared_ptr<Connector> connector) {
    connector->setData(ui_interface::PL_GPS_LATITUDE, latitude);
    connector->setData(ui_interface::PL_GPS_LONGITUDE, longitude);
    connector->setData(ui_interface::PL_GPS_ALTITUDE, altitude);
    connector->setData(ui_interface::PL_GPS_HDOP, hdop);
    connector->setData(ui_interface::PL_GPS_SAT_NBR, satelliteNbr);
    return true;
}
