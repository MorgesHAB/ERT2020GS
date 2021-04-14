//
// Created by stephanie on 13/02/20.
//

#include "GSESensors.h"

void GSESensors::write(Packet &packet) {
  packet.write(fill_valve_state);
  packet.write(purge_valve_state);
  packet.write(main_ignition_state);
  packet.write(secondary_ignition_state);
  packet.write(main_disconnect_state);
  packet.write(secondary_disconnect_state);
  packet.write(battery_level);
  packet.write(hose_pressure);
  packet.write(hose_temperature);
  packet.write(tank_temp);
  packet.write(rocket_weight);
  packet.write(main_ignition_current);
  packet.write(secondary_ignition_current);
  packet.write(main_disconnect_current);
  packet.write(secondary_disconnect_current);
  packet.write(fill_valve_current);
  packet.write(purge_valve_current);
  packet.write(wind_speed);
}

void GSESensors::parse(Packet &packet) {
  packet.parse(fill_valve_state);
  packet.parse(purge_valve_state);
  packet.parse(main_ignition_state);
  packet.parse(secondary_ignition_state);
  packet.parse(main_disconnect_state);
  packet.parse(secondary_disconnect_state);
  packet.parse(battery_level);
  packet.parse(hose_pressure);
  packet.parse(hose_temperature);
  packet.parse(tank_temp);
  packet.parse(rocket_weight);
  packet.parse(main_ignition_current);
  packet.parse(secondary_ignition_current);
  packet.parse(main_disconnect_current);
  packet.parse(secondary_disconnect_current);
  packet.parse(fill_valve_current);
  packet.parse(purge_valve_current);
  packet.parse(wind_speed);
}

void GSESensors::print() const {
  return;
  std::cout << "GSE SENSORS PACKET\n"
            << std::endl
            << "States:  [" << fill_valve_state << "," << purge_valve_state << ","
            << main_ignition_state << "," << secondary_ignition_state << ","
            << main_disconnect_state << "," << secondary_disconnect_state << "]\n"
            << "Battery: " << battery_level << "\n"
            << "Hose pressure : " << hose_pressure << "\n"
            << "Hose temperature : " << hose_temperature << "\n"
            << "Tank temperature : " << tank_temp << "\n"
            << "Rocket weight : " << rocket_weight << "\n"
            << "Main ignition current : " << main_ignition_current << "\n"
            << "Secondary ignition current : " << secondary_ignition_current << "\n"
            << "Main disconnect current : " << main_disconnect_current << "\n"
            << "Secondary disconnect current : " << secondary_disconnect_current << "\n"
            << "Fill valve current : " << fill_valve_current << "\n"
            << "Purge valve current : " << purge_valve_current << "\n"
            << "Wind speed : " << wind_speed << "\n"
            << std::endl;
}
std::string GSESensors::log() const {
  return "GSE sensors" + SEPARATOR + std::to_string((float)battery_level);
}

bool GSESensors::updateTx(std::shared_ptr<Connector> connector) { return true; }

bool GSESensors::updateRx(std::shared_ptr<Connector> connector) {
  // update states
  connector->setData(ui_interface::GSE_SECONDARY_IGNITION_STATE, secondary_ignition_state);
  connector->setData(ui_interface::GSE_MAIN_IGNITION_STATE, main_ignition_state);
  connector->setData(ui_interface::GSE_MAIN_DISCONNECT_STATE, main_disconnect_state);
  connector->setData(ui_interface::GSE_SECONDARY_DISCONNECT_STATE, secondary_disconnect_state);
  connector->setData(ui_interface::GSE_PURGE_VALVE_STATE, purge_valve_state);
  connector->setData(ui_interface::GSE_FILL_VALVE_STATE, fill_valve_state);
  // update data
  connector->setData(ui_interface::GSE_MAIN_IGNITION_CURRENT, main_ignition_current);
  connector->setData(ui_interface::GSE_HOSE_PRESSURE, hose_pressure);
  connector->setData(ui_interface::GSE_BATTERY_LEVEL, battery_level);
  connector->setData(ui_interface::GSE_SECONDARY_IGNITION_CURRENT, secondary_ignition_current);
  connector->setData(ui_interface::GSE_MAIN_DISCONNECT_CURRENT, main_disconnect_current);
  connector->setData(ui_interface::GSE_SECONDARY_DISCONNECT_CURRENT, secondary_disconnect_current);
  connector->setData(ui_interface::GSE_FILL_VALVE_CURRENT, fill_valve_current);
  connector->setData(ui_interface::GSE_PURGE_VALVE_CURRENT, purge_valve_current);
  connector->setData(ui_interface::GSE_ROCKET_WEIGHT, rocket_weight);
  connector->setData(ui_interface::GSE_TANK_TEMP, tank_temp);
  connector->setData(ui_interface::GSE_HOSE_TEMP, hose_temperature);
  connector->setData(ui_interface::GSE_WIND_SPEED, wind_speed);

  return true;
}
