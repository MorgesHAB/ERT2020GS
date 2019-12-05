#ifndef GUIWINDOW_H
#define GUIWINDOW_H
#include "ui_form.h"
#include <QTimer>
#include <memory>
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"



class GuiWindow : public QWidget, public Ui_Form {
    Q_OBJECT
public:
    GuiWindow(int refresh_rate, std::shared_ptr<Connector> connector);
    virtual ~GuiWindow(){data_->setData(ui_interface::RUNNING, 0);}
    QTimer* timer_;
    void update();

public slots:
    void push_data();
    void xbee_clicked();
    void xbee_stop_clicked();
    void ignite_clicked();

private:
    std::shared_ptr<Connector> data_;
};

#endif // GUIWINDOW_H
