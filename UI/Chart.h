#pragma once

#include <qlineseries.h>

#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <memory>
#include <qrgb.h>

#include "ProtocolDefine.h"
#include "connector.h"

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Chart : public QChart {
  Q_OBJECT
 public:
  Chart(std::shared_ptr<Connector> connector, std::vector<ui_interface::DataType> dataTypes,
               std::vector<QRgb> colors, qreal refresh_time);
  virtual ~Chart();

  void setLineColor(QColor color);
  void setYRange(qreal min, qreal max);
  void setDataType(ui_interface::DataType dataType);

 public slots:
  void handleTimeout();

 private:
  std::shared_ptr<Connector> data_;
  QTimer m_timer;
  std::vector<QLineSeries *> m_series;
  QStringList m_titles;
  QValueAxis *m_axisX;
  QValueAxis *m_axisY;
  std::vector<qreal> m_x;
  std::vector<qreal> m_y;
  qreal refresh_time;
  std::vector<ui_interface::DataType> dataTypes;
};
