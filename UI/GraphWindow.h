/*!
 * \file GraphWindow.h
 *
 * \brief Graph Window module interface
 *
 * \author      De Buscchere Yanis - EPFL EL BA3
 * \date        03.03.2021
 */

#pragma once

#include <QtCharts/QChartView>
#include <memory>

#include "../RF-UI-Interface/connector.h"
#include "ui_form.h"

class GraphWindow : public QWidget {
  Q_OBJECT
 public:
  GraphWindow(std::shared_ptr<Connector> connector);

  void addGraph(std::vector<ui_interface::DataType> dataTypes, std::vector<QRgb> colors,
                QString name, qreal refreshRate, qreal minY, qreal maxY);

 private:
  std::shared_ptr<Connector> data_;
  QGridLayout *main_layout;
  QGridLayout *graph_layout;
  QComboBox comboxBox;
  unsigned int count;
};

