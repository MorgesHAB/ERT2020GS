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
#include <qgridlayout.h>
#include <qnamespace.h>
#include <qrgb.h>

#include <QtCharts/QChartView>

#include "Chart.h"

// GUI Window Class Functions

GraphWindow::GraphWindow(std::shared_ptr<Connector> connector) : data_(connector) {
  mainLayout = new QGridLayout(this);
  setLayout(mainLayout);

  setStyleSheet(
      QLatin1String("min-height: 400px;\n"
                    "min-width: 500px;\n"
                    "background-color: rgb(30, 30, 30);\n"
                    "color: rgb(255, 255, 255);"));


  addGraph(ui_interface::GPS_ALTITUDE, "Altitude", QColor(qRgb(255, 0, 0)));
}

void GraphWindow::addGraph(ui_interface::DataType dataType, QString name, QColor lineColor) {
  Chart *chart = new Chart(data_,dataType);
  chart->setTitle(name);
  chart->legend()->hide();
  chart->setAnimationOptions(QChart::AllAnimations);
  chart->setLineColor(lineColor);
  QtCharts::QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::HighQualityAntialiasing);
  mainLayout->addWidget(chartView);
}