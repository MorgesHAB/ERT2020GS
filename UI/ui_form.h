/********************************************************************************
** Form generated from reading UI file 'WasserfallenGUID10596.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WASSERFALLENGUID10596_H
#define WASSERFALLENGUID10596_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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
    QGridLayout *gridLayout_10;
    QGroupBox *av_states_box;
    QGridLayout *gridLayout_11;
    QLabel *sleep_label;
    QLabel *sleep_state_ok_panel;
    QLabel *calibration_label;
    QLabel *calibration_state_ok_panel;
    QLabel *idle_label;
    QLabel *idle_state_ok_panel;
    QLabel *filling_label_av;
    QLabel *filling_av_ok_panel;
    QLabel *liftoff_label;
    QLabel *liftoff_state_ok_panel;
    QLabel *coast_label;
    QLabel *coast_state_ok_panel;
    QLabel *first_event_label;
    QLabel *first_event_ok_panel;
    QLabel *second_event_label;
    QLabel *second_event_ok_panel;
    QLabel *touchdown_label;
    QLabel *touchdown_event_ok_panel;
    QGroupBox *avionics_box;
    QGridLayout *gridLayout_8;
    QLabel *hpa_unit_label;
    QLabel *avionics_state_label;
    QLabel *pressure_label;
    QLabel *altitude_panel_telemetry;
    QLabel *speed_label;
    QLabel *m_unit_label_3;
    QLabel *altitude_label_telemetry;
    QLabel *speed_panel;
    QLabel *avionics_state_panel;
    QLabel *temperature_panel;
    QLabel *pressure_panel;
    QLabel *m_s_unit_label;
    QLabel *temperature_label;
    QLabel *celcius_label;
    QGroupBox *ignition_box;
    QGridLayout *gridLayout_2;
    QPushButton *ignition_button;
    QLabel *ready_ignition_panel;
    QLabel *key_1_label;
    QLabel *key_1_panel;
    QLabel *key_2_label;
    QLabel *key_2_panel;
    QLabel *red_button_label;
    QLabel *red_button_panel;
    QLabel *ignition_status_label;
    QFrame *ignition_frame;
    QHBoxLayout *horizontalLayout;
    QLabel *code_3;
    QLabel *code_2;
    QLabel *code_1;
    QLabel *code_0;
    QWidget *widget;
    QGridLayout *gridLayout_9;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *serial_status_label;
    QPushButton *reset_button;
    QPushButton *xbee_button;
    QComboBox *serialport_selector;
    QPushButton *change_theme;
    QLabel *serial_status_panel;
    QWidget *upper_widget;
    QGridLayout *gridLayout_5;
    QLabel *time_panel;
    QPushButton *manual_mode_button;
    QPushButton *request_rssi;
    QLabel *dbm_label;
    QLCDNumber *rssi_panel;
    QGroupBox *gps_box;
    QGridLayout *gridLayout_3;
    QLabel *longitude_label;
    QLabel *latitude_label;
    QLabel *altitude_label_gps;
    QLabel *sat_nbr_label;
    QLabel *hdop_label;
    QLabel *altitude_max_label;
    QLabel *longitude_panel;
    QLabel *ft_unit_label_2;
    QLCDNumber *altitude_max_lcd_m;
    QLCDNumber *altitude_lcd_gps_ft;
    QLCDNumber *altitude_lcd_gps;
    QLabel *m_unit_label_2;
    QLabel *m_unit_label;
    QLCDNumber *altitude_max_lcd_ft;
    QLabel *ft_unit_label;
    QLabel *latitude_panel;
    QLabel *hdop_panel;
    QLabel *sat_nbr_panel;
    QGroupBox *accel_box;
    QGridLayout *gridLayout_7;
    QLabel *accel_x_label;
    QLabel *accel_z_label;
    QLabel *accel_y_label;
    QLabel *accel_x_panel;
    QLabel *accel_y_panel;
    QLabel *accel_z_panel;
    QLabel *norm_label;
    QLabel *norm_panel;
    QLabel *logo;
    QGroupBox *euler_box;
    QGridLayout *gridLayout_6;
    QLabel *euler_x_panel;
    QLabel *euler_y_panel;
    QLabel *euler_x_label;
    QLabel *euler_y_label;
    QLabel *euler_z_label;
    QLabel *euler_z_panel;
    QGroupBox *com_box;
    QGridLayout *gridLayout_4;
    QLabel *packets_second_label;
    QLabel *received_pack_cnt_label;
    QLabel *corrupted_label;
    QProgressBar *pl_packets_second_bar;
    QLabel *received_pack_cnt_panel;
    QLabel *pl_packet_label;
    QLabel *time_since_last_panel;
    QLabel *corrupted_panel;
    QLabel *time_since_last_label;
    QLabel *last_datagram_id;
    QProgressBar *av_packets_second_bar;
    QProgressBar *packets_second_bar;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_12;
    QLabel *pl_altitude_label;
    QLabel *pl_altitude_panel;
    QLabel *pl_altitude_label_m;
    QLabel *pl_temperature_label;
    QLabel *pl_temperature_panel;
    QLabel *pl_celcius_label;
    QLabel *pl_pressure_panel;
    QLabel *pl_hpa_unit_label;
    QLabel *pl_percent_label;
    QLabel *pl_pressure_label;
    QLabel *pl_humid_label;
    QLabel *pl_humid_panel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(846, 666);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(0, 0));
        Form->setMaximumSize(QSize(9999, 9999));
        Form->setMouseTracking(false);
        Form->setStyleSheet(QLatin1String("background-color: rgb(30, 30, 30);\n"
                                          "color: rgb(255, 255, 255);"));
        gridLayout_10 = new QGridLayout(Form);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        av_states_box = new QGroupBox(Form);
        av_states_box->setObjectName(QStringLiteral("av_states_box"));
        gridLayout_11 = new QGridLayout(av_states_box);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        sleep_label = new QLabel(av_states_box);
        sleep_label->setObjectName(QStringLiteral("sleep_label"));

        gridLayout_11->addWidget(sleep_label, 1, 1, 1, 1);

        sleep_state_ok_panel = new QLabel(av_states_box);
        sleep_state_ok_panel->setObjectName(QStringLiteral("sleep_state_ok_panel"));
        sleep_state_ok_panel->setMinimumSize(QSize(23, 0));
        sleep_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        sleep_state_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        sleep_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(sleep_state_ok_panel, 1, 2, 1, 1);

        calibration_label = new QLabel(av_states_box);
        calibration_label->setObjectName(QStringLiteral("calibration_label"));
        calibration_label->setStyleSheet(QStringLiteral(""));

        gridLayout_11->addWidget(calibration_label, 2, 1, 1, 1);

        calibration_state_ok_panel = new QLabel(av_states_box);
        calibration_state_ok_panel->setObjectName(QStringLiteral("calibration_state_ok_panel"));
        calibration_state_ok_panel->setMinimumSize(QSize(23, 0));
        calibration_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        calibration_state_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        calibration_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(calibration_state_ok_panel, 2, 2, 1, 1);

        idle_label = new QLabel(av_states_box);
        idle_label->setObjectName(QStringLiteral("idle_label"));
        idle_label->setStyleSheet(QStringLiteral(""));

        gridLayout_11->addWidget(idle_label, 3, 1, 1, 1);

        idle_state_ok_panel = new QLabel(av_states_box);
        idle_state_ok_panel->setObjectName(QStringLiteral("idle_state_ok_panel"));
        idle_state_ok_panel->setMinimumSize(QSize(23, 0));
        idle_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        idle_state_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        idle_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(idle_state_ok_panel, 3, 2, 1, 1);

        filling_label_av = new QLabel(av_states_box);
        filling_label_av->setObjectName(QStringLiteral("filling_label_av"));

        gridLayout_11->addWidget(filling_label_av, 4, 1, 1, 1);

        filling_av_ok_panel = new QLabel(av_states_box);
        filling_av_ok_panel->setObjectName(QStringLiteral("filling_av_ok_panel"));
        filling_av_ok_panel->setMinimumSize(QSize(23, 0));
        filling_av_ok_panel->setMaximumSize(QSize(23, 16777215));
        filling_av_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        filling_av_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(filling_av_ok_panel, 4, 2, 1, 1);

        liftoff_label = new QLabel(av_states_box);
        liftoff_label->setObjectName(QStringLiteral("liftoff_label"));

        gridLayout_11->addWidget(liftoff_label, 5, 1, 1, 1);

        liftoff_state_ok_panel = new QLabel(av_states_box);
        liftoff_state_ok_panel->setObjectName(QStringLiteral("liftoff_state_ok_panel"));
        liftoff_state_ok_panel->setMinimumSize(QSize(23, 0));
        liftoff_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        liftoff_state_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        liftoff_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(liftoff_state_ok_panel, 5, 2, 1, 1);

        coast_label = new QLabel(av_states_box);
        coast_label->setObjectName(QStringLiteral("coast_label"));

        gridLayout_11->addWidget(coast_label, 6, 1, 1, 1);

        coast_state_ok_panel = new QLabel(av_states_box);
        coast_state_ok_panel->setObjectName(QStringLiteral("coast_state_ok_panel"));
        coast_state_ok_panel->setMinimumSize(QSize(23, 0));
        coast_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        coast_state_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        coast_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(coast_state_ok_panel, 6, 2, 1, 1);

        first_event_label = new QLabel(av_states_box);
        first_event_label->setObjectName(QStringLiteral("first_event_label"));

        gridLayout_11->addWidget(first_event_label, 7, 1, 1, 1);

        first_event_ok_panel = new QLabel(av_states_box);
        first_event_ok_panel->setObjectName(QStringLiteral("first_event_ok_panel"));
        first_event_ok_panel->setMinimumSize(QSize(23, 0));
        first_event_ok_panel->setMaximumSize(QSize(23, 16777215));
        first_event_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        first_event_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(first_event_ok_panel, 7, 2, 1, 1);

        second_event_label = new QLabel(av_states_box);
        second_event_label->setObjectName(QStringLiteral("second_event_label"));

        gridLayout_11->addWidget(second_event_label, 8, 1, 1, 1);

        second_event_ok_panel = new QLabel(av_states_box);
        second_event_ok_panel->setObjectName(QStringLiteral("second_event_ok_panel"));
        second_event_ok_panel->setMinimumSize(QSize(23, 0));
        second_event_ok_panel->setMaximumSize(QSize(23, 16777215));
        second_event_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        second_event_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(second_event_ok_panel, 8, 2, 1, 1);

        touchdown_label = new QLabel(av_states_box);
        touchdown_label->setObjectName(QStringLiteral("touchdown_label"));

        gridLayout_11->addWidget(touchdown_label, 9, 1, 1, 1);

        touchdown_event_ok_panel = new QLabel(av_states_box);
        touchdown_event_ok_panel->setObjectName(QStringLiteral("touchdown_event_ok_panel"));
        touchdown_event_ok_panel->setMinimumSize(QSize(23, 0));
        touchdown_event_ok_panel->setMaximumSize(QSize(23, 16777215));
        touchdown_event_ok_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        touchdown_event_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(touchdown_event_ok_panel, 9, 2, 1, 1);


        gridLayout_10->addWidget(av_states_box, 6, 2, 1, 1);

        avionics_box = new QGroupBox(Form);
        avionics_box->setObjectName(QStringLiteral("avionics_box"));
        gridLayout_8 = new QGridLayout(avionics_box);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        hpa_unit_label = new QLabel(avionics_box);
        hpa_unit_label->setObjectName(QStringLiteral("hpa_unit_label"));
        hpa_unit_label->setMaximumSize(QSize(30, 16777215));

        gridLayout_8->addWidget(hpa_unit_label, 3, 2, 1, 1);

        avionics_state_label = new QLabel(avionics_box);
        avionics_state_label->setObjectName(QStringLiteral("avionics_state_label"));

        gridLayout_8->addWidget(avionics_state_label, 6, 0, 1, 1);

        pressure_label = new QLabel(avionics_box);
        pressure_label->setObjectName(QStringLiteral("pressure_label"));

        gridLayout_8->addWidget(pressure_label, 3, 0, 1, 1);

        altitude_panel_telemetry = new QLabel(avionics_box);
        altitude_panel_telemetry->setObjectName(QStringLiteral("altitude_panel_telemetry"));

        gridLayout_8->addWidget(altitude_panel_telemetry, 5, 1, 1, 1);

        speed_label = new QLabel(avionics_box);
        speed_label->setObjectName(QStringLiteral("speed_label"));

        gridLayout_8->addWidget(speed_label, 4, 0, 1, 1);

        m_unit_label_3 = new QLabel(avionics_box);
        m_unit_label_3->setObjectName(QStringLiteral("m_unit_label_3"));
        m_unit_label_3->setMaximumSize(QSize(30, 16777215));

        gridLayout_8->addWidget(m_unit_label_3, 5, 2, 1, 1);

        altitude_label_telemetry = new QLabel(avionics_box);
        altitude_label_telemetry->setObjectName(QStringLiteral("altitude_label_telemetry"));

        gridLayout_8->addWidget(altitude_label_telemetry, 5, 0, 1, 1);

        speed_panel = new QLabel(avionics_box);
        speed_panel->setObjectName(QStringLiteral("speed_panel"));

        gridLayout_8->addWidget(speed_panel, 4, 1, 1, 1);

        avionics_state_panel = new QLabel(avionics_box);
        avionics_state_panel->setObjectName(QStringLiteral("avionics_state_panel"));
        avionics_state_panel->setMinimumSize(QSize(99, 28));
        avionics_state_panel->setMaximumSize(QSize(99, 28));
        avionics_state_panel->setFrameShape(QFrame::WinPanel);
        avionics_state_panel->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(avionics_state_panel, 6, 1, 1, 2);

        temperature_panel = new QLabel(avionics_box);
        temperature_panel->setObjectName(QStringLiteral("temperature_panel"));

        gridLayout_8->addWidget(temperature_panel, 0, 1, 1, 1);

        pressure_panel = new QLabel(avionics_box);
        pressure_panel->setObjectName(QStringLiteral("pressure_panel"));

        gridLayout_8->addWidget(pressure_panel, 3, 1, 1, 1);

        m_s_unit_label = new QLabel(avionics_box);
        m_s_unit_label->setObjectName(QStringLiteral("m_s_unit_label"));
        m_s_unit_label->setMaximumSize(QSize(30, 16777215));

        gridLayout_8->addWidget(m_s_unit_label, 4, 2, 1, 1);

        temperature_label = new QLabel(avionics_box);
        temperature_label->setObjectName(QStringLiteral("temperature_label"));

        gridLayout_8->addWidget(temperature_label, 0, 0, 1, 1);

        celcius_label = new QLabel(avionics_box);
        celcius_label->setObjectName(QStringLiteral("celcius_label"));
        celcius_label->setMinimumSize(QSize(0, 0));
        celcius_label->setMaximumSize(QSize(30, 16777215));

        gridLayout_8->addWidget(celcius_label, 0, 2, 1, 1);


        gridLayout_10->addWidget(avionics_box, 1, 0, 4, 1);

        ignition_box = new QGroupBox(Form);
        ignition_box->setObjectName(QStringLiteral("ignition_box"));
        ignition_box->setMinimumSize(QSize(200, 203));
        gridLayout_2 = new QGridLayout(ignition_box);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ignition_button = new QPushButton(ignition_box);
        ignition_button->setObjectName(QStringLiteral("ignition_button"));
        ignition_button->setMinimumSize(QSize(0, 20));
        ignition_button->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(ignition_button, 0, 0, 1, 1);

        ready_ignition_panel = new QLabel(ignition_box);
        ready_ignition_panel->setObjectName(QStringLiteral("ready_ignition_panel"));
        ready_ignition_panel->setMinimumSize(QSize(0, 0));
        ready_ignition_panel->setMaximumSize(QSize(23, 16777215));
        ready_ignition_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        ready_ignition_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(ready_ignition_panel, 0, 1, 1, 1);

        key_1_label = new QLabel(ignition_box);
        key_1_label->setObjectName(QStringLiteral("key_1_label"));

        gridLayout_2->addWidget(key_1_label, 1, 0, 1, 1);

        key_1_panel = new QLabel(ignition_box);
        key_1_panel->setObjectName(QStringLiteral("key_1_panel"));
        key_1_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        key_1_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(key_1_panel, 1, 1, 1, 1);

        key_2_label = new QLabel(ignition_box);
        key_2_label->setObjectName(QStringLiteral("key_2_label"));

        gridLayout_2->addWidget(key_2_label, 2, 0, 1, 1);

        key_2_panel = new QLabel(ignition_box);
        key_2_panel->setObjectName(QStringLiteral("key_2_panel"));
        key_2_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        key_2_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(key_2_panel, 2, 1, 1, 1);

        red_button_label = new QLabel(ignition_box);
        red_button_label->setObjectName(QStringLiteral("red_button_label"));

        gridLayout_2->addWidget(red_button_label, 3, 0, 1, 1);

        red_button_panel = new QLabel(ignition_box);
        red_button_panel->setObjectName(QStringLiteral("red_button_panel"));
        red_button_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        red_button_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(red_button_panel, 3, 1, 1, 1);

        ignition_status_label = new QLabel(ignition_box);
        ignition_status_label->setObjectName(QStringLiteral("ignition_status_label"));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        ignition_status_label->setFont(font);
        ignition_status_label->setAutoFillBackground(false);
        ignition_status_label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(ignition_status_label, 4, 0, 1, 1);

        ignition_frame = new QFrame(ignition_box);
        ignition_frame->setObjectName(QStringLiteral("ignition_frame"));
        ignition_frame->setMinimumSize(QSize(0, 30));
        ignition_frame->setMaximumSize(QSize(16777215, 1999999));
        ignition_frame->setStyleSheet(QLatin1String("border-color: rgb(255, 0, 0);\n"
                                                    "gridline-color: rgb(255, 0, 0);"));
        ignition_frame->setFrameShape(QFrame::WinPanel);
        ignition_frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(ignition_frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        code_3 = new QLabel(ignition_frame);
        code_3->setObjectName(QStringLiteral("code_3"));
        code_3->setMinimumSize(QSize(21, 21));
        code_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_3);

        code_2 = new QLabel(ignition_frame);
        code_2->setObjectName(QStringLiteral("code_2"));
        code_2->setMinimumSize(QSize(21, 21));
        code_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_2);

        code_1 = new QLabel(ignition_frame);
        code_1->setObjectName(QStringLiteral("code_1"));
        code_1->setMinimumSize(QSize(21, 21));
        code_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_1);

        code_0 = new QLabel(ignition_frame);
        code_0->setObjectName(QStringLiteral("code_0"));
        code_0->setMinimumSize(QSize(21, 21));
        code_0->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_0);


        gridLayout_2->addWidget(ignition_frame, 5, 0, 1, 2);


        gridLayout_10->addWidget(ignition_box, 0, 0, 1, 1);

        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_9 = new QGridLayout(widget);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serial_status_label = new QLabel(widget_2);
        serial_status_label->setObjectName(QStringLiteral("serial_status_label"));
        serial_status_label->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(serial_status_label, 0, 0, 1, 1);

        reset_button = new QPushButton(widget_2);
        reset_button->setObjectName(QStringLiteral("reset_button"));

        gridLayout->addWidget(reset_button, 3, 0, 1, 2);

        xbee_button = new QPushButton(widget_2);
        xbee_button->setObjectName(QStringLiteral("xbee_button"));
        xbee_button->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(xbee_button, 2, 0, 1, 2);

        serialport_selector = new QComboBox(widget_2);
        serialport_selector->setObjectName(QStringLiteral("serialport_selector"));

        gridLayout->addWidget(serialport_selector, 1, 0, 1, 2);

        change_theme = new QPushButton(widget_2);
        change_theme->setObjectName(QStringLiteral("change_theme"));

        gridLayout->addWidget(change_theme, 4, 0, 1, 2);

        serial_status_panel = new QLabel(widget_2);
        serial_status_panel->setObjectName(QStringLiteral("serial_status_panel"));
        serial_status_panel->setMinimumSize(QSize(23, 0));
        serial_status_panel->setMaximumSize(QSize(23, 16777215));
        serial_status_panel->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
                                                         "color: rgb(0, 255, 255);"));
        serial_status_panel->setFrameShape(QFrame::NoFrame);
        serial_status_panel->setLineWidth(1);
        serial_status_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(serial_status_panel, 0, 1, 1, 1);


        gridLayout_9->addWidget(widget_2, 1, 0, 1, 1);

        upper_widget = new QWidget(widget);
        upper_widget->setObjectName(QStringLiteral("upper_widget"));
        gridLayout_5 = new QGridLayout(upper_widget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        time_panel = new QLabel(upper_widget);
        time_panel->setObjectName(QStringLiteral("time_panel"));
        time_panel->setMinimumSize(QSize(0, 0));
        time_panel->setMaximumSize(QSize(999999, 16777215));
        time_panel->setStyleSheet(QStringLiteral(""));
        time_panel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(time_panel, 0, 1, 1, 2);

        manual_mode_button = new QPushButton(upper_widget);
        manual_mode_button->setObjectName(QStringLiteral("manual_mode_button"));

        gridLayout_5->addWidget(manual_mode_button, 0, 0, 1, 1);

        request_rssi = new QPushButton(upper_widget);
        request_rssi->setObjectName(QStringLiteral("request_rssi"));
        request_rssi->setStyleSheet(QLatin1String("QPushButton{\n"
                                                  "qproperty-icon: url(:/assets/rssi.png);\n"
                                                  "qproperty-iconSize: 25px;\n"
                                                  "font: 14pt \"MS Shell Dlg 2\";\n"
                                                  "border: 1px solid;\n"
                                                  "border-color: rgb(215, 237, 252);\n"
                                                  "border-radius: 10px;\n"
                                                  "}\n"
                                                  "QPushButton:hover {\n"
                                                  "background-color: rgb(35, 35, 35); \n"
                                                  "border: 2px solid;\n"
                                                  "border-color: rgb(215, 237, 252);\n"
                                                  "}\n"
                                                  "QPushButton:pressed {\n"
                                                  "border: 3px solid;\n"
                                                  "border-color: rgb(92, 242, 135);\n"
                                                  "}\n"
                                                  ""));

        gridLayout_5->addWidget(request_rssi, 2, 0, 1, 1);

        dbm_label = new QLabel(upper_widget);
        dbm_label->setObjectName(QStringLiteral("dbm_label"));
        dbm_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(dbm_label, 2, 2, 1, 1);

        rssi_panel = new QLCDNumber(upper_widget);
        rssi_panel->setObjectName(QStringLiteral("rssi_panel"));

        gridLayout_5->addWidget(rssi_panel, 2, 1, 1, 1);


        gridLayout_9->addWidget(upper_widget, 0, 0, 1, 1);


        gridLayout_10->addWidget(widget, 0, 3, 2, 1);

        gps_box = new QGroupBox(Form);
        gps_box->setObjectName(QStringLiteral("gps_box"));
        gps_box->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(gps_box);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        longitude_label = new QLabel(gps_box);
        longitude_label->setObjectName(QStringLiteral("longitude_label"));

        gridLayout_3->addWidget(longitude_label, 3, 0, 1, 1);

        latitude_label = new QLabel(gps_box);
        latitude_label->setObjectName(QStringLiteral("latitude_label"));

        gridLayout_3->addWidget(latitude_label, 5, 0, 1, 1);

        altitude_label_gps = new QLabel(gps_box);
        altitude_label_gps->setObjectName(QStringLiteral("altitude_label_gps"));

        gridLayout_3->addWidget(altitude_label_gps, 1, 0, 1, 1);

        sat_nbr_label = new QLabel(gps_box);
        sat_nbr_label->setObjectName(QStringLiteral("sat_nbr_label"));

        gridLayout_3->addWidget(sat_nbr_label, 7, 0, 1, 1);

        hdop_label = new QLabel(gps_box);
        hdop_label->setObjectName(QStringLiteral("hdop_label"));

        gridLayout_3->addWidget(hdop_label, 6, 0, 1, 1);

        altitude_max_label = new QLabel(gps_box);
        altitude_max_label->setObjectName(QStringLiteral("altitude_max_label"));

        gridLayout_3->addWidget(altitude_max_label, 2, 0, 1, 1);

        longitude_panel = new QLabel(gps_box);
        longitude_panel->setObjectName(QStringLiteral("longitude_panel"));

        gridLayout_3->addWidget(longitude_panel, 3, 1, 1, 4);

        ft_unit_label_2 = new QLabel(gps_box);
        ft_unit_label_2->setObjectName(QStringLiteral("ft_unit_label_2"));
        ft_unit_label_2->setMaximumSize(QSize(20, 16777215));

        gridLayout_3->addWidget(ft_unit_label_2, 1, 4, 1, 1);

        altitude_max_lcd_m = new QLCDNumber(gps_box);
        altitude_max_lcd_m->setObjectName(QStringLiteral("altitude_max_lcd_m"));
        altitude_max_lcd_m->setEnabled(true);
        altitude_max_lcd_m->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(altitude_max_lcd_m, 2, 1, 1, 1);

        altitude_lcd_gps_ft = new QLCDNumber(gps_box);
        altitude_lcd_gps_ft->setObjectName(QStringLiteral("altitude_lcd_gps_ft"));
        altitude_lcd_gps_ft->setFrameShadow(QFrame::Raised);
        altitude_lcd_gps_ft->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(altitude_lcd_gps_ft, 1, 3, 1, 1);

        altitude_lcd_gps = new QLCDNumber(gps_box);
        altitude_lcd_gps->setObjectName(QStringLiteral("altitude_lcd_gps"));
        altitude_lcd_gps->setSmallDecimalPoint(false);
        altitude_lcd_gps->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(altitude_lcd_gps, 1, 1, 1, 1);

        m_unit_label_2 = new QLabel(gps_box);
        m_unit_label_2->setObjectName(QStringLiteral("m_unit_label_2"));
        m_unit_label_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_3->addWidget(m_unit_label_2, 1, 2, 1, 1);

        m_unit_label = new QLabel(gps_box);
        m_unit_label->setObjectName(QStringLiteral("m_unit_label"));

        gridLayout_3->addWidget(m_unit_label, 2, 2, 1, 1);

        altitude_max_lcd_ft = new QLCDNumber(gps_box);
        altitude_max_lcd_ft->setObjectName(QStringLiteral("altitude_max_lcd_ft"));
        altitude_max_lcd_ft->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_3->addWidget(altitude_max_lcd_ft, 2, 3, 1, 1);

        ft_unit_label = new QLabel(gps_box);
        ft_unit_label->setObjectName(QStringLiteral("ft_unit_label"));

        gridLayout_3->addWidget(ft_unit_label, 2, 4, 1, 1);

        latitude_panel = new QLabel(gps_box);
        latitude_panel->setObjectName(QStringLiteral("latitude_panel"));
        latitude_panel->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(latitude_panel, 5, 1, 1, 4);

        hdop_panel = new QLabel(gps_box);
        hdop_panel->setObjectName(QStringLiteral("hdop_panel"));

        gridLayout_3->addWidget(hdop_panel, 6, 1, 1, 4);

        sat_nbr_panel = new QLabel(gps_box);
        sat_nbr_panel->setObjectName(QStringLiteral("sat_nbr_panel"));

        gridLayout_3->addWidget(sat_nbr_panel, 7, 1, 1, 4);


        gridLayout_10->addWidget(gps_box, 1, 1, 4, 2);

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
        accel_x_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_7->addWidget(accel_x_panel, 0, 1, 1, 1);

        accel_y_panel = new QLabel(accel_box);
        accel_y_panel->setObjectName(QStringLiteral("accel_y_panel"));
        accel_y_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_7->addWidget(accel_y_panel, 1, 1, 1, 1);

        accel_z_panel = new QLabel(accel_box);
        accel_z_panel->setObjectName(QStringLiteral("accel_z_panel"));
        accel_z_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_7->addWidget(accel_z_panel, 2, 1, 1, 1);

        norm_label = new QLabel(accel_box);
        norm_label->setObjectName(QStringLiteral("norm_label"));

        gridLayout_7->addWidget(norm_label, 3, 0, 1, 1);

        norm_panel = new QLabel(accel_box);
        norm_panel->setObjectName(QStringLiteral("norm_panel"));

        gridLayout_7->addWidget(norm_panel, 3, 1, 1, 1);


        gridLayout_10->addWidget(accel_box, 6, 0, 1, 1);

        logo = new QLabel(Form);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setStyleSheet(QLatin1String("\n"
                                          "\n"
                                          "image: url(:/assets/logo.png);"));

        gridLayout_10->addWidget(logo, 6, 3, 1, 1);

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


        gridLayout_10->addWidget(euler_box, 6, 1, 1, 1);

        com_box = new QGroupBox(Form);
        com_box->setObjectName(QStringLiteral("com_box"));
        gridLayout_4 = new QGridLayout(com_box);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        packets_second_label = new QLabel(com_box);
        packets_second_label->setObjectName(QStringLiteral("packets_second_label"));

        gridLayout_4->addWidget(packets_second_label, 1, 0, 1, 1);

        received_pack_cnt_label = new QLabel(com_box);
        received_pack_cnt_label->setObjectName(QStringLiteral("received_pack_cnt_label"));
        received_pack_cnt_label->setMinimumSize(QSize(155, 0));

        gridLayout_4->addWidget(received_pack_cnt_label, 0, 0, 1, 2);

        corrupted_label = new QLabel(com_box);
        corrupted_label->setObjectName(QStringLiteral("corrupted_label"));

        gridLayout_4->addWidget(corrupted_label, 7, 0, 1, 1);

        pl_packets_second_bar = new QProgressBar(com_box);
        pl_packets_second_bar->setObjectName(QStringLiteral("pl_packets_second_bar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pl_packets_second_bar->sizePolicy().hasHeightForWidth());
        pl_packets_second_bar->setSizePolicy(sizePolicy1);
        pl_packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                           "background:rgb(52, 101, 164);} "));
        pl_packets_second_bar->setMaximum(40);
        pl_packets_second_bar->setValue(30);
        pl_packets_second_bar->setAlignment(Qt::AlignCenter);
        pl_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(pl_packets_second_bar, 3, 1, 1, 2);

        received_pack_cnt_panel = new QLabel(com_box);
        received_pack_cnt_panel->setObjectName(QStringLiteral("received_pack_cnt_panel"));

        gridLayout_4->addWidget(received_pack_cnt_panel, 0, 2, 1, 1);

        pl_packet_label = new QLabel(com_box);
        pl_packet_label->setObjectName(QStringLiteral("pl_packet_label"));

        gridLayout_4->addWidget(pl_packet_label, 3, 0, 1, 1);

        time_since_last_panel = new QLabel(com_box);
        time_since_last_panel->setObjectName(QStringLiteral("time_since_last_panel"));

        gridLayout_4->addWidget(time_since_last_panel, 6, 1, 1, 2);

        corrupted_panel = new QLabel(com_box);
        corrupted_panel->setObjectName(QStringLiteral("corrupted_panel"));

        gridLayout_4->addWidget(corrupted_panel, 7, 1, 1, 2);

        time_since_last_label = new QLabel(com_box);
        time_since_last_label->setObjectName(QStringLiteral("time_since_last_label"));

        gridLayout_4->addWidget(time_since_last_label, 6, 0, 1, 1);

        last_datagram_id = new QLabel(com_box);
        last_datagram_id->setObjectName(QStringLiteral("last_datagram_id"));

        gridLayout_4->addWidget(last_datagram_id, 2, 0, 1, 1);

        av_packets_second_bar = new QProgressBar(com_box);
        av_packets_second_bar->setObjectName(QStringLiteral("av_packets_second_bar"));
        sizePolicy1.setHeightForWidth(av_packets_second_bar->sizePolicy().hasHeightForWidth());
        av_packets_second_bar->setSizePolicy(sizePolicy1);
        av_packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                           "background:rgb(52, 101, 164);} "));
        av_packets_second_bar->setMaximum(40);
        av_packets_second_bar->setValue(30);
        av_packets_second_bar->setAlignment(Qt::AlignCenter);
        av_packets_second_bar->setTextVisible(true);
        av_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(av_packets_second_bar, 2, 1, 1, 2);

        packets_second_bar = new QProgressBar(com_box);
        packets_second_bar->setObjectName(QStringLiteral("packets_second_bar"));
        sizePolicy1.setHeightForWidth(packets_second_bar->sizePolicy().hasHeightForWidth());
        packets_second_bar->setSizePolicy(sizePolicy1);
        packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                        "background:rgb(0, 160, 250);} "));
        packets_second_bar->setMaximum(40);
        packets_second_bar->setValue(30);
        packets_second_bar->setAlignment(Qt::AlignCenter);
        packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(packets_second_bar, 1, 1, 1, 2);


        gridLayout_10->addWidget(com_box, 0, 1, 1, 2);

        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_12 = new QGridLayout(groupBox);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        pl_altitude_label = new QLabel(groupBox);
        pl_altitude_label->setObjectName(QStringLiteral("pl_altitude_label"));

        gridLayout_12->addWidget(pl_altitude_label, 0, 0, 1, 2);

        pl_altitude_panel = new QLabel(groupBox);
        pl_altitude_panel->setObjectName(QStringLiteral("pl_altitude_panel"));

        gridLayout_12->addWidget(pl_altitude_panel, 0, 2, 1, 2);

        pl_altitude_label_m = new QLabel(groupBox);
        pl_altitude_label_m->setObjectName(QStringLiteral("pl_altitude_label_m"));

        gridLayout_12->addWidget(pl_altitude_label_m, 0, 4, 1, 1);

        pl_temperature_label = new QLabel(groupBox);
        pl_temperature_label->setObjectName(QStringLiteral("pl_temperature_label"));

        gridLayout_12->addWidget(pl_temperature_label, 1, 0, 2, 2);

        pl_temperature_panel = new QLabel(groupBox);
        pl_temperature_panel->setObjectName(QStringLiteral("pl_temperature_panel"));

        gridLayout_12->addWidget(pl_temperature_panel, 1, 2, 2, 2);

        pl_celcius_label = new QLabel(groupBox);
        pl_celcius_label->setObjectName(QStringLiteral("pl_celcius_label"));
        pl_celcius_label->setMinimumSize(QSize(0, 0));
        pl_celcius_label->setMaximumSize(QSize(30, 16777215));

        gridLayout_12->addWidget(pl_celcius_label, 1, 4, 2, 1);

        pl_pressure_panel = new QLabel(groupBox);
        pl_pressure_panel->setObjectName(QStringLiteral("pl_pressure_panel"));

        gridLayout_12->addWidget(pl_pressure_panel, 3, 2, 2, 2);

        pl_hpa_unit_label = new QLabel(groupBox);
        pl_hpa_unit_label->setObjectName(QStringLiteral("pl_hpa_unit_label"));
        pl_hpa_unit_label->setMaximumSize(QSize(30, 16777215));

        gridLayout_12->addWidget(pl_hpa_unit_label, 3, 4, 2, 1);

        pl_percent_label = new QLabel(groupBox);
        pl_percent_label->setObjectName(QStringLiteral("pl_percent_label"));
        pl_percent_label->setMaximumSize(QSize(30, 16777215));

        gridLayout_12->addWidget(pl_percent_label, 5, 4, 1, 1);

        pl_pressure_label = new QLabel(groupBox);
        pl_pressure_label->setObjectName(QStringLiteral("pl_pressure_label"));

        gridLayout_12->addWidget(pl_pressure_label, 3, 0, 1, 2);

        pl_humid_label = new QLabel(groupBox);
        pl_humid_label->setObjectName(QStringLiteral("pl_humid_label"));

        gridLayout_12->addWidget(pl_humid_label, 5, 0, 1, 2);

        pl_humid_panel = new QLabel(groupBox);
        pl_humid_panel->setObjectName(QStringLiteral("pl_humid_panel"));

        gridLayout_12->addWidget(pl_humid_panel, 5, 2, 1, 2);


        gridLayout_10->addWidget(groupBox, 2, 3, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "GSBellaLui2020", Q_NULLPTR));
        av_states_box->setTitle(QApplication::translate("Form", "AV States", Q_NULLPTR));
        sleep_label->setText(QApplication::translate("Form", "Sleep", Q_NULLPTR));
        sleep_state_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        calibration_label->setText(QApplication::translate("Form", "Calibration", Q_NULLPTR));
        calibration_state_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        idle_label->setText(QApplication::translate("Form", "IDLE", Q_NULLPTR));
        idle_state_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        filling_label_av->setText(QApplication::translate("Form", "Filling", Q_NULLPTR));
        filling_av_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        liftoff_label->setText(QApplication::translate("Form", "Lift off", Q_NULLPTR));
        liftoff_state_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        coast_label->setText(QApplication::translate("Form", "Coast", Q_NULLPTR));
        coast_state_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        first_event_label->setText(QApplication::translate("Form", "1st Event", Q_NULLPTR));
        first_event_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        second_event_label->setText(QApplication::translate("Form", "2nd Event", Q_NULLPTR));
        second_event_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        touchdown_label->setText(QApplication::translate("Form", "Touchdown", Q_NULLPTR));
        touchdown_event_ok_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        avionics_box->setTitle(QApplication::translate("Form", "Avionics Data", Q_NULLPTR));
        hpa_unit_label->setText(QApplication::translate("Form", "hPa", Q_NULLPTR));
        avionics_state_label->setText(QApplication::translate("Form", "AV. STATE", Q_NULLPTR));
        pressure_label->setText(QApplication::translate("Form", "PRESS.", Q_NULLPTR));
        altitude_panel_telemetry->setText(QString());
        speed_label->setText(QApplication::translate("Form", "SPEED", Q_NULLPTR));
        m_unit_label_3->setText(QApplication::translate("Form", "m", Q_NULLPTR));
        altitude_label_telemetry->setText(QApplication::translate("Form", "ALT.", Q_NULLPTR));
        speed_panel->setText(QString());
        avionics_state_panel->setText(QString());
        temperature_panel->setText(QString());
        pressure_panel->setText(QString());
        m_s_unit_label->setText(QApplication::translate("Form", "m/s", Q_NULLPTR));
        temperature_label->setText(QApplication::translate("Form", "TEMP", Q_NULLPTR));
        celcius_label->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" vertical-align:super;\">o</span>C</p></body></html>", Q_NULLPTR));
        ignition_box->setTitle(QApplication::translate("Form", "Ignition", Q_NULLPTR));
        ignition_button->setText(QApplication::translate("Form", "Ready For Ignition", Q_NULLPTR));
        ready_ignition_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        key_1_label->setText(QApplication::translate("Form", "KEY 1", Q_NULLPTR));
        key_1_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        key_2_label->setText(QApplication::translate("Form", "KEY 2", Q_NULLPTR));
        key_2_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        red_button_label->setText(QApplication::translate("Form", "Red Button", Q_NULLPTR));
        red_button_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        ignition_status_label->setText(QApplication::translate("Form", "Ignition", Q_NULLPTR));
        code_3->setText(QString());
        code_2->setText(QString());
        code_1->setText(QString());
        code_0->setText(QString());
        serial_status_label->setText(QApplication::translate("Form", "Serial port status", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        reset_button->setToolTip(QApplication::translate("Form", "Resets saved data", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        reset_button->setText(QApplication::translate("Form", "Reset", Q_NULLPTR));
        xbee_button->setText(QApplication::translate("Form", "START XBee", Q_NULLPTR));
        serialport_selector->clear();
        serialport_selector->insertItems(0, QStringList()
                                                << QApplication::translate("Form", "ttyUSB0", Q_NULLPTR)
                                                << QApplication::translate("Form", "ttyUSB1", Q_NULLPTR)
                                                << QApplication::translate("Form", "ttyS3", Q_NULLPTR)
                                                << QApplication::translate("Form", "ttyS6", Q_NULLPTR)
                                         );
        change_theme->setText(QApplication::translate("Form", "Change Color Theme", Q_NULLPTR));
        serial_status_panel->setText(QApplication::translate("Form", "...", Q_NULLPTR));
        time_panel->setText(QApplication::translate("Form", "44:44:44", Q_NULLPTR));
        manual_mode_button->setText(QApplication::translate("Form", "Manual Mode", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        request_rssi->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Get RSSI</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        request_rssi->setText(QApplication::translate("Form", "RSSI", Q_NULLPTR));
        dbm_label->setText(QApplication::translate("Form", "dBm", Q_NULLPTR));
        gps_box->setTitle(QApplication::translate("Form", "GPS", Q_NULLPTR));
        longitude_label->setText(QApplication::translate("Form", "LONGITUDE", Q_NULLPTR));
        latitude_label->setText(QApplication::translate("Form", "LATITUDE", Q_NULLPTR));
        altitude_label_gps->setText(QApplication::translate("Form", "ALTITUDE", Q_NULLPTR));
        sat_nbr_label->setText(QApplication::translate("Form", "SATELLITES", Q_NULLPTR));
        hdop_label->setText(QApplication::translate("Form", "HDOP", Q_NULLPTR));
        altitude_max_label->setText(QApplication::translate("Form", "ALTITUDE MAX", Q_NULLPTR));
        longitude_panel->setText(QString());
        ft_unit_label_2->setText(QApplication::translate("Form", "ft", Q_NULLPTR));
        m_unit_label_2->setText(QApplication::translate("Form", "m", Q_NULLPTR));
        m_unit_label->setText(QApplication::translate("Form", "m", Q_NULLPTR));
        ft_unit_label->setText(QApplication::translate("Form", "ft", Q_NULLPTR));
        latitude_panel->setText(QString());
        hdop_panel->setText(QString());
        sat_nbr_panel->setText(QString());
        accel_box->setTitle(QApplication::translate("Form", "Accelerometer", Q_NULLPTR));
        accel_x_label->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        accel_z_label->setText(QApplication::translate("Form", "Z", Q_NULLPTR));
        accel_y_label->setText(QApplication::translate("Form", "Y", Q_NULLPTR));
        accel_x_panel->setText(QString());
        accel_y_panel->setText(QString());
        accel_z_panel->setText(QString());
        norm_label->setText(QApplication::translate("Form", "Norm", Q_NULLPTR));
        norm_panel->setText(QString());
#ifndef QT_NO_TOOLTIP
        logo->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Project Bella Lui 2020</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        logo->setText(QString());
        euler_box->setTitle(QApplication::translate("Form", "Euler angles", Q_NULLPTR));
        euler_x_panel->setText(QString());
        euler_y_panel->setText(QString());
        euler_x_label->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        euler_y_label->setText(QApplication::translate("Form", "Y", Q_NULLPTR));
        euler_z_label->setText(QApplication::translate("Form", "Z", Q_NULLPTR));
        euler_z_panel->setText(QString());
        com_box->setTitle(QApplication::translate("Form", "COM", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        packets_second_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        packets_second_label->setText(QApplication::translate("Form", "TOTAL", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        received_pack_cnt_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        received_pack_cnt_label->setText(QApplication::translate("Form", "Total packets", Q_NULLPTR));
        corrupted_label->setText(QApplication::translate("Form", "Corrupted Packets", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pl_packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pl_packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        received_pack_cnt_panel->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        received_pack_cnt_panel->setText(QString());
#ifndef QT_NO_TOOLTIP
        pl_packet_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The last received packet's number (defined by TX)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pl_packet_label->setText(QApplication::translate("Form", "PL", Q_NULLPTR));
        time_since_last_panel->setText(QString());
        corrupted_panel->setText(QString());
        time_since_last_label->setText(QApplication::translate("Form", "Time since last packet", Q_NULLPTR));
        last_datagram_id->setText(QApplication::translate("Form", "AV", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        av_packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        av_packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Form", "Payload Data", Q_NULLPTR));
        pl_altitude_label->setText(QApplication::translate("Form", "Altitude", Q_NULLPTR));
        pl_altitude_panel->setText(QString());
        pl_altitude_label_m->setText(QApplication::translate("Form", "m", Q_NULLPTR));
        pl_temperature_label->setText(QApplication::translate("Form", "Temperature", Q_NULLPTR));
        pl_temperature_panel->setText(QString());
        pl_celcius_label->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" vertical-align:super;\">o</span>C</p></body></html>", Q_NULLPTR));
        pl_pressure_panel->setText(QString());
        pl_hpa_unit_label->setText(QApplication::translate("Form", "hPa", Q_NULLPTR));
        pl_percent_label->setText(QApplication::translate("Form", "%", Q_NULLPTR));
        pl_pressure_label->setText(QApplication::translate("Form", "Pressure", Q_NULLPTR));
        pl_humid_label->setText(QApplication::translate("Form", "Humidity", Q_NULLPTR));
        pl_humid_panel->setText(QString());
    } // retranslateUi

};

namespace Ui {
class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WASSERFALLENGUID10596_H
