/*!
 * \file TerminalWindow.cpp
 *
 * \brief Terminal Window module interface
 *
 * \author      De Buscchere Yanis - EPFL EL BA3
 * \date        03.03.2021
 */

#include "TerminalWindow.h"

#include <QGridLayout>

TerminalWindow::TerminalWindow(std::shared_ptr<Connector> connector) : data_(connector) {
  mainLayout = new QGridLayout(this);
  setLayout(mainLayout);

  setStyleSheet(
      QLatin1String("min-height: 400px;\n"
                    "min-width: 500px;\n"
                    "background-color: rgb(30, 30, 30);\n"
                    "color: rgb(255, 255, 255);"));

  mainLayout->addWidget(&terminal);
}

TerminalWindow::~TerminalWindow(){}
