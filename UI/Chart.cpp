#include "Chart.h"

#include <qlineseries.h>
#include <qpainter.h>
#include <qrgb.h>
#include <sys/types.h>

#include <QtCharts/QAbstractAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>
#include <cstddef>
#include <iostream>
#include <memory>

#include "connector.h"

Chart::Chart(std::shared_ptr<Connector> connector, std::vector<ui_interface::DataType> dataTypes,
             std::vector<QRgb> colors, qreal refresh_time)
    : QChart(QChart::ChartTypeCartesian, NULL, {}),
      data_(connector),
      dataTypes(dataTypes),
      m_series(0),
      m_axisX(new QValueAxis()),
      m_axisY(new QValueAxis()),
      refresh_time(refresh_time),
      m_timer(this) {
  m_timer.setInterval(refresh_time);
  m_timer.start();
  QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
  setAnimationDuration(refresh_time);

  addAxis(m_axisX, Qt::AlignBottom);
  addAxis(m_axisY, Qt::AlignLeft);
  m_axisX->setTickCount(11);
  m_axisY->setTickCount(11);
  m_axisX->setRange(0, 20);
  m_axisY->setRange(0, 100);

  size_t i(0);
  for (auto data : dataTypes) {
    m_series.push_back(new QLineSeries(this));
    m_x.push_back(0);
    m_y.push_back(0);
    m_series.back()->append(m_x.back(), m_y.back());
    m_series.back()->setColor(QColor(colors.at(i++)));
    addSeries(m_series.back());
    m_series.back()->attachAxis(m_axisX);
    m_series.back()->attachAxis(m_axisY);
  }

  setTheme(ChartThemeDark);
  setBackgroundBrush(QBrush(QColor(qRgb(30, 30, 30))));

  m_timer.start();
}

Chart::~Chart() {
  for (auto s : m_series) {
    delete (s);
  }
}

void Chart::setYRange(qreal min, qreal max) { m_axisY->setRange(min, max); }

void Chart::handleTimeout() {
  for (size_t i(0); i < dataTypes.size(); i++) {
    m_x.at(i) += refresh_time / 1000;

    m_y.at(i) = data_->getData<int16_t>(dataTypes.at(i)) / 10.0;

    m_series.at(i)->append(m_x.at(i), m_y.at(i));
    if (m_axisX->max() - 2 <= m_x.at(i)) {
      scroll(plotArea().width() / (m_axisX->tickCount() - 1), 0);
      m_series.at(i)->removePoints(0, 2 * 1000/refresh_time);
      std::cout <<  m_series.at(i)->points().size() << std::endl;
    }
  }

//qreal Chart::nextPoint(size_t i) {
//  if (dataTypes.at(i) == ui_interface::PP_TEMPERATURE_1) return data_->getData<int16_t>(dataTypes.at(i)) / 10.0; 
//}


}
