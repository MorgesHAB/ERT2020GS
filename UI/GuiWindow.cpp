#include "GuiWindow.h"
#include <iostream>
#include <ctime>
#include <QStyleFactory>
#include <QString>
#include <QMessageBox>
#include <QPixmap>
#include <QCoreApplication>
#include <array>

constexpr uint8_t THEME_NUMBER(3);


using namespace ui_interface;

inline QString degree_representation(double value){
    return QString::number(value)  + "<sup>o</sup>";
}

inline QString qstr(double value){
    return QString::number(value);
}
inline QString qstr(uint16_t value){
    return QString::number(value);
}
inline QString qstr(uint32_t value){
    return QString::number(value);
}
inline QString qstr(uint64_t value){
    return QString::number(value);
}



GuiWindow::GuiWindow(int refresh_rate, std::shared_ptr<Connector> connector) :
        timer_(new QTimer(this)),
        data_(connector),
        missed_count_(0),
        white_theme_(0),
        xbee_acvite_(false){
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles);
    QApplication::setStyle(QStyleFactory::create("cleanlooks"));
    Ui_Form::setupUi(this);
    connect(timer_, SIGNAL (timeout()), this, SLOT (refresh_data()));
    connect(xbee_button, SIGNAL (pressed()), this, SLOT (xbee_clicked()));
    connect(ignition_button, SIGNAL (pressed()), this, SLOT (ignite_clicked()));
    connect(change_theme, SIGNAL (pressed()), this, SLOT (theme_change_clicked()));
    timer_->start(refresh_rate);
}
//TODO This function is very bad structured, must fix
void GuiWindow::refresh_data() {
    //std::cout << "Data stored reads : " << data_->getData<float>(ui_interface::PRESSURE_DATA)  //<<std::endl;

	refresh_misses();
    miss_panel->setText(qstr(calculate_misses_in_last_2()));
    float tmp(data_->getData<float>(LATITUDE));
    latitude_panel->setText(degree_representation(tmp));
    tmp = data_->getData<float>(LONGITUDE);
    longitude_panel->setText(degree_representation(tmp));
    tmp = data_->getData<float>(ALTITUDE);
    this->altitude_lcd->display(tmp);
    this->last_packet_number_panel->setText(qstr(data_->getData<uint32_t>(TX_PACKET_NR)));
    received_pack_cnt_panel->setText(qstr(data_->getData<uint32_t>(RX_PACKET_CTR)));
    this->speed_lcd->display(data_->getData<float>(SPEED));
    time_t timestamp(data_->getData<time_t>(TIMESTAMP));
    char tbuffer[32];
    struct tm* tptr = std::localtime(&timestamp);
    std::strftime(tbuffer, 32, "%T", tptr);
    this->last_refresh_panel->setText(tbuffer);
    timestamp = std::time(nullptr);
    std::strftime(tbuffer, 32, "%H:%M:%S", tptr);
    time_panel->setText(tbuffer);
    this->rssi_panel->setText("NOT YET IMPLEMENTED");
    uint32_t packets(data_->eatData<uint32_t>(PACKET_RX_RATE_CTR, 0));
    packets_second_bar->setValue((int)(packets*(1000.0/(timer_->interval()))));
    if(data_->eatData<bool>(IGNITION_STATUS, false)){
        QMessageBox::warning(this, "Ignition", "BOOM!");
    }

    ++tick_counter_;
}

void GuiWindow::xbee_clicked() {

    if(!xbee_acvite_){
        std::cout << "XBee ON button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, true);
        xbee_button->setText("STOP XBee");
    }else {
        std::cout << "XBee STOP button clicked!" << std::endl;
        data_->setData(ui_interface::ACTIVE_XBEE, false);
        xbee_button->setText("START XBee");
    }
    xbee_acvite_ = !xbee_acvite_;

}



void GuiWindow::ignite_clicked() {
    std::cout << "Ignition button clicked!" << std::endl;
    data_->setData(ui_interface::IGNITION_CLICKED, true);
}

void GuiWindow::theme_change_clicked()
{
    if(white_theme_%THEME_NUMBER == 0){
        setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
        "color: rgb(0, 255, 0);"));
        packets_second_bar->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);"));
    }else if(white_theme_%THEME_NUMBER == 1){
        setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
        "color: rgb(0, 0, 0);"));
        packets_second_bar->setStyleSheet(QLatin1String("color: rgb(0,0,0);"));
    }else if(white_theme_%THEME_NUMBER == 2){
        setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
        "color: rgb(255, 255, 255);"));
        packets_second_bar->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);"));
    }
    ++white_theme_;
}

uint16_t GuiWindow::calculate_misses_in_last_2()
{
    static std::array<uint32_t, 4> before{0};

    uint64_t current(tick_counter_%4);
    uint64_t tmp(missed_count_ - before[current]);
    before[current] = missed_count_;
    return tmp;
}

void GuiWindow::closeEvent (QCloseEvent *event)
{
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "BELLA LUI 2020",
                                                                    tr("Ending mission Bella Lui 2020.\nAre you sure?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            event->accept();
            data_->setData(ui_interface::RUNNING, false);
		std::cout << "running set to false" << std::endl;
        }
}

void GuiWindow::refresh_misses()
{
    missed_count_ = data_->getData<uint32_t>(TX_PACKET_NR) -
            data_->getData<uint32_t>(RX_PACKET_CTR);
}

