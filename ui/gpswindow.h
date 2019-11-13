#ifndef GPSWINDOW_H
#define GPSWINDOW_H
#include "ui_form.h"
#include <QTimer>


class GPSWindow : public QWidget, public Ui_Form
{
    Q_OBJECT
public:
    GPSWindow(uint32_t refresh_rate);
    QTimer* timer_;
    void update(){
        this->push_data();
        this->QWidget::update();
    }

public slots:

    void push_data();

};

#endif // GPSWINDOW_H
