#include "GuiWindow.h"
#include <iostream>
#include <QString>

GuiWindow::GuiWindow(int refresh_rate, std::shared_ptr<Connector> connector) :
        timer_(new QTimer(this)),
        data_(connector),
        white_theme_(false){
    Ui_Form::setupUi(this);
    connect(timer_, SIGNAL (timeout()), this, SLOT (push_data()));
    connect(xbee_button, SIGNAL (pressed()), this, SLOT (xbee_clicked()));
    connect(stop_xbee, SIGNAL (pressed()), this, SLOT (xbee_stop_clicked()));
    connect(ignition_button, SIGNAL (pressed()), this, SLOT (ignite_clicked()));
    connect(change_theme, SIGNAL (pressed()), this, SLOT (theme_change_clicked()));
    timer_->start(refresh_rate);
}

void GuiWindow::update() {
    this->push_data();
    this->QWidget::update();
}

void GuiWindow::push_data() {
    this->altitude_lcd->display(data_->getData<float>(ui_interface::PRESSURE_DATA));
    this->rssi_panel->setText(QString::number(0)  + "<sup>o</sup>");
}

void GuiWindow::xbee_clicked() {
    std::cout << "XBee ON button clicked!" << std::endl;
    data_->setData(ui_interface::ACTIVE_XBEE, true);
}

void GuiWindow::xbee_stop_clicked() {
    std::cout << "XBee STOP button clicked!" << std::endl;
    data_->setData(ui_interface::RUNNING, false);
}

void GuiWindow::ignite_clicked() {
    std::cout << "Ignition button clicked!" << std::endl;
    data_->setData(ui_interface::IGNITION_CLICKED, false);
}

void GuiWindow::theme_change_clicked()
{
    if(white_theme_){
        setStyleSheet(QLatin1String("background-color: rgb(35, 35, 35);\n"
        "color: rgb(51, 255, 0);"));
    }else{
        setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
        "color: rgb(0, 0, 0);"));
    }
    white_theme_ = !white_theme_;
}
