#ifndef GPSWINDOW_H
#define GPSWINDOW_H
#include "ui_form.h"
#include <QTimer>
#include <LoRa.h>
#include <DataHandler.h>


class GPSWindow : public QWidget, public Ui_Form {
    Q_OBJECT
public:
    GPSWindow(uint32_t refresh_rate);
    QTimer* timer_;
    void update();

public slots:
    void push_data();

private:
    LoRa loRa;
    DataHandler dataHandler;
};

#endif // GPSWINDOW_H
