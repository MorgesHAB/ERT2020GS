/********************************************************************************
** Form generated from reading UI file 'press_altQb3989.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PRESS_ALTQB3989_H
#define PRESS_ALTQB3989_H

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
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QLabel *time_panel;
    QPushButton *xbee_button;
    QPushButton *change_theme;
    QLabel *current_time_label;
    QGroupBox *euler_box;
    QGridLayout *gridLayout_6;
    QLabel *euler_x_panel;
    QLabel *euler_y_panel;
    QLabel *euler_x_label;
    QLabel *euler_y_label;
    QLabel *euler_z_label;
    QLabel *euler_z_panel;
    QGroupBox *ignition_box;
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
    QGroupBox *avionics_box;
    QGridLayout *gridLayout_8;
    QLabel *altitude_label_telemetry;
    QLabel *speed_label;
    QLabel *temperature_label;
    QLabel *pressure_label;
    QLabel *temperature_panel;
    QLabel *pressure_panel;
    QLabel *speed_panel;
    QLabel *altitude_panel_telemetry;
    QLabel *logo;
    QGroupBox *accel_box;
    QGridLayout *gridLayout_7;
    QLabel *accel_x_label;
    QLabel *accel_z_label;
    QLabel *accel_y_label;
    QLabel *accel_x_panel;
    QLabel *accel_y_panel;
    QLabel *accel_z_panel;
    QGroupBox *com_box;
    QGridLayout *gridLayout_4;
    QLabel *last_refresh_label;
    QLabel *last_packet_nbr_label;
    QLabel *packets_second_label;
    QProgressBar *packets_second_bar;
    QLabel *last_packet_number_panel;
    QLabel *received_pack_cnt_label;
    QLabel *last_refresh_panel;
    QLabel *received_pack_cnt_panel;
    QLabel *miss_label;
    QLabel *miss_panel;
    QLabel *corrupted_label;
    QLabel *corrupted_panel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QLabel *receiver_state_label;
    QLabel *transmitter_state_label;
    QLabel *transmitter_state_panel;
    QPushButton *file_transmission_button;
    QLabel *receiver_state_panel;
    QProgressBar *file_transmission_progress_bar;
    QGroupBox *gps_box;
    QGridLayout *gridLayout_3;
    QLabel *altitude_label_gps;
    QLabel *latitude_label;
    QLabel *latitude_panel;
    QLabel *longitude_label;
    QLabel *longitude_panel;
    QLCDNumber *altitude_lcd_gps;
    QLabel *hdop_panel;
    QLabel *hdop_label;
    QLabel *sat_nbr_label;
    QLabel *sat_nbr_panel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(600, 609);
        Form->setMinimumSize(QSize(600, 0));
        Form->setMaximumSize(QSize(9999, 9999));
        Form->setMouseTracking(false);
        Form->setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
                                          "color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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

        gridLayout_5->addWidget(time_panel, 0, 4, 1, 1);

        xbee_button = new QPushButton(widget);
        xbee_button->setObjectName(QStringLiteral("xbee_button"));
        xbee_button->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(xbee_button, 0, 1, 1, 1);

        change_theme = new QPushButton(widget);
        change_theme->setObjectName(QStringLiteral("change_theme"));

        gridLayout_5->addWidget(change_theme, 0, 2, 1, 1);

        current_time_label = new QLabel(widget);
        current_time_label->setObjectName(QStringLiteral("current_time_label"));
        current_time_label->setMaximumSize(QSize(100, 16777215));
        current_time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(current_time_label, 0, 3, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 5);

        euler_box = new QGroupBox(Form);
        euler_box->setObjectName(QStringLiteral("euler_box"));
        gridLayout_6 = new QGridLayout(euler_box);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        euler_x_panel = new QLabel(euler_box);
        euler_x_panel->setObjectName(QStringLiteral("euler_x_panel"));

        gridLayout_6->addWidget(euler_x_panel, 0, 1, 1, 1);

        euler_y_panel = new QLabel(euler_box);
        euler_y_panel->setObjectName(QStringLiteral("euler_y_panel"));

        gridLayout_6->addWidget(euler_y_panel, 1, 1, 1, 1);

        euler_x_label = new QLabel(euler_box);
        euler_x_label->setObjectName(QStringLiteral("euler_x_label"));
        euler_x_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_6->addWidget(euler_x_label, 0, 0, 1, 1);

        euler_y_label = new QLabel(euler_box);
        euler_y_label->setObjectName(QStringLiteral("euler_y_label"));
        euler_y_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_6->addWidget(euler_y_label, 1, 0, 1, 1);

        euler_z_label = new QLabel(euler_box);
        euler_z_label->setObjectName(QStringLiteral("euler_z_label"));
        euler_z_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_6->addWidget(euler_z_label, 2, 0, 1, 1);

        euler_z_panel = new QLabel(euler_box);
        euler_z_panel->setObjectName(QStringLiteral("euler_z_panel"));

        gridLayout_6->addWidget(euler_z_panel, 2, 1, 1, 1);


        gridLayout->addWidget(euler_box, 5, 3, 1, 1);

        ignition_box = new QGroupBox(Form);
        ignition_box->setObjectName(QStringLiteral("ignition_box"));
        gridLayout_2 = new QGridLayout(ignition_box);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        key_2_label = new QLabel(ignition_box);
        key_2_label->setObjectName(QStringLiteral("key_2_label"));

        gridLayout_2->addWidget(key_2_label, 2, 0, 1, 1);

        ignition_button = new QPushButton(ignition_box);
        ignition_button->setObjectName(QStringLiteral("ignition_button"));
        ignition_button->setMinimumSize(QSize(132, 0));
        ignition_button->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(ignition_button, 0, 0, 1, 1);

        ready_ignition_panel = new QLabel(ignition_box);
        ready_ignition_panel->setObjectName(QStringLiteral("ready_ignition_panel"));
        ready_ignition_panel->setMinimumSize(QSize(23, 0));
        ready_ignition_panel->setMaximumSize(QSize(23, 16777215));
        ready_ignition_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(ready_ignition_panel, 0, 1, 1, 1);

        key_1_label = new QLabel(ignition_box);
        key_1_label->setObjectName(QStringLiteral("key_1_label"));

        gridLayout_2->addWidget(key_1_label, 1, 0, 1, 1);

        key_2_panel = new QLabel(ignition_box);
        key_2_panel->setObjectName(QStringLiteral("key_2_panel"));
        key_2_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(key_2_panel, 2, 1, 1, 1);

        key_1_panel = new QLabel(ignition_box);
        key_1_panel->setObjectName(QStringLiteral("key_1_panel"));
        key_1_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(key_1_panel, 1, 1, 1, 1);

        red_button_label = new QLabel(ignition_box);
        red_button_label->setObjectName(QStringLiteral("red_button_label"));

        gridLayout_2->addWidget(red_button_label, 3, 0, 1, 1);

        red_button_panel = new QLabel(ignition_box);
        red_button_panel->setObjectName(QStringLiteral("red_button_panel"));
        red_button_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(red_button_panel, 3, 1, 1, 1);

        frame = new QFrame(ignition_box);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setMaximumSize(QSize(16777215, 35));
        frame->setStyleSheet(QLatin1String("border-color: rgb(255, 0, 0);\n"
                                           "gridline-color: rgb(255, 0, 0);"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        code_3 = new QLabel(frame);
        code_3->setObjectName(QStringLiteral("code_3"));
        code_3->setMinimumSize(QSize(21, 21));
        code_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_3);

        code_2 = new QLabel(frame);
        code_2->setObjectName(QStringLiteral("code_2"));
        code_2->setMinimumSize(QSize(21, 21));
        code_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_2);

        code_1 = new QLabel(frame);
        code_1->setObjectName(QStringLiteral("code_1"));
        code_1->setMinimumSize(QSize(21, 21));
        code_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_1);

        code_0 = new QLabel(frame);
        code_0->setObjectName(QStringLiteral("code_0"));
        code_0->setMinimumSize(QSize(21, 21));
        code_0->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_0);


        gridLayout_2->addWidget(frame, 4, 0, 1, 2);


        gridLayout->addWidget(ignition_box, 2, 0, 1, 1);

        avionics_box = new QGroupBox(Form);
        avionics_box->setObjectName(QStringLiteral("avionics_box"));
        gridLayout_8 = new QGridLayout(avionics_box);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        altitude_label_telemetry = new QLabel(avionics_box);
        altitude_label_telemetry->setObjectName(QStringLiteral("altitude_label_telemetry"));

        gridLayout_8->addWidget(altitude_label_telemetry, 3, 0, 1, 1);

        speed_label = new QLabel(avionics_box);
        speed_label->setObjectName(QStringLiteral("speed_label"));

        gridLayout_8->addWidget(speed_label, 2, 0, 1, 1);

        temperature_label = new QLabel(avionics_box);
        temperature_label->setObjectName(QStringLiteral("temperature_label"));

        gridLayout_8->addWidget(temperature_label, 0, 0, 1, 1);

        pressure_label = new QLabel(avionics_box);
        pressure_label->setObjectName(QStringLiteral("pressure_label"));

        gridLayout_8->addWidget(pressure_label, 1, 0, 1, 1);

        temperature_panel = new QLabel(avionics_box);
        temperature_panel->setObjectName(QStringLiteral("temperature_panel"));

        gridLayout_8->addWidget(temperature_panel, 0, 1, 1, 1);

        pressure_panel = new QLabel(avionics_box);
        pressure_panel->setObjectName(QStringLiteral("pressure_panel"));

        gridLayout_8->addWidget(pressure_panel, 1, 1, 1, 1);

        speed_panel = new QLabel(avionics_box);
        speed_panel->setObjectName(QStringLiteral("speed_panel"));

        gridLayout_8->addWidget(speed_panel, 2, 1, 1, 1);

        altitude_panel_telemetry = new QLabel(avionics_box);
        altitude_panel_telemetry->setObjectName(QStringLiteral("altitude_panel_telemetry"));

        gridLayout_8->addWidget(altitude_panel_telemetry, 3, 1, 1, 1);


        gridLayout->addWidget(avionics_box, 3, 3, 2, 1);

        logo = new QLabel(Form);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setStyleSheet(QLatin1String("\n"
                                          "\n"
                                          "image: url(:/assets/logo.png);"));

        gridLayout->addWidget(logo, 5, 4, 1, 1);

        accel_box = new QGroupBox(Form);
        accel_box->setObjectName(QStringLiteral("accel_box"));
        gridLayout_7 = new QGridLayout(accel_box);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        accel_x_label = new QLabel(accel_box);
        accel_x_label->setObjectName(QStringLiteral("accel_x_label"));
        accel_x_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(accel_x_label, 0, 0, 1, 1);

        accel_z_label = new QLabel(accel_box);
        accel_z_label->setObjectName(QStringLiteral("accel_z_label"));
        accel_z_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(accel_z_label, 2, 0, 1, 1);

        accel_y_label = new QLabel(accel_box);
        accel_y_label->setObjectName(QStringLiteral("accel_y_label"));
        accel_y_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(accel_y_label, 1, 0, 1, 1);

        accel_x_panel = new QLabel(accel_box);
        accel_x_panel->setObjectName(QStringLiteral("accel_x_panel"));

        gridLayout_7->addWidget(accel_x_panel, 0, 1, 1, 1);

        accel_y_panel = new QLabel(accel_box);
        accel_y_panel->setObjectName(QStringLiteral("accel_y_panel"));

        gridLayout_7->addWidget(accel_y_panel, 1, 1, 1, 1);

        accel_z_panel = new QLabel(accel_box);
        accel_z_panel->setObjectName(QStringLiteral("accel_z_panel"));

        gridLayout_7->addWidget(accel_z_panel, 2, 1, 1, 1);


        gridLayout->addWidget(accel_box, 3, 4, 2, 1);

        com_box = new QGroupBox(Form);
        com_box->setObjectName(QStringLiteral("com_box"));
        gridLayout_4 = new QGridLayout(com_box);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        last_refresh_label = new QLabel(com_box);
        last_refresh_label->setObjectName(QStringLiteral("last_refresh_label"));

        gridLayout_4->addWidget(last_refresh_label, 6, 0, 1, 1);

        last_packet_nbr_label = new QLabel(com_box);
        last_packet_nbr_label->setObjectName(QStringLiteral("last_packet_nbr_label"));

        gridLayout_4->addWidget(last_packet_nbr_label, 2, 0, 1, 1);

        packets_second_label = new QLabel(com_box);
        packets_second_label->setObjectName(QStringLiteral("packets_second_label"));

        gridLayout_4->addWidget(packets_second_label, 3, 0, 1, 1);

        packets_second_bar = new QProgressBar(com_box);
        packets_second_bar->setObjectName(QStringLiteral("packets_second_bar"));
        packets_second_bar->setStyleSheet(QStringLiteral(""));
        packets_second_bar->setMaximum(40);
        packets_second_bar->setValue(30);
        packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(packets_second_bar, 3, 1, 1, 1);

        last_packet_number_panel = new QLabel(com_box);
        last_packet_number_panel->setObjectName(QStringLiteral("last_packet_number_panel"));

        gridLayout_4->addWidget(last_packet_number_panel, 2, 1, 1, 1);

        received_pack_cnt_label = new QLabel(com_box);
        received_pack_cnt_label->setObjectName(QStringLiteral("received_pack_cnt_label"));

        gridLayout_4->addWidget(received_pack_cnt_label, 1, 0, 1, 1);

        last_refresh_panel = new QLabel(com_box);
        last_refresh_panel->setObjectName(QStringLiteral("last_refresh_panel"));

        gridLayout_4->addWidget(last_refresh_panel, 6, 1, 1, 1);

        received_pack_cnt_panel = new QLabel(com_box);
        received_pack_cnt_panel->setObjectName(QStringLiteral("received_pack_cnt_panel"));

        gridLayout_4->addWidget(received_pack_cnt_panel, 1, 1, 1, 1);

        miss_label = new QLabel(com_box);
        miss_label->setObjectName(QStringLiteral("miss_label"));

        gridLayout_4->addWidget(miss_label, 5, 0, 1, 1);

        miss_panel = new QLabel(com_box);
        miss_panel->setObjectName(QStringLiteral("miss_panel"));

        gridLayout_4->addWidget(miss_panel, 5, 1, 1, 1);

        corrupted_label = new QLabel(com_box);
        corrupted_label->setObjectName(QStringLiteral("corrupted_label"));

        gridLayout_4->addWidget(corrupted_label, 7, 0, 1, 1);

        corrupted_panel = new QLabel(com_box);
        corrupted_panel->setObjectName(QStringLiteral("corrupted_panel"));

        gridLayout_4->addWidget(corrupted_panel, 7, 1, 1, 1);


        gridLayout->addWidget(com_box, 2, 1, 1, 4);

        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        receiver_state_label = new QLabel(groupBox);
        receiver_state_label->setObjectName(QStringLiteral("receiver_state_label"));
        receiver_state_label->setMinimumSize(QSize(140, 0));
        receiver_state_label->setMaximumSize(QSize(212411, 16777215));

        gridLayout_9->addWidget(receiver_state_label, 1, 0, 1, 1);

        transmitter_state_label = new QLabel(groupBox);
        transmitter_state_label->setObjectName(QStringLiteral("transmitter_state_label"));
        transmitter_state_label->setMinimumSize(QSize(140, 0));
        transmitter_state_label->setMaximumSize(QSize(1241251, 16777215));

        gridLayout_9->addWidget(transmitter_state_label, 2, 0, 1, 1);

        transmitter_state_panel = new QLabel(groupBox);
        transmitter_state_panel->setObjectName(QStringLiteral("transmitter_state_panel"));

        gridLayout_9->addWidget(transmitter_state_panel, 2, 1, 1, 1);

        file_transmission_button = new QPushButton(groupBox);
        file_transmission_button->setObjectName(QStringLiteral("file_transmission_button"));

        gridLayout_9->addWidget(file_transmission_button, 0, 0, 1, 2);

        receiver_state_panel = new QLabel(groupBox);
        receiver_state_panel->setObjectName(QStringLiteral("receiver_state_panel"));

        gridLayout_9->addWidget(receiver_state_panel, 1, 1, 1, 1);

        file_transmission_progress_bar = new QProgressBar(groupBox);
        file_transmission_progress_bar->setObjectName(QStringLiteral("file_transmission_progress_bar"));
        file_transmission_progress_bar->setValue(24);

        gridLayout_9->addWidget(file_transmission_progress_bar, 3, 0, 1, 2);


        gridLayout->addWidget(groupBox, 5, 0, 1, 3);

        gps_box = new QGroupBox(Form);
        gps_box->setObjectName(QStringLiteral("gps_box"));
        gps_box->setMinimumSize(QSize(0, 200));
        gridLayout_3 = new QGridLayout(gps_box);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        altitude_label_gps = new QLabel(gps_box);
        altitude_label_gps->setObjectName(QStringLiteral("altitude_label_gps"));

        gridLayout_3->addWidget(altitude_label_gps, 1, 0, 1, 1);

        latitude_label = new QLabel(gps_box);
        latitude_label->setObjectName(QStringLiteral("latitude_label"));

        gridLayout_3->addWidget(latitude_label, 3, 0, 1, 1);

        latitude_panel = new QLabel(gps_box);
        latitude_panel->setObjectName(QStringLiteral("latitude_panel"));
        latitude_panel->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(latitude_panel, 3, 1, 1, 1);

        longitude_label = new QLabel(gps_box);
        longitude_label->setObjectName(QStringLiteral("longitude_label"));

        gridLayout_3->addWidget(longitude_label, 2, 0, 1, 1);

        longitude_panel = new QLabel(gps_box);
        longitude_panel->setObjectName(QStringLiteral("longitude_panel"));

        gridLayout_3->addWidget(longitude_panel, 2, 1, 1, 1);

        altitude_lcd_gps = new QLCDNumber(gps_box);
        altitude_lcd_gps->setObjectName(QStringLiteral("altitude_lcd_gps"));
        altitude_lcd_gps->setSmallDecimalPoint(false);
        altitude_lcd_gps->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(altitude_lcd_gps, 1, 1, 1, 1);

        hdop_panel = new QLabel(gps_box);
        hdop_panel->setObjectName(QStringLiteral("hdop_panel"));

        gridLayout_3->addWidget(hdop_panel, 4, 1, 1, 1);

        hdop_label = new QLabel(gps_box);
        hdop_label->setObjectName(QStringLiteral("hdop_label"));

        gridLayout_3->addWidget(hdop_label, 4, 0, 1, 1);

        sat_nbr_label = new QLabel(gps_box);
        sat_nbr_label->setObjectName(QStringLiteral("sat_nbr_label"));

        gridLayout_3->addWidget(sat_nbr_label, 5, 0, 1, 1);

        sat_nbr_panel = new QLabel(gps_box);
        sat_nbr_panel->setObjectName(QStringLiteral("sat_nbr_panel"));

        gridLayout_3->addWidget(sat_nbr_panel, 5, 1, 1, 1);


        gridLayout->addWidget(gps_box, 3, 0, 2, 3);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "GSBellaLui2020", Q_NULLPTR));
        time_panel->setText(QApplication::translate("Form", "44:44:44", Q_NULLPTR));
        xbee_button->setText(QApplication::translate("Form", "START XBee", Q_NULLPTR));
        change_theme->setText(QApplication::translate("Form", "Change Color Theme", Q_NULLPTR));
        current_time_label->setText(QApplication::translate("Form", "Current Time:", Q_NULLPTR));
        euler_box->setTitle(QApplication::translate("Form", "Euler angles", Q_NULLPTR));
        euler_x_panel->setText(QString());
        euler_y_panel->setText(QString());
        euler_x_label->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        euler_y_label->setText(QApplication::translate("Form", "Y", Q_NULLPTR));
        euler_z_label->setText(QApplication::translate("Form", "Z", Q_NULLPTR));
        euler_z_panel->setText(QString());
        ignition_box->setTitle(QApplication::translate("Form", "Ignition", Q_NULLPTR));
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
        avionics_box->setTitle(QApplication::translate("Form", "Avionics Data", Q_NULLPTR));
        altitude_label_telemetry->setText(QApplication::translate("Form", "ALT.", Q_NULLPTR));
        speed_label->setText(QApplication::translate("Form", "SPEED", Q_NULLPTR));
        temperature_label->setText(QApplication::translate("Form", "TEMP", Q_NULLPTR));
        pressure_label->setText(QApplication::translate("Form", "PRESS.", Q_NULLPTR));
        temperature_panel->setText(QString());
        pressure_panel->setText(QString());
        speed_panel->setText(QString());
        altitude_panel_telemetry->setText(QString());
#ifndef QT_NO_TOOLTIP
        logo->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Project Bella Lui 2020</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        logo->setText(QString());
        accel_box->setTitle(QApplication::translate("Form", "Accelerometer", Q_NULLPTR));
        accel_x_label->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        accel_z_label->setText(QApplication::translate("Form", "Z", Q_NULLPTR));
        accel_y_label->setText(QApplication::translate("Form", "Y", Q_NULLPTR));
        accel_x_panel->setText(QString());
        accel_y_panel->setText(QString());
        accel_z_panel->setText(QString());
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
        corrupted_label->setText(QApplication::translate("Form", "Corrupted Packets", Q_NULLPTR));
        corrupted_panel->setText(QString());
        groupBox->setTitle(QApplication::translate("Form", "File Transmission", Q_NULLPTR));
        receiver_state_label->setText(QApplication::translate("Form", "Receiver State", Q_NULLPTR));
        transmitter_state_label->setText(QApplication::translate("Form", "Transmitter State", Q_NULLPTR));
        transmitter_state_panel->setText(QString());
        file_transmission_button->setText(QApplication::translate("Form", "Start File Transmission", Q_NULLPTR));
        receiver_state_panel->setText(QString());
        file_transmission_progress_bar->setFormat(QApplication::translate("Form", "%v / %m", Q_NULLPTR));
        gps_box->setTitle(QApplication::translate("Form", "GPS", Q_NULLPTR));
        altitude_label_gps->setText(QApplication::translate("Form", "ALTITUDE", Q_NULLPTR));
        latitude_label->setText(QApplication::translate("Form", "LATITUDE", Q_NULLPTR));
        latitude_panel->setText(QString());
        longitude_label->setText(QApplication::translate("Form", "LONGITUDE", Q_NULLPTR));
        longitude_panel->setText(QString());
        hdop_panel->setText(QString());
        hdop_label->setText(QApplication::translate("Form", "HDOP", Q_NULLPTR));
        sat_nbr_label->setText(QApplication::translate("Form", "SATELLITES", Q_NULLPTR));
        sat_nbr_panel->setText(QString());
    } // retranslateUi

};

namespace Ui {
class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRESS_ALTQB3989_H
