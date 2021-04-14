/*!
 * \file GraphWindow.h
 *
 * \brief Graph Window module interface
 *
 * \author      De Buscchere Yanis - EPFL EL BA3
 * \date        03.03.2021
 */

#pragma once

#include <QWidget>
#include <QGridLayout>
#include <memory>

#include "Terminal.h"

#include "../RF-UI-Interface/connector.h"

class TerminalWindow : public QWidget {
  Q_OBJECT;
 public:
  TerminalWindow(std::shared_ptr<Connector> connector);
  ~TerminalWindow();

 private:
  Terminal terminal;
  std::shared_ptr<Connector> data_;
  QGridLayout *mainLayout;
};
