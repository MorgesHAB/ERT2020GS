/*!
 * \file GraphWindow.h
 *
 * \brief Graph Window module interface
 *
 * \author      De Buscchere Yanis - EPFL EL BA3
 * \date        03.03.2021
 */

#pragma once

#include <qmainwindow.h>
#include <qwidget.h>
#include <qwindow.h>
#include <qwindowdefs.h>

#include <QCloseEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QtCharts/QChartView>
#include <memory>

#include "../RF-UI-Interface/ProtocolDefine.h"
#include "../RF-UI-Interface/connector.h"
#include "gui_logger.h"
#include "ui_form.h"

class GraphWindow : public QWidget {
  Q_OBJECT
 public:
  GraphWindow(std::shared_ptr<Connector> connector);

  void addGraph(ui_interface::DataType dataType, QString name, QColor lineColor);

 private:
  std::shared_ptr<Connector> data_;
  QGridLayout *mainLayout;
};
