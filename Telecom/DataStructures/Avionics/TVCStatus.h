#ifndef ERT2020GS_TVCSTATUS_H
#define ERT2020GS_TVCSTATUS_H

#include <Data.h>

class TVCStatus : public Data {
public:
  void write(Packet &packet) override;
  void parse(Packet &packet) override;

  void print() const override;
  std::string log() const override;

  bool updateTx(std::shared_ptr<Connector> connector) override;
  bool updateRx(std::shared_ptr<Connector> connector) override;

private:
  int32_t status;
  int32_t thrust;
};

#endif // ERT2020GS_TVCSTATUS_H
