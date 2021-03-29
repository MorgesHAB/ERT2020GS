/*!
 * \file GraphWindow.cpp
 *
 * \brief Graph Window module interface
 *
 * \author      De Buscchere Yanis - EPFL EL BA3
 * \date        03.03.2021
 */

#include "GraphWindow.h"

#include <qchartview.h>
#include <qcombobox.h>
#include <qgridlayout.h>
#include <qnamespace.h>
#include <qrgb.h>

#include <QtCharts/QChartView>
#include <vector>

#include "../RF-UI-Interface/connector.h"
#include "Chart.h"
#include "ProtocolDefine.h"

// GUI Window Class Functions

GraphWindow::GraphWindow(std::shared_ptr<Connector> connector) : data_(connector) {
  main_layout = new QGridLayout(this);
  graph_layout = new QGridLayout(this);
  //QComboBox *comboxBox = new QComboBox(this);
  //main_layout->addWidget(comboxBox, 0, 0);
  main_layout->addLayout(graph_layout, 1, 0);
  setLayout(main_layout);

  setStyleSheet(
      QLatin1String("min-height: 300px;\n"
                    "min-width: 400px;\n"
                    "background-color: rgb(30, 30, 30);\n"
                    "color: rgb(255, 255, 255);"));

  addGraph(std::vector<ui_interface::DataType>{ui_interface::PP_TEMPERATURE_1,
                                               ui_interface::PP_TEMPERATURE_2,
                                               ui_interface::PP_TEMPERATURE_3},
           std::vector<QRgb>{qRgb(255, 0, 0), qRgb(0, 255, 0), qRgb(0, 0, 255)}, "PP Temperatures",
           100, -30, 80);
}

void GraphWindow::addGraph(std::vector<ui_interface::DataType> dataTypes, std::vector<QRgb> colors,
                           QString name, qreal refreshRate, qreal minY, qreal maxY) {
  Chart *chart = new Chart(data_, dataTypes, colors, refreshRate);
  chart->setTitle(name);
  chart->legend()->hide();
  chart->setAnimationOptions(QChart::AllAnimations);
  chart->setYRange(minY, maxY);
  QtCharts::QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::HighQualityAntialiasing);
  graph_layout->addWidget(chartView);
}
