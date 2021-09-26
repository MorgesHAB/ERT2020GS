#include "TVCStatus.h"
#include "TVCStatusValue.h"

void TVCStatus::write(Packet &packet) { packet.write(status); }

void TVCStatus::parse(Packet &packet) { packet.parse(status); }

void TVCStatus::print() const { std::cout << tvc_status::status_name[status]; }

bool TVCStatus::updateTx(std::shared_ptr<Connector> connector) { return false; }

bool TVCStatus::updateRx(std::shared_ptr<Connector> connector) {
  connector->setData(ui_interface::TVC_STATUS, status);
  return true;
}

std::string TVCStatus::log() const {
  return std::move("TVC" + SEPARATOR + std::to_string(status));
}
