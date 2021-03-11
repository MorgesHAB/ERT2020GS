#pragma once

#include <memory>
#include <qlineseries.h>

#include <QtCharts/QChart>
#include <QtCore/QTimer>

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
  Chart(std::shared_ptr<Connector> connector, ui_interface::DataType dataType, QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
  virtual ~Chart();

  void setLineColor(QColor color);
  void setDataType(ui_interface::DataType dataType);

 public slots:
  void handleTimeout();

 private:
  std::shared_ptr<Connector> data_;
  QTimer m_timer;
  QLineSeries *m_series;
  QStringList m_titles;
  QValueAxis *m_axisX;
  QValueAxis *m_axisY;
  qreal m_x;
  qreal m_y;
  qreal step_size;
  ui_interface::DataType dataType;
};
