/********************************************************************************
** Form generated from reading UI file 'press_altA14522.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PRESS_ALTA14522_H
#define PRESS_ALTA14522_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QGroupBox *telemetry_box;
    QGridLayout *gridLayout_3;
    QLabel *altitude_label;
    QLabel *speed_label;
    QLabel *latitude_label;
    QLCDNumber *speed_lcd;
    QLabel *latitude_panel;
    QLabel *longitude_label;
    QLabel *longitude_panel;
    QLCDNumber *altitude_lcd;
    QGroupBox *com_box;
    QGridLayout *gridLayout_4;
    QLabel *last_refresh_label;
    QLabel *last_packet_nbr_label;
    QLabel *packets_second_label;
    QProgressBar *packets_second_bar;
    QLabel *last_packet_number_panel;
    QLabel *rssi_label;
    QLabel *rssi_panel;
    QLabel *received_pack_cnt_label;
    QLabel *last_refresh_panel;
    QLabel *received_pack_cnt_panel;
    QLabel *miss_label;
    QLabel *miss_panel;
    QLabel *logo;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QLabel *time_panel;
    QPushButton *xbee_button;
    QPushButton *change_theme;
    QLabel *current_time_label;
    QWidget *button_widget;
    QGridLayout *gridLayout_2;
    QLabel *key_2_label;
    QPushButton *ignition_button;
    QLabel *ready_ignition_panel;
    QLabel *key_1_label;
    QLabel *key_2_panel;
    QLabel *key_1_panel;
    QLabel *red_button_label;
    QLabel *red_button_panel;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *code_3;
    QLabel *code_2;
    QLabel *code_1;
    QLabel *code_0;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(483, 457);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(0, 0));
        Form->setMaximumSize(QSize(1024, 720));
        Form->setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
"color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        telemetry_box = new QGroupBox(Form);
        telemetry_box->setObjectName(QStringLiteral("telemetry_box"));
        telemetry_box->setMinimumSize(QSize(0, 200));
        gridLayout_3 = new QGridLayout(telemetry_box);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        altitude_label = new QLabel(telemetry_box);
        altitude_label->setObjectName(QStringLiteral("altitude_label"));

        gridLayout_3->addWidget(altitude_label, 1, 0, 1, 1);

        speed_label = new QLabel(telemetry_box);
        speed_label->setObjectName(QStringLiteral("speed_label"));

        gridLayout_3->addWidget(speed_label, 8, 0, 1, 1);

        latitude_label = new QLabel(telemetry_box);
        latitude_label->setObjectName(QStringLiteral("latitude_label"));

        gridLayout_3->addWidget(latitude_label, 3, 0, 1, 1);

        speed_lcd = new QLCDNumber(telemetry_box);
        speed_lcd->setObjectName(QStringLiteral("speed_lcd"));
        speed_lcd->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(speed_lcd, 8, 1, 1, 1);

        latitude_panel = new QLabel(telemetry_box);
        latitude_panel->setObjectName(QStringLiteral("latitude_panel"));
        latitude_panel->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(latitude_panel, 3, 1, 1, 1);

        longitude_label = new QLabel(telemetry_box);
        longitude_label->setObjectName(QStringLiteral("longitude_label"));

        gridLayout_3->addWidget(longitude_label, 2, 0, 1, 1);

        longitude_panel = new QLabel(telemetry_box);
        longitude_panel->setObjectName(QStringLiteral("longitude_panel"));

        gridLayout_3->addWidget(longitude_panel, 2, 1, 1, 1);

        altitude_lcd = new QLCDNumber(telemetry_box);
        altitude_lcd->setObjectName(QStringLiteral("altitude_lcd"));
        altitude_lcd->setSmallDecimalPoint(false);
        altitude_lcd->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(altitude_lcd, 1, 1, 1, 1);


        gridLayout->addWidget(telemetry_box, 2, 0, 1, 2);

        com_box = new QGroupBox(Form);
        com_box->setObjectName(QStringLiteral("com_box"));
        gridLayout_4 = new QGridLayout(com_box);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        last_refresh_label = new QLabel(com_box);
        last_refresh_label->setObjectName(QStringLiteral("last_refresh_label"));

        gridLayout_4->addWidget(last_refresh_label, 7, 0, 1, 1);

        last_packet_nbr_label = new QLabel(com_box);
        last_packet_nbr_label->setObjectName(QStringLiteral("last_packet_nbr_label"));

        gridLayout_4->addWidget(last_packet_nbr_label, 2, 0, 1, 1);

        packets_second_label = new QLabel(com_box);
        packets_second_label->setObjectName(QStringLiteral("packets_second_label"));

        gridLayout_4->addWidget(packets_second_label, 4, 0, 1, 1);

        packets_second_bar = new QProgressBar(com_box);
        packets_second_bar->setObjectName(QStringLiteral("packets_second_bar"));
        packets_second_bar->setStyleSheet(QStringLiteral(""));
        packets_second_bar->setMaximum(70);
        packets_second_bar->setValue(60);
        packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(packets_second_bar, 4, 1, 1, 1);

        last_packet_number_panel = new QLabel(com_box);
        last_packet_number_panel->setObjectName(QStringLiteral("last_packet_number_panel"));

        gridLayout_4->addWidget(last_packet_number_panel, 2, 1, 1, 1);

        rssi_label = new QLabel(com_box);
        rssi_label->setObjectName(QStringLiteral("rssi_label"));

        gridLayout_4->addWidget(rssi_label, 3, 0, 1, 1);

        rssi_panel = new QLabel(com_box);
        rssi_panel->setObjectName(QStringLiteral("rssi_panel"));

        gridLayout_4->addWidget(rssi_panel, 3, 1, 1, 1);

        received_pack_cnt_label = new QLabel(com_box);
        received_pack_cnt_label->setObjectName(QStringLiteral("received_pack_cnt_label"));

        gridLayout_4->addWidget(received_pack_cnt_label, 1, 0, 1, 1);

        last_refresh_panel = new QLabel(com_box);
        last_refresh_panel->setObjectName(QStringLiteral("last_refresh_panel"));

        gridLayout_4->addWidget(last_refresh_panel, 7, 1, 1, 1);

        received_pack_cnt_panel = new QLabel(com_box);
        received_pack_cnt_panel->setObjectName(QStringLiteral("received_pack_cnt_panel"));

        gridLayout_4->addWidget(received_pack_cnt_panel, 1, 1, 1, 1);

        miss_label = new QLabel(com_box);
        miss_label->setObjectName(QStringLiteral("miss_label"));

        gridLayout_4->addWidget(miss_label, 6, 0, 1, 1);

        miss_panel = new QLabel(com_box);
        miss_panel->setObjectName(QStringLiteral("miss_panel"));

        gridLayout_4->addWidget(miss_panel, 6, 1, 1, 1);


        gridLayout->addWidget(com_box, 1, 1, 1, 2);

        logo = new QLabel(Form);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setStyleSheet(QStringLiteral("image: url(:/image.png);"));

        gridLayout->addWidget(logo, 2, 2, 1, 1);

        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        time_panel = new QLabel(widget);
        time_panel->setObjectName(QStringLiteral("time_panel"));
        time_panel->setMinimumSize(QSize(70, 0));
        time_panel->setMaximumSize(QSize(60, 16777215));
        time_panel->setStyleSheet(QStringLiteral(""));
        time_panel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(time_panel, 0, 3, 1, 1);

        xbee_button = new QPushButton(widget);
        xbee_button->setObjectName(QStringLiteral("xbee_button"));
        xbee_button->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(xbee_button, 0, 0, 1, 1);

        change_theme = new QPushButton(widget);
        change_theme->setObjectName(QStringLiteral("change_theme"));

        gridLayout_5->addWidget(change_theme, 0, 1, 1, 1);

        current_time_label = new QLabel(widget);
        current_time_label->setObjectName(QStringLiteral("current_time_label"));
        current_time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(current_time_label, 0, 2, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 3);

        button_widget = new QWidget(Form);
        button_widget->setObjectName(QStringLiteral("button_widget"));
        gridLayout_2 = new QGridLayout(button_widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        key_2_label = new QLabel(button_widget);
        key_2_label->setObjectName(QStringLiteral("key_2_label"));

        gridLayout_2->addWidget(key_2_label, 2, 0, 1, 1);

        ignition_button = new QPushButton(button_widget);
        ignition_button->setObjectName(QStringLiteral("ignition_button"));
        ignition_button->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(ignition_button, 0, 0, 1, 1);

        ready_ignition_panel = new QLabel(button_widget);
        ready_ignition_panel->setObjectName(QStringLiteral("ready_ignition_panel"));
        ready_ignition_panel->setMinimumSize(QSize(23, 0));
        ready_ignition_panel->setMaximumSize(QSize(23, 16777215));
        ready_ignition_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(ready_ignition_panel, 0, 1, 1, 1);

        key_1_label = new QLabel(button_widget);
        key_1_label->setObjectName(QStringLiteral("key_1_label"));

        gridLayout_2->addWidget(key_1_label, 1, 0, 1, 1);

        key_2_panel = new QLabel(button_widget);
        key_2_panel->setObjectName(QStringLiteral("key_2_panel"));
        key_2_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(key_2_panel, 2, 1, 1, 1);

        key_1_panel = new QLabel(button_widget);
        key_1_panel->setObjectName(QStringLiteral("key_1_panel"));
        key_1_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(key_1_panel, 1, 1, 1, 1);

        red_button_label = new QLabel(button_widget);
        red_button_label->setObjectName(QStringLiteral("red_button_label"));

        gridLayout_2->addWidget(red_button_label, 3, 0, 1, 1);

        red_button_panel = new QLabel(button_widget);
        red_button_panel->setObjectName(QStringLiteral("red_button_panel"));
        red_button_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(red_button_panel, 3, 1, 1, 1);

        frame = new QFrame(button_widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 35));
        frame->setStyleSheet(QLatin1String("border-color: rgb(255, 0, 0);\n"
"gridline-color: rgb(255, 0, 0);"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        code_3 = new QLabel(frame);
        code_3->setObjectName(QStringLiteral("code_3"));
        code_3->setMinimumSize(QSize(21, 0));
        code_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_3);

        code_2 = new QLabel(frame);
        code_2->setObjectName(QStringLiteral("code_2"));
        code_2->setMinimumSize(QSize(21, 0));
        code_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_2);

        code_1 = new QLabel(frame);
        code_1->setObjectName(QStringLiteral("code_1"));
        code_1->setMinimumSize(QSize(21, 0));
        code_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_1);

        code_0 = new QLabel(frame);
        code_0->setObjectName(QStringLiteral("code_0"));
        code_0->setMinimumSize(QSize(21, 0));
        code_0->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_0);


        gridLayout_2->addWidget(frame, 4, 0, 1, 2);


        gridLayout->addWidget(button_widget, 1, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "GSBellaLui2020", Q_NULLPTR));
        telemetry_box->setTitle(QApplication::translate("Form", "Telemetry", Q_NULLPTR));
        altitude_label->setText(QApplication::translate("Form", "ALTITUDE", Q_NULLPTR));
        speed_label->setText(QApplication::translate("Form", "SPEED", Q_NULLPTR));
        latitude_label->setText(QApplication::translate("Form", "LATITUDE", Q_NULLPTR));
        latitude_panel->setText(QString());
        longitude_label->setText(QApplication::translate("Form", "LONGITUDE", Q_NULLPTR));
        longitude_panel->setText(QString());
        com_box->setTitle(QApplication::translate("Form", "COM", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        last_refresh_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Last packet's timestamp</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        last_refresh_label->setText(QApplication::translate("Form", "Last Refresh", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        last_packet_nbr_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The last received packet's number (defined by TX)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        last_packet_nbr_label->setText(QApplication::translate("Form", "Last Packet Number", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        packets_second_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        packets_second_label->setText(QApplication::translate("Form", "Packets/second", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        last_packet_number_panel->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The last received packet's number (defined by TX)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        last_packet_number_panel->setText(QString());
        rssi_label->setText(QApplication::translate("Form", "RSSI", Q_NULLPTR));
        rssi_panel->setText(QString());
#ifndef QT_NO_TOOLTIP
        received_pack_cnt_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        received_pack_cnt_label->setText(QApplication::translate("Form", "Received Packet Count", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        last_refresh_panel->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Last packet's timestamp</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        last_refresh_panel->setText(QString());
#ifndef QT_NO_TOOLTIP
        received_pack_cnt_panel->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        received_pack_cnt_panel->setText(QString());
#ifndef QT_NO_TOOLTIP
        miss_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Lost packets in last 2 seconds</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        miss_label->setText(QApplication::translate("Form", "Misses", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        miss_panel->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Lost packets in last 2 seconds</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        miss_panel->setText(QString());
#ifndef QT_NO_TOOLTIP
        logo->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Project Bella Lui 2020</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        logo->setText(QString());
        time_panel->setText(QApplication::translate("Form", "44:44:44", Q_NULLPTR));
        xbee_button->setText(QApplication::translate("Form", "START XBee", Q_NULLPTR));
        change_theme->setText(QApplication::translate("Form", "Change Color Theme", Q_NULLPTR));
        current_time_label->setText(QApplication::translate("Form", "Current Time:", Q_NULLPTR));
        key_2_label->setText(QApplication::translate("Form", "KEY 2", Q_NULLPTR));
        ignition_button->setText(QApplication::translate("Form", "Ready For Ignition", Q_NULLPTR));
        ready_ignition_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        key_1_label->setText(QApplication::translate("Form", "KEY 1", Q_NULLPTR));
        key_2_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        key_1_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        red_button_label->setText(QApplication::translate("Form", "Red Button", Q_NULLPTR));
        red_button_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        code_3->setText(QString());
        code_2->setText(QString());
        code_1->setText(QString());
        code_0->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRESS_ALTA14522_H
