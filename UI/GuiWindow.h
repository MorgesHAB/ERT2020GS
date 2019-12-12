/*!
 * \file GuiWindow.h
 *
 * \brief Gui Window module interface
 *
 * \author      KESKE CEM - EPFL EL BA3
 * \date        02.12.2019
 */

#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include "ui_form.h"
#include <QTimer>
#include <memory>
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include "QCloseEvent"


class GuiWindow : public QWidget, public Ui_Form {
Q_OBJECT
public:
    GuiWindow(int refresh_rate, std::shared_ptr<Connector> connector);
    void update();

    QTimer *timer_;

public slots:
    void refresh_data();
    void xbee_clicked();
    void ignite_clicked();
    void theme_change_clicked();

private:
    uint16_t calculate_misses_in_last_2();
    void closeEvent(QCloseEvent *event) override;
    void refresh_misses();

    std::shared_ptr<Connector> data_;
    uint64_t tick_counter_;
    uint64_t missed_count_;
    uint8_t white_theme_;
    bool xbee_acvite_;
};

#endif // GUIWINDOW_H
