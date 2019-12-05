#ifndef GPSWINDOW_H
#define GPSWINDOW_H
#include "ui_form.h"
#include <QTimer>
#include <memory>
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"



class GPSWindow : public QWidget, public Ui_Form {
    Q_OBJECT
public:
    GPSWindow(int refresh_rate, std::shared_ptr<Connector> connector);
    virtual ~GPSWindow(){data_->setData(ui_interface::RUNNING, 0);}
    QTimer* timer_;
    void update();

public slots:
    void push_data();
    void xbee_clicked();

private:
    std::shared_ptr<Connector> data_;
};

#endif // GPSWINDOW_H
