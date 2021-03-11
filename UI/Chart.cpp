#include "Chart.h"

#include <iostream>
#include <qlineseries.h>
#include <qpainter.h>

#include <QtCharts/QAbstractAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>
#include <QtCore/QRandomGenerator>
#include <memory>

#include "connector.h"

Chart::Chart(std::shared_ptr<Connector> connector, ui_interface::DataType dataType, QGraphicsItem *parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags),
      data_(connector),
      dataType(dataType),
      m_series(0),
      m_axisX(new QValueAxis()),
      m_axisY(new QValueAxis()),
      step_size(1000),
      m_x(0),
      m_y(0) {
  QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
  m_timer.setInterval(step_size);

  m_series = new QLineSeries(this);
  m_series->append(m_x, m_y);

  addSeries(m_series);

  addAxis(m_axisX, Qt::AlignBottom);
  addAxis(m_axisY, Qt::AlignLeft);
  m_series->attachAxis(m_axisX);
  m_series->attachAxis(m_axisY);
  m_axisX->setTickCount(11);
  m_axisX->setRange(0, 20);
  m_axisY->setRange(0, 100);

  setTheme(ChartThemeDark);
  setBackgroundBrush(QBrush(QColor(qRgb(30, 30, 30))));

  m_timer.start();
}

Chart::~Chart() {}

void Chart::setLineColor(QColor color) {
  QPen pen(color);
  pen.setWidth(3);
  m_series->setPen(pen);
}

void Chart::setDataType(ui_interface::DataType dataType) { this->dataType = dataType; }

void Chart::handleTimeout() {
  qreal x = plotArea().width() / (m_axisX->tickCount() - 1);
  m_x += step_size/1000;
  m_y = data_->getData<double>(dataType);
  m_series->append(m_x, m_y);
  if(m_axisX->max() -2 <= m_x)
    scroll(x, 0);
}
