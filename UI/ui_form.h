/********************************************************************************
** Form generated from reading UI file 'WasserfallenGUIE24228.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WASSERFALLENGUIE24228_H
#define WASSERFALLENGUIE24228_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout_11;
    QWidget *left_widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *com_box;
    QGridLayout *gridLayout_4;
    QLabel *packets_second_label;
    QProgressBar *packets_second_bar;
    QLabel *last_datagram_id;
    QProgressBar *av_packets_second_bar;
    QLabel *pl_packet_label;
    QProgressBar *pl_packets_second_bar;
    QLabel *gse_packet_label;
    QProgressBar *gse_packets_second_bar;
    QLabel *pp_packets_second_label;
    QProgressBar *pp_packets_second_bar;
    QLabel *received_pack_cnt_label;
    QLabel *received_pack_cnt_panel;
    QLabel *time_since_last_label;
    QLabel *time_since_last_panel;
    QLabel *corrupted_label;
    QLabel *corrupted_panel;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_22;
    QLabel *altitude_label_gps;
    QLCDNumber *altitude_lcd_gps;
    QLabel *ft_unit_label_2;
    QLabel *m_unit_label_2;
    QLCDNumber *altitude_lcd_gps_ft;
    QLabel *altitude_max_label;
    QLCDNumber *altitude_max_lcd_m;
    QLabel *m_unit_label;
    QLCDNumber *altitude_max_lcd_ft;
    QLabel *ft_unit_label;
    QGroupBox *gps_box;
    QGridLayout *gridLayout_3;
    QLabel *longitude_label;
    QLabel *hdop_label;
    QLabel *latitude_panel;
    QLabel *sat_nbr_label;
    QLabel *sat_nbr_panel;
    QLabel *latitude_label;
    QLabel *longitude_panel;
    QLabel *hdop_panel;
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
    QLabel *temperature_panel;
    QLabel *pressure_panel;
    QLabel *m_s_unit_label;
    QLabel *temperature_label;
    QLabel *celcius_label;
    QLabel *avionics_state_panel;
    QWidget *middle_widget;
    QGridLayout *gridLayout_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_10;
    QTabWidget *tabWidget_5;
    QWidget *tab_12;
    QGridLayout *gridLayout_7;
    QLabel *euler_z_label;
    QLabel *euler_y_label;
    QLabel *euler_x_label;
    QLabel *euler_x_panel;
    QLabel *euler_y_panel;
    QLabel *euler_z_panel;
    QWidget *tab_11;
    QGridLayout *gridLayout_24;
    QLabel *accel_x_panel;
    QLabel *accel_x_label;
    QLabel *accel_z_panel;
    QLabel *accel_z_label;
    QLabel *accel_y_label;
    QLabel *accel_y_panel;
    QLabel *norm_panel;
    QLabel *norm_label;
    QGroupBox *gse_state_box;
    QGridLayout *gridLayout_17;
    QLabel *purge_valve_state_panel;
    QLabel *fill_valve_state_panel;
    QLabel *purge_valve_label;
    QLabel *secondary_ignition_state_panel;
    QLabel *main_ignition_state_panel;
    QLabel *main_ignition_label;
    QLabel *hose_disconnect_state_panel;
    QLabel *secondary_ignition_label;
    QLabel *hose_disconnect_label;
    QLabel *fill_valve_label;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QGridLayout *gridLayout_19;
    QLabel *pl_bme_humidity_label;
    QLabel *pl_bme_temperature_label;
    QLabel *pl_bme_pressure_label;
    QLabel *pl_bme_temperature_panel;
    QLabel *pl_bme_altitude_label;
    QLabel *pl_bme_altitude_panel;
    QLabel *pl_bme_humidity_panel;
    QLabel *pl_bme_pressure_panel;
    QLabel *pl_celcius_label_2;
    QLabel *pl_hpa_label;
    QLabel *pl_percentage_label;
    QLabel *pl_m_label;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_31;
    QGridLayout *gridLayout_18;
    QLabel *pl_latitude_label;
    QLabel *pl_sat_nbr_panel;
    QLabel *pl_latitude_panel;
    QLabel *pl_satellites_label;
    QLabel *pl_longitude_label;
    QLabel *pl_longitude_panel;
    QLabel *pl_gps_altitude_label;
    QLabel *pl_gps_altitude_panel;
    QLabel *pl_hdop_label;
    QLabel *pl_hdop_panel;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_5;
    QGridLayout *gridLayout_20;
    QLabel *pl_bno_az_panel;
    QLabel *pl_bno_oy_label;
    QLabel *pl_bno_ox_panel;
    QLabel *pl_bno_ax_panel;
    QLabel *pl_bno_oz_label;
    QLabel *pl_bno_ax_label;
    QLabel *pl_bno_ay_label;
    QLabel *pl_bno_az_label;
    QLabel *pl_bno_ay_panel;
    QLabel *pl_bno_oy_panel;
    QLabel *pl_bno_temperature_label;
    QLabel *pl_bno_temperature_panel;
    QLabel *pl_bno_oz_panel;
    QLabel *deg_label_2;
    QLabel *deg_label_3;
    QLabel *deg_label;
    QLabel *pl_bno_ox_label;
    QLabel *ms2_label_2;
    QLabel *ms2_label_3;
    QLabel *label_7;
    QLabel *ms2_label;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_6;
    QGridLayout *gridLayout_21;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label;
    QLabel *label_9;
    QLabel *pp_pressure_1_panel;
    QLabel *pp_temperature_1_panel;
    QLabel *pp_pressure_2_panel;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_16;
    QLabel *pp_temperature_2_panel;
    QLabel *label_18;
    QLabel *pp_temperature_3_panel;
    QLabel *label_20;
    QLabel *pp_status_panel;
    QLabel *pp_motor_position_panel;
    QLabel *label_24;
    QWidget *tab_7;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *right_widget;
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_13;
    QLabel *logo;
    QWidget *tab_2;
    QGridLayout *gridLayout_14;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *serial_status_label;
    QPushButton *reset_button;
    QPushButton *xbee_button;
    QComboBox *serialport_selector;
    QPushButton *change_theme;
    QLabel *serial_status_panel;
    QTabWidget *tabWidget_4;
    QWidget *tab_8;
    QHBoxLayout *horizontalLayout_8;
    QWidget *ignition_box;
    QGridLayout *gridLayout_2;
    QPushButton *ignition_button;
    QLabel *ready_ignition_panel;
    QLabel *key_1_label;
    QLabel *key_1_panel;
    QLabel *key_2_label;
    QLabel *key_2_panel;
    QLabel *red_button_label;
    QLabel *red_button_panel;
    QFrame *ignition_frame;
    QHBoxLayout *horizontalLayout;
    QLabel *code_3;
    QLabel *code_2;
    QLabel *code_1;
    QLabel *code_0;
    QWidget *tab_10;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widget_21;
    QGridLayout *gridLayout_16;
    QLabel *tank_temp_label_2;
    QLabel *celcius_label2_2;
    QLabel *hose_pressure_label_2;
    QLabel *hose_pressure_panel_2;
    QLabel *hpa_panel_2;
    QLabel *hoes_temp_label_2;
    QLabel *hose_temp_panel_2;
    QLabel *celcius_label_3;
    QLabel *rocket_weight_label_2;
    QLabel *rocket_weight_panel_2;
    QLabel *kg_label_2;
    QLabel *battery_level_label;
    QLabel *battery_level_panel;
    QLabel *voltunit_label;
    QLabel *main_current_label;
    QLabel *main_current_panel;
    QLabel *m_a_unit_label;
    QLabel *label_8;
    QLabel *secondary_current_panel;
    QLabel *ma_unit_label;
    QLabel *label_11;
    QLabel *wind_speed_panel;
    QLabel *m_s_unit_label_2;
    QLabel *tank_temp_panel_2;
    QWidget *tab_9;
    QHBoxLayout *horizontalLayout_7;
    QWidget *gse_control_box;
    QGridLayout *gridLayout_15;
    QPushButton *filling_open_button;
    QPushButton *purge_open_button;
    QLabel *purge_label;
    QPushButton *purge_close_button;
    QLabel *filling_label;
    QPushButton *filling_close_button;
    QPushButton *disconnect_wire_button;
    QPushButton *echo_button;
    QWidget *upper_widget;
    QGridLayout *gridLayout_5;
    QLabel *time_panel;
    QPushButton *manual_mode_button;
    QPushButton *request_rssi;
    QLabel *dbm_label;
    QLCDNumber *rssi_panel;
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

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1038, 667);
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
        horizontalLayout_11 = new QHBoxLayout(Form);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        left_widget = new QWidget(Form);
        left_widget->setObjectName(QStringLiteral("left_widget"));
        verticalLayout = new QVBoxLayout(left_widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        com_box = new QGroupBox(left_widget);
        com_box->setObjectName(QStringLiteral("com_box"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(com_box->sizePolicy().hasHeightForWidth());
        com_box->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(com_box);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        packets_second_label = new QLabel(com_box);
        packets_second_label->setObjectName(QStringLiteral("packets_second_label"));

        gridLayout_4->addWidget(packets_second_label, 0, 0, 1, 1);

        packets_second_bar = new QProgressBar(com_box);
        packets_second_bar->setObjectName(QStringLiteral("packets_second_bar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(packets_second_bar->sizePolicy().hasHeightForWidth());
        packets_second_bar->setSizePolicy(sizePolicy2);
        packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                        "background:rgb(0, 160, 250);} "));
        packets_second_bar->setMaximum(40);
        packets_second_bar->setValue(30);
        packets_second_bar->setAlignment(Qt::AlignCenter);
        packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(packets_second_bar, 0, 1, 1, 1);

        last_datagram_id = new QLabel(com_box);
        last_datagram_id->setObjectName(QStringLiteral("last_datagram_id"));

        gridLayout_4->addWidget(last_datagram_id, 1, 0, 1, 1);

        av_packets_second_bar = new QProgressBar(com_box);
        av_packets_second_bar->setObjectName(QStringLiteral("av_packets_second_bar"));
        sizePolicy2.setHeightForWidth(av_packets_second_bar->sizePolicy().hasHeightForWidth());
        av_packets_second_bar->setSizePolicy(sizePolicy2);
        av_packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                           "background:rgb(52, 101, 164);} "));
        av_packets_second_bar->setMaximum(40);
        av_packets_second_bar->setValue(30);
        av_packets_second_bar->setAlignment(Qt::AlignCenter);
        av_packets_second_bar->setTextVisible(true);
        av_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(av_packets_second_bar, 1, 1, 1, 1);

        pl_packet_label = new QLabel(com_box);
        pl_packet_label->setObjectName(QStringLiteral("pl_packet_label"));

        gridLayout_4->addWidget(pl_packet_label, 2, 0, 1, 1);

        pl_packets_second_bar = new QProgressBar(com_box);
        pl_packets_second_bar->setObjectName(QStringLiteral("pl_packets_second_bar"));
        sizePolicy2.setHeightForWidth(pl_packets_second_bar->sizePolicy().hasHeightForWidth());
        pl_packets_second_bar->setSizePolicy(sizePolicy2);
        pl_packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                           "background:rgb(52, 101, 164);} "));
        pl_packets_second_bar->setMaximum(40);
        pl_packets_second_bar->setValue(30);
        pl_packets_second_bar->setAlignment(Qt::AlignCenter);
        pl_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(pl_packets_second_bar, 2, 1, 1, 1);

        gse_packet_label = new QLabel(com_box);
        gse_packet_label->setObjectName(QStringLiteral("gse_packet_label"));

        gridLayout_4->addWidget(gse_packet_label, 3, 0, 1, 1);

        gse_packets_second_bar = new QProgressBar(com_box);
        gse_packets_second_bar->setObjectName(QStringLiteral("gse_packets_second_bar"));
        sizePolicy2.setHeightForWidth(gse_packets_second_bar->sizePolicy().hasHeightForWidth());
        gse_packets_second_bar->setSizePolicy(sizePolicy2);
        gse_packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                            "background:rgb(52, 101, 164);} "));
        gse_packets_second_bar->setMaximum(40);
        gse_packets_second_bar->setValue(30);
        gse_packets_second_bar->setAlignment(Qt::AlignCenter);
        gse_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(gse_packets_second_bar, 3, 1, 1, 1);

        pp_packets_second_label = new QLabel(com_box);
        pp_packets_second_label->setObjectName(QStringLiteral("pp_packets_second_label"));

        gridLayout_4->addWidget(pp_packets_second_label, 4, 0, 1, 1);

        pp_packets_second_bar = new QProgressBar(com_box);
        pp_packets_second_bar->setObjectName(QStringLiteral("pp_packets_second_bar"));
        sizePolicy2.setHeightForWidth(pp_packets_second_bar->sizePolicy().hasHeightForWidth());
        pp_packets_second_bar->setSizePolicy(sizePolicy2);
        pp_packets_second_bar->setStyleSheet(QLatin1String("QProgressBar::chunk:horizontal { \n"
                                                           "background:rgb(52, 101, 164);} "));
        pp_packets_second_bar->setMaximum(40);
        pp_packets_second_bar->setValue(30);
        pp_packets_second_bar->setAlignment(Qt::AlignCenter);
        pp_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(pp_packets_second_bar, 4, 1, 1, 1);

        received_pack_cnt_label = new QLabel(com_box);
        received_pack_cnt_label->setObjectName(QStringLiteral("received_pack_cnt_label"));
        received_pack_cnt_label->setMinimumSize(QSize(155, 0));

        gridLayout_4->addWidget(received_pack_cnt_label, 5, 0, 1, 1);

        received_pack_cnt_panel = new QLabel(com_box);
        received_pack_cnt_panel->setObjectName(QStringLiteral("received_pack_cnt_panel"));

        gridLayout_4->addWidget(received_pack_cnt_panel, 5, 1, 1, 1);

        time_since_last_label = new QLabel(com_box);
        time_since_last_label->setObjectName(QStringLiteral("time_since_last_label"));

        gridLayout_4->addWidget(time_since_last_label, 6, 0, 1, 1);

        time_since_last_panel = new QLabel(com_box);
        time_since_last_panel->setObjectName(QStringLiteral("time_since_last_panel"));

        gridLayout_4->addWidget(time_since_last_panel, 6, 1, 1, 1);

        corrupted_label = new QLabel(com_box);
        corrupted_label->setObjectName(QStringLiteral("corrupted_label"));

        gridLayout_4->addWidget(corrupted_label, 7, 0, 1, 1);

        corrupted_panel = new QLabel(com_box);
        corrupted_panel->setObjectName(QStringLiteral("corrupted_panel"));

        gridLayout_4->addWidget(corrupted_panel, 7, 1, 1, 1);


        verticalLayout->addWidget(com_box);

        groupBox_7 = new QGroupBox(left_widget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_22 = new QGridLayout(groupBox_7);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        altitude_label_gps = new QLabel(groupBox_7);
        altitude_label_gps->setObjectName(QStringLiteral("altitude_label_gps"));

        gridLayout_22->addWidget(altitude_label_gps, 0, 0, 1, 1);

        altitude_lcd_gps = new QLCDNumber(groupBox_7);
        altitude_lcd_gps->setObjectName(QStringLiteral("altitude_lcd_gps"));
        altitude_lcd_gps->setSmallDecimalPoint(false);
        altitude_lcd_gps->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_lcd_gps, 0, 1, 1, 1);

        ft_unit_label_2 = new QLabel(groupBox_7);
        ft_unit_label_2->setObjectName(QStringLiteral("ft_unit_label_2"));
        ft_unit_label_2->setMaximumSize(QSize(20, 16777215));

        gridLayout_22->addWidget(ft_unit_label_2, 0, 4, 1, 1);

        m_unit_label_2 = new QLabel(groupBox_7);
        m_unit_label_2->setObjectName(QStringLiteral("m_unit_label_2"));
        m_unit_label_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_22->addWidget(m_unit_label_2, 0, 2, 1, 1);

        altitude_lcd_gps_ft = new QLCDNumber(groupBox_7);
        altitude_lcd_gps_ft->setObjectName(QStringLiteral("altitude_lcd_gps_ft"));
        altitude_lcd_gps_ft->setFrameShadow(QFrame::Raised);
        altitude_lcd_gps_ft->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_lcd_gps_ft, 0, 3, 1, 1);

        altitude_max_label = new QLabel(groupBox_7);
        altitude_max_label->setObjectName(QStringLiteral("altitude_max_label"));

        gridLayout_22->addWidget(altitude_max_label, 1, 0, 1, 1);

        altitude_max_lcd_m = new QLCDNumber(groupBox_7);
        altitude_max_lcd_m->setObjectName(QStringLiteral("altitude_max_lcd_m"));
        altitude_max_lcd_m->setEnabled(true);
        altitude_max_lcd_m->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_max_lcd_m, 1, 1, 1, 1);

        m_unit_label = new QLabel(groupBox_7);
        m_unit_label->setObjectName(QStringLiteral("m_unit_label"));

        gridLayout_22->addWidget(m_unit_label, 1, 2, 1, 1);

        altitude_max_lcd_ft = new QLCDNumber(groupBox_7);
        altitude_max_lcd_ft->setObjectName(QStringLiteral("altitude_max_lcd_ft"));
        altitude_max_lcd_ft->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_max_lcd_ft, 1, 3, 1, 1);

        ft_unit_label = new QLabel(groupBox_7);
        ft_unit_label->setObjectName(QStringLiteral("ft_unit_label"));

        gridLayout_22->addWidget(ft_unit_label, 1, 4, 1, 1);


        verticalLayout->addWidget(groupBox_7);

        gps_box = new QGroupBox(left_widget);
        gps_box->setObjectName(QStringLiteral("gps_box"));
        sizePolicy1.setHeightForWidth(gps_box->sizePolicy().hasHeightForWidth());
        gps_box->setSizePolicy(sizePolicy1);
        gps_box->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(gps_box);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        longitude_label = new QLabel(gps_box);
        longitude_label->setObjectName(QStringLiteral("longitude_label"));

        gridLayout_3->addWidget(longitude_label, 3, 0, 1, 1);

        hdop_label = new QLabel(gps_box);
        hdop_label->setObjectName(QStringLiteral("hdop_label"));

        gridLayout_3->addWidget(hdop_label, 6, 0, 1, 1);

        latitude_panel = new QLabel(gps_box);
        latitude_panel->setObjectName(QStringLiteral("latitude_panel"));
        latitude_panel->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(latitude_panel, 3, 6, 1, 1);

        sat_nbr_label = new QLabel(gps_box);
        sat_nbr_label->setObjectName(QStringLiteral("sat_nbr_label"));

        gridLayout_3->addWidget(sat_nbr_label, 6, 5, 1, 1);

        sat_nbr_panel = new QLabel(gps_box);
        sat_nbr_panel->setObjectName(QStringLiteral("sat_nbr_panel"));

        gridLayout_3->addWidget(sat_nbr_panel, 6, 6, 1, 1);

        latitude_label = new QLabel(gps_box);
        latitude_label->setObjectName(QStringLiteral("latitude_label"));

        gridLayout_3->addWidget(latitude_label, 3, 5, 1, 1);

        longitude_panel = new QLabel(gps_box);
        longitude_panel->setObjectName(QStringLiteral("longitude_panel"));

        gridLayout_3->addWidget(longitude_panel, 3, 1, 1, 1);

        hdop_panel = new QLabel(gps_box);
        hdop_panel->setObjectName(QStringLiteral("hdop_panel"));

        gridLayout_3->addWidget(hdop_panel, 6, 1, 1, 1);


        verticalLayout->addWidget(gps_box);

        avionics_box = new QGroupBox(left_widget);
        avionics_box->setObjectName(QStringLiteral("avionics_box"));
        sizePolicy1.setHeightForWidth(avionics_box->sizePolicy().hasHeightForWidth());
        avionics_box->setSizePolicy(sizePolicy1);
        gridLayout_8 = new QGridLayout(avionics_box);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        hpa_unit_label = new QLabel(avionics_box);
        hpa_unit_label->setObjectName(QStringLiteral("hpa_unit_label"));
        hpa_unit_label->setMinimumSize(QSize(40, 0));
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

        temperature_panel = new QLabel(avionics_box);
        temperature_panel->setObjectName(QStringLiteral("temperature_panel"));

        gridLayout_8->addWidget(temperature_panel, 0, 1, 1, 1);

        pressure_panel = new QLabel(avionics_box);
        pressure_panel->setObjectName(QStringLiteral("pressure_panel"));

        gridLayout_8->addWidget(pressure_panel, 3, 1, 1, 1);

        m_s_unit_label = new QLabel(avionics_box);
        m_s_unit_label->setObjectName(QStringLiteral("m_s_unit_label"));
        m_s_unit_label->setMinimumSize(QSize(45, 0));
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

        avionics_state_panel = new QLabel(avionics_box);
        avionics_state_panel->setObjectName(QStringLiteral("avionics_state_panel"));

        gridLayout_8->addWidget(avionics_state_panel, 6, 1, 1, 2);


        verticalLayout->addWidget(avionics_box);


        horizontalLayout_11->addWidget(left_widget);

        middle_widget = new QWidget(Form);
        middle_widget->setObjectName(QStringLiteral("middle_widget"));
        gridLayout_6 = new QGridLayout(middle_widget);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        widget_3 = new QWidget(middle_widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_10 = new QHBoxLayout(widget_3);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        tabWidget_5 = new QTabWidget(widget_3);
        tabWidget_5->setObjectName(QStringLiteral("tabWidget_5"));
        tabWidget_5->setMinimumSize(QSize(150, 0));
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        gridLayout_7 = new QGridLayout(tab_12);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        euler_z_label = new QLabel(tab_12);
        euler_z_label->setObjectName(QStringLiteral("euler_z_label"));
        euler_z_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(euler_z_label, 2, 0, 1, 1);

        euler_y_label = new QLabel(tab_12);
        euler_y_label->setObjectName(QStringLiteral("euler_y_label"));
        euler_y_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(euler_y_label, 1, 0, 1, 1);

        euler_x_label = new QLabel(tab_12);
        euler_x_label->setObjectName(QStringLiteral("euler_x_label"));
        euler_x_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(euler_x_label, 0, 0, 1, 1);

        euler_x_panel = new QLabel(tab_12);
        euler_x_panel->setObjectName(QStringLiteral("euler_x_panel"));

        gridLayout_7->addWidget(euler_x_panel, 0, 1, 1, 1);

        euler_y_panel = new QLabel(tab_12);
        euler_y_panel->setObjectName(QStringLiteral("euler_y_panel"));

        gridLayout_7->addWidget(euler_y_panel, 1, 1, 1, 1);

        euler_z_panel = new QLabel(tab_12);
        euler_z_panel->setObjectName(QStringLiteral("euler_z_panel"));

        gridLayout_7->addWidget(euler_z_panel, 2, 1, 1, 1);

        tabWidget_5->addTab(tab_12, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        gridLayout_24 = new QGridLayout(tab_11);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        accel_x_panel = new QLabel(tab_11);
        accel_x_panel->setObjectName(QStringLiteral("accel_x_panel"));
        accel_x_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_24->addWidget(accel_x_panel, 0, 2, 1, 1);

        accel_x_label = new QLabel(tab_11);
        accel_x_label->setObjectName(QStringLiteral("accel_x_label"));
        accel_x_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_24->addWidget(accel_x_label, 0, 1, 1, 1);

        accel_z_panel = new QLabel(tab_11);
        accel_z_panel->setObjectName(QStringLiteral("accel_z_panel"));
        accel_z_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_24->addWidget(accel_z_panel, 2, 2, 1, 1);

        accel_z_label = new QLabel(tab_11);
        accel_z_label->setObjectName(QStringLiteral("accel_z_label"));
        accel_z_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_24->addWidget(accel_z_label, 2, 1, 1, 1);

        accel_y_label = new QLabel(tab_11);
        accel_y_label->setObjectName(QStringLiteral("accel_y_label"));
        accel_y_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_24->addWidget(accel_y_label, 1, 1, 1, 1);

        accel_y_panel = new QLabel(tab_11);
        accel_y_panel->setObjectName(QStringLiteral("accel_y_panel"));
        accel_y_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_24->addWidget(accel_y_panel, 1, 2, 1, 1);

        norm_panel = new QLabel(tab_11);
        norm_panel->setObjectName(QStringLiteral("norm_panel"));

        gridLayout_24->addWidget(norm_panel, 3, 2, 1, 1);

        norm_label = new QLabel(tab_11);
        norm_label->setObjectName(QStringLiteral("norm_label"));

        gridLayout_24->addWidget(norm_label, 3, 1, 1, 1);

        tabWidget_5->addTab(tab_11, QString());

        horizontalLayout_10->addWidget(tabWidget_5);

        gse_state_box = new QGroupBox(widget_3);
        gse_state_box->setObjectName(QStringLiteral("gse_state_box"));
        sizePolicy1.setHeightForWidth(gse_state_box->sizePolicy().hasHeightForWidth());
        gse_state_box->setSizePolicy(sizePolicy1);
        gridLayout_17 = new QGridLayout(gse_state_box);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        purge_valve_state_panel = new QLabel(gse_state_box);
        purge_valve_state_panel->setObjectName(QStringLiteral("purge_valve_state_panel"));
        purge_valve_state_panel->setMinimumSize(QSize(23, 0));
        purge_valve_state_panel->setMaximumSize(QSize(23, 16777215));
        purge_valve_state_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        purge_valve_state_panel->setFrameShape(QFrame::NoFrame);
        purge_valve_state_panel->setLineWidth(1);
        purge_valve_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(purge_valve_state_panel, 0, 1, 1, 1);

        fill_valve_state_panel = new QLabel(gse_state_box);
        fill_valve_state_panel->setObjectName(QStringLiteral("fill_valve_state_panel"));
        fill_valve_state_panel->setMinimumSize(QSize(23, 0));
        fill_valve_state_panel->setMaximumSize(QSize(23, 16777215));
        fill_valve_state_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        fill_valve_state_panel->setFrameShape(QFrame::NoFrame);
        fill_valve_state_panel->setLineWidth(1);
        fill_valve_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(fill_valve_state_panel, 1, 1, 1, 1);

        purge_valve_label = new QLabel(gse_state_box);
        purge_valve_label->setObjectName(QStringLiteral("purge_valve_label"));

        gridLayout_17->addWidget(purge_valve_label, 0, 0, 1, 1);

        secondary_ignition_state_panel = new QLabel(gse_state_box);
        secondary_ignition_state_panel->setObjectName(QStringLiteral("secondary_ignition_state_panel"));
        secondary_ignition_state_panel->setMinimumSize(QSize(23, 0));
        secondary_ignition_state_panel->setMaximumSize(QSize(23, 16777215));
        secondary_ignition_state_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        secondary_ignition_state_panel->setFrameShape(QFrame::NoFrame);
        secondary_ignition_state_panel->setLineWidth(1);
        secondary_ignition_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(secondary_ignition_state_panel, 3, 1, 1, 1);

        main_ignition_state_panel = new QLabel(gse_state_box);
        main_ignition_state_panel->setObjectName(QStringLiteral("main_ignition_state_panel"));
        main_ignition_state_panel->setMinimumSize(QSize(23, 0));
        main_ignition_state_panel->setMaximumSize(QSize(23, 16777215));
        main_ignition_state_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        main_ignition_state_panel->setFrameShape(QFrame::NoFrame);
        main_ignition_state_panel->setLineWidth(1);
        main_ignition_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(main_ignition_state_panel, 2, 1, 1, 1);

        main_ignition_label = new QLabel(gse_state_box);
        main_ignition_label->setObjectName(QStringLiteral("main_ignition_label"));

        gridLayout_17->addWidget(main_ignition_label, 2, 0, 1, 1);

        hose_disconnect_state_panel = new QLabel(gse_state_box);
        hose_disconnect_state_panel->setObjectName(QStringLiteral("hose_disconnect_state_panel"));
        hose_disconnect_state_panel->setMinimumSize(QSize(23, 0));
        hose_disconnect_state_panel->setMaximumSize(QSize(23, 16777215));
        hose_disconnect_state_panel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        hose_disconnect_state_panel->setFrameShape(QFrame::NoFrame);
        hose_disconnect_state_panel->setLineWidth(1);
        hose_disconnect_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(hose_disconnect_state_panel, 4, 1, 1, 1);

        secondary_ignition_label = new QLabel(gse_state_box);
        secondary_ignition_label->setObjectName(QStringLiteral("secondary_ignition_label"));

        gridLayout_17->addWidget(secondary_ignition_label, 3, 0, 1, 1);

        hose_disconnect_label = new QLabel(gse_state_box);
        hose_disconnect_label->setObjectName(QStringLiteral("hose_disconnect_label"));

        gridLayout_17->addWidget(hose_disconnect_label, 4, 0, 1, 1);

        fill_valve_label = new QLabel(gse_state_box);
        fill_valve_label->setObjectName(QStringLiteral("fill_valve_label"));

        gridLayout_17->addWidget(fill_valve_label, 1, 0, 1, 1);


        horizontalLayout_10->addWidget(gse_state_box);


        gridLayout_6->addWidget(widget_3, 2, 0, 1, 1);

        tabWidget_2 = new QTabWidget(middle_widget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(250, 0));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget_4 = new QWidget(tab_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        gridLayout_19 = new QGridLayout(widget_4);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        pl_bme_humidity_label = new QLabel(widget_4);
        pl_bme_humidity_label->setObjectName(QStringLiteral("pl_bme_humidity_label"));

        gridLayout_19->addWidget(pl_bme_humidity_label, 2, 0, 1, 1);

        pl_bme_temperature_label = new QLabel(widget_4);
        pl_bme_temperature_label->setObjectName(QStringLiteral("pl_bme_temperature_label"));

        gridLayout_19->addWidget(pl_bme_temperature_label, 0, 0, 1, 1);

        pl_bme_pressure_label = new QLabel(widget_4);
        pl_bme_pressure_label->setObjectName(QStringLiteral("pl_bme_pressure_label"));

        gridLayout_19->addWidget(pl_bme_pressure_label, 1, 0, 1, 1);

        pl_bme_temperature_panel = new QLabel(widget_4);
        pl_bme_temperature_panel->setObjectName(QStringLiteral("pl_bme_temperature_panel"));

        gridLayout_19->addWidget(pl_bme_temperature_panel, 0, 1, 1, 1);

        pl_bme_altitude_label = new QLabel(widget_4);
        pl_bme_altitude_label->setObjectName(QStringLiteral("pl_bme_altitude_label"));

        gridLayout_19->addWidget(pl_bme_altitude_label, 3, 0, 1, 1);

        pl_bme_altitude_panel = new QLabel(widget_4);
        pl_bme_altitude_panel->setObjectName(QStringLiteral("pl_bme_altitude_panel"));

        gridLayout_19->addWidget(pl_bme_altitude_panel, 3, 1, 1, 1);

        pl_bme_humidity_panel = new QLabel(widget_4);
        pl_bme_humidity_panel->setObjectName(QStringLiteral("pl_bme_humidity_panel"));

        gridLayout_19->addWidget(pl_bme_humidity_panel, 2, 1, 1, 1);

        pl_bme_pressure_panel = new QLabel(widget_4);
        pl_bme_pressure_panel->setObjectName(QStringLiteral("pl_bme_pressure_panel"));

        gridLayout_19->addWidget(pl_bme_pressure_panel, 1, 1, 1, 1);

        pl_celcius_label_2 = new QLabel(widget_4);
        pl_celcius_label_2->setObjectName(QStringLiteral("pl_celcius_label_2"));

        gridLayout_19->addWidget(pl_celcius_label_2, 0, 2, 1, 1);

        pl_hpa_label = new QLabel(widget_4);
        pl_hpa_label->setObjectName(QStringLiteral("pl_hpa_label"));

        gridLayout_19->addWidget(pl_hpa_label, 1, 2, 1, 1);

        pl_percentage_label = new QLabel(widget_4);
        pl_percentage_label->setObjectName(QStringLiteral("pl_percentage_label"));

        gridLayout_19->addWidget(pl_percentage_label, 2, 2, 1, 1);

        pl_m_label = new QLabel(widget_4);
        pl_m_label->setObjectName(QStringLiteral("pl_m_label"));

        gridLayout_19->addWidget(pl_m_label, 3, 2, 1, 1);


        horizontalLayout_3->addWidget(widget_4);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        horizontalLayout_4 = new QHBoxLayout(tab_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_31 = new QWidget(tab_4);
        widget_31->setObjectName(QStringLiteral("widget_31"));
        sizePolicy1.setHeightForWidth(widget_31->sizePolicy().hasHeightForWidth());
        widget_31->setSizePolicy(sizePolicy1);
        gridLayout_18 = new QGridLayout(widget_31);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        pl_latitude_label = new QLabel(widget_31);
        pl_latitude_label->setObjectName(QStringLiteral("pl_latitude_label"));

        gridLayout_18->addWidget(pl_latitude_label, 3, 0, 1, 1);

        pl_sat_nbr_panel = new QLabel(widget_31);
        pl_sat_nbr_panel->setObjectName(QStringLiteral("pl_sat_nbr_panel"));

        gridLayout_18->addWidget(pl_sat_nbr_panel, 2, 2, 1, 1);

        pl_latitude_panel = new QLabel(widget_31);
        pl_latitude_panel->setObjectName(QStringLiteral("pl_latitude_panel"));

        gridLayout_18->addWidget(pl_latitude_panel, 3, 2, 1, 1);

        pl_satellites_label = new QLabel(widget_31);
        pl_satellites_label->setObjectName(QStringLiteral("pl_satellites_label"));

        gridLayout_18->addWidget(pl_satellites_label, 2, 0, 1, 1);

        pl_longitude_label = new QLabel(widget_31);
        pl_longitude_label->setObjectName(QStringLiteral("pl_longitude_label"));

        gridLayout_18->addWidget(pl_longitude_label, 4, 0, 1, 1);

        pl_longitude_panel = new QLabel(widget_31);
        pl_longitude_panel->setObjectName(QStringLiteral("pl_longitude_panel"));

        gridLayout_18->addWidget(pl_longitude_panel, 4, 2, 1, 1);

        pl_gps_altitude_label = new QLabel(widget_31);
        pl_gps_altitude_label->setObjectName(QStringLiteral("pl_gps_altitude_label"));

        gridLayout_18->addWidget(pl_gps_altitude_label, 5, 0, 1, 1);

        pl_gps_altitude_panel = new QLabel(widget_31);
        pl_gps_altitude_panel->setObjectName(QStringLiteral("pl_gps_altitude_panel"));

        gridLayout_18->addWidget(pl_gps_altitude_panel, 5, 2, 1, 1);

        pl_hdop_label = new QLabel(widget_31);
        pl_hdop_label->setObjectName(QStringLiteral("pl_hdop_label"));

        gridLayout_18->addWidget(pl_hdop_label, 6, 0, 1, 1);

        pl_hdop_panel = new QLabel(widget_31);
        pl_hdop_panel->setObjectName(QStringLiteral("pl_hdop_panel"));

        gridLayout_18->addWidget(pl_hdop_panel, 6, 2, 1, 1);


        horizontalLayout_4->addWidget(widget_31);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        horizontalLayout_5 = new QHBoxLayout(tab_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget_5 = new QWidget(tab_5);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        gridLayout_20 = new QGridLayout(widget_5);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        pl_bno_az_panel = new QLabel(widget_5);
        pl_bno_az_panel->setObjectName(QStringLiteral("pl_bno_az_panel"));

        gridLayout_20->addWidget(pl_bno_az_panel, 6, 1, 1, 1);

        pl_bno_oy_label = new QLabel(widget_5);
        pl_bno_oy_label->setObjectName(QStringLiteral("pl_bno_oy_label"));

        gridLayout_20->addWidget(pl_bno_oy_label, 2, 0, 1, 1);

        pl_bno_ox_panel = new QLabel(widget_5);
        pl_bno_ox_panel->setObjectName(QStringLiteral("pl_bno_ox_panel"));

        gridLayout_20->addWidget(pl_bno_ox_panel, 1, 1, 1, 1);

        pl_bno_ax_panel = new QLabel(widget_5);
        pl_bno_ax_panel->setObjectName(QStringLiteral("pl_bno_ax_panel"));

        gridLayout_20->addWidget(pl_bno_ax_panel, 4, 1, 1, 1);

        pl_bno_oz_label = new QLabel(widget_5);
        pl_bno_oz_label->setObjectName(QStringLiteral("pl_bno_oz_label"));

        gridLayout_20->addWidget(pl_bno_oz_label, 3, 0, 1, 1);

        pl_bno_ax_label = new QLabel(widget_5);
        pl_bno_ax_label->setObjectName(QStringLiteral("pl_bno_ax_label"));

        gridLayout_20->addWidget(pl_bno_ax_label, 4, 0, 1, 1);

        pl_bno_ay_label = new QLabel(widget_5);
        pl_bno_ay_label->setObjectName(QStringLiteral("pl_bno_ay_label"));

        gridLayout_20->addWidget(pl_bno_ay_label, 5, 0, 1, 1);

        pl_bno_az_label = new QLabel(widget_5);
        pl_bno_az_label->setObjectName(QStringLiteral("pl_bno_az_label"));

        gridLayout_20->addWidget(pl_bno_az_label, 6, 0, 1, 1);

        pl_bno_ay_panel = new QLabel(widget_5);
        pl_bno_ay_panel->setObjectName(QStringLiteral("pl_bno_ay_panel"));

        gridLayout_20->addWidget(pl_bno_ay_panel, 5, 1, 1, 1);

        pl_bno_oy_panel = new QLabel(widget_5);
        pl_bno_oy_panel->setObjectName(QStringLiteral("pl_bno_oy_panel"));

        gridLayout_20->addWidget(pl_bno_oy_panel, 2, 1, 1, 1);

        pl_bno_temperature_label = new QLabel(widget_5);
        pl_bno_temperature_label->setObjectName(QStringLiteral("pl_bno_temperature_label"));

        gridLayout_20->addWidget(pl_bno_temperature_label, 0, 0, 1, 1);

        pl_bno_temperature_panel = new QLabel(widget_5);
        pl_bno_temperature_panel->setObjectName(QStringLiteral("pl_bno_temperature_panel"));

        gridLayout_20->addWidget(pl_bno_temperature_panel, 0, 1, 1, 1);

        pl_bno_oz_panel = new QLabel(widget_5);
        pl_bno_oz_panel->setObjectName(QStringLiteral("pl_bno_oz_panel"));

        gridLayout_20->addWidget(pl_bno_oz_panel, 3, 1, 1, 1);

        deg_label_2 = new QLabel(widget_5);
        deg_label_2->setObjectName(QStringLiteral("deg_label_2"));

        gridLayout_20->addWidget(deg_label_2, 2, 2, 1, 1);

        deg_label_3 = new QLabel(widget_5);
        deg_label_3->setObjectName(QStringLiteral("deg_label_3"));

        gridLayout_20->addWidget(deg_label_3, 1, 2, 1, 1);

        deg_label = new QLabel(widget_5);
        deg_label->setObjectName(QStringLiteral("deg_label"));

        gridLayout_20->addWidget(deg_label, 3, 2, 1, 1);

        pl_bno_ox_label = new QLabel(widget_5);
        pl_bno_ox_label->setObjectName(QStringLiteral("pl_bno_ox_label"));

        gridLayout_20->addWidget(pl_bno_ox_label, 1, 0, 1, 1);

        ms2_label_2 = new QLabel(widget_5);
        ms2_label_2->setObjectName(QStringLiteral("ms2_label_2"));

        gridLayout_20->addWidget(ms2_label_2, 5, 2, 1, 1);

        ms2_label_3 = new QLabel(widget_5);
        ms2_label_3->setObjectName(QStringLiteral("ms2_label_3"));

        gridLayout_20->addWidget(ms2_label_3, 4, 2, 1, 1);

        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_20->addWidget(label_7, 0, 2, 1, 1);

        ms2_label = new QLabel(widget_5);
        ms2_label->setObjectName(QStringLiteral("ms2_label"));

        gridLayout_20->addWidget(ms2_label, 6, 2, 1, 1);


        horizontalLayout_5->addWidget(widget_5);

        tabWidget_2->addTab(tab_5, QString());

        gridLayout_6->addWidget(tabWidget_2, 0, 0, 1, 1);

        tabWidget_3 = new QTabWidget(middle_widget);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        horizontalLayout_6 = new QHBoxLayout(tab_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        widget_6 = new QWidget(tab_6);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        gridLayout_21 = new QGridLayout(widget_6);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        label_15 = new QLabel(widget_6);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_21->addWidget(label_15, 5, 0, 1, 1);

        label_13 = new QLabel(widget_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_21->addWidget(label_13, 3, 0, 1, 1);

        label = new QLabel(widget_6);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_21->addWidget(label, 1, 0, 1, 1);

        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_21->addWidget(label_9, 2, 0, 1, 1);

        pp_pressure_1_panel = new QLabel(widget_6);
        pp_pressure_1_panel->setObjectName(QStringLiteral("pp_pressure_1_panel"));

        gridLayout_21->addWidget(pp_pressure_1_panel, 0, 1, 1, 1);

        pp_temperature_1_panel = new QLabel(widget_6);
        pp_temperature_1_panel->setObjectName(QStringLiteral("pp_temperature_1_panel"));

        gridLayout_21->addWidget(pp_temperature_1_panel, 2, 1, 1, 1);

        pp_pressure_2_panel = new QLabel(widget_6);
        pp_pressure_2_panel->setObjectName(QStringLiteral("pp_pressure_2_panel"));

        gridLayout_21->addWidget(pp_pressure_2_panel, 1, 1, 1, 1);

        label_12 = new QLabel(widget_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_21->addWidget(label_12, 2, 2, 1, 1);

        label_14 = new QLabel(widget_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_21->addWidget(label_14, 4, 0, 1, 1);

        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_21->addWidget(label_6, 0, 2, 1, 1);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_21->addWidget(label_3, 1, 2, 1, 1);

        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_21->addWidget(label_5, 0, 0, 1, 1);

        label_16 = new QLabel(widget_6);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_21->addWidget(label_16, 6, 0, 1, 1);

        pp_temperature_2_panel = new QLabel(widget_6);
        pp_temperature_2_panel->setObjectName(QStringLiteral("pp_temperature_2_panel"));

        gridLayout_21->addWidget(pp_temperature_2_panel, 3, 1, 1, 1);

        label_18 = new QLabel(widget_6);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_21->addWidget(label_18, 3, 2, 1, 1);

        pp_temperature_3_panel = new QLabel(widget_6);
        pp_temperature_3_panel->setObjectName(QStringLiteral("pp_temperature_3_panel"));

        gridLayout_21->addWidget(pp_temperature_3_panel, 4, 1, 1, 1);

        label_20 = new QLabel(widget_6);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_21->addWidget(label_20, 4, 2, 1, 1);

        pp_status_panel = new QLabel(widget_6);
        pp_status_panel->setObjectName(QStringLiteral("pp_status_panel"));

        gridLayout_21->addWidget(pp_status_panel, 5, 1, 1, 1);

        pp_motor_position_panel = new QLabel(widget_6);
        pp_motor_position_panel->setObjectName(QStringLiteral("pp_motor_position_panel"));

        gridLayout_21->addWidget(pp_motor_position_panel, 6, 1, 1, 1);

        label_24 = new QLabel(widget_6);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_21->addWidget(label_24, 6, 2, 1, 1);


        horizontalLayout_6->addWidget(widget_6);

        tabWidget_3->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        horizontalLayout_2 = new QHBoxLayout(tab_7);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget = new QWidget(tab_7);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_12 = new QGridLayout(widget);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_12->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_12->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_12->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_12->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QStringLiteral("color: rgb(204, 0, 0);"));

        gridLayout_12->addWidget(pushButton_5, 2, 0, 1, 2);


        horizontalLayout_2->addWidget(widget);

        tabWidget_3->addTab(tab_7, QString());

        gridLayout_6->addWidget(tabWidget_3, 1, 0, 1, 1);


        horizontalLayout_11->addWidget(middle_widget);

        right_widget = new QWidget(Form);
        right_widget->setObjectName(QStringLiteral("right_widget"));
        gridLayout_9 = new QGridLayout(right_widget);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        tabWidget = new QTabWidget(right_widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMaximumSize(QSize(9999999, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_13 = new QGridLayout(tab);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        logo = new QLabel(tab);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setStyleSheet(QLatin1String("\n"
                                          "\n"
                                          "image: url(:/assets/logo.png);"));

        gridLayout_13->addWidget(logo, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_14 = new QGridLayout(tab_2);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serial_status_label = new QLabel(widget_2);
        serial_status_label->setObjectName(QStringLiteral("serial_status_label"));
        serial_status_label->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(serial_status_label, 0, 0, 1, 1);

        reset_button = new QPushButton(widget_2);
        reset_button->setObjectName(QStringLiteral("reset_button"));
        reset_button->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(reset_button, 3, 0, 1, 2);

        xbee_button = new QPushButton(widget_2);
        xbee_button->setObjectName(QStringLiteral("xbee_button"));
        xbee_button->setMinimumSize(QSize(0, 0));
        xbee_button->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(xbee_button, 2, 0, 1, 2);

        serialport_selector = new QComboBox(widget_2);
        serialport_selector->setObjectName(QStringLiteral("serialport_selector"));

        gridLayout->addWidget(serialport_selector, 1, 0, 1, 2);

        change_theme = new QPushButton(widget_2);
        change_theme->setObjectName(QStringLiteral("change_theme"));
        change_theme->setStyleSheet(QStringLiteral(""));

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


        gridLayout_14->addWidget(widget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_9->addWidget(tabWidget, 2, 2, 1, 1);

        tabWidget_4 = new QTabWidget(right_widget);
        tabWidget_4->setObjectName(QStringLiteral("tabWidget_4"));
        tabWidget_4->setMaximumSize(QSize(999999, 16777215));
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        horizontalLayout_8 = new QHBoxLayout(tab_8);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        ignition_box = new QWidget(tab_8);
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


        gridLayout_2->addWidget(ignition_frame, 4, 0, 1, 2);


        horizontalLayout_8->addWidget(ignition_box);

        tabWidget_4->addTab(tab_8, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        horizontalLayout_9 = new QHBoxLayout(tab_10);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        widget_21 = new QWidget(tab_10);
        widget_21->setObjectName(QStringLiteral("widget_21"));
        sizePolicy1.setHeightForWidth(widget_21->sizePolicy().hasHeightForWidth());
        widget_21->setSizePolicy(sizePolicy1);
        gridLayout_16 = new QGridLayout(widget_21);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        tank_temp_label_2 = new QLabel(widget_21);
        tank_temp_label_2->setObjectName(QStringLiteral("tank_temp_label_2"));

        gridLayout_16->addWidget(tank_temp_label_2, 0, 0, 1, 1);

        celcius_label2_2 = new QLabel(widget_21);
        celcius_label2_2->setObjectName(QStringLiteral("celcius_label2_2"));
        celcius_label2_2->setMaximumSize(QSize(40, 16777215));

        gridLayout_16->addWidget(celcius_label2_2, 0, 2, 1, 1);

        hose_pressure_label_2 = new QLabel(widget_21);
        hose_pressure_label_2->setObjectName(QStringLiteral("hose_pressure_label_2"));

        gridLayout_16->addWidget(hose_pressure_label_2, 1, 0, 1, 1);

        hose_pressure_panel_2 = new QLabel(widget_21);
        hose_pressure_panel_2->setObjectName(QStringLiteral("hose_pressure_panel_2"));
        hose_pressure_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(hose_pressure_panel_2, 1, 1, 1, 1);

        hpa_panel_2 = new QLabel(widget_21);
        hpa_panel_2->setObjectName(QStringLiteral("hpa_panel_2"));
        hpa_panel_2->setMaximumSize(QSize(40, 16777215));

        gridLayout_16->addWidget(hpa_panel_2, 1, 2, 1, 1);

        hoes_temp_label_2 = new QLabel(widget_21);
        hoes_temp_label_2->setObjectName(QStringLiteral("hoes_temp_label_2"));

        gridLayout_16->addWidget(hoes_temp_label_2, 2, 0, 1, 1);

        hose_temp_panel_2 = new QLabel(widget_21);
        hose_temp_panel_2->setObjectName(QStringLiteral("hose_temp_panel_2"));
        hose_temp_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(hose_temp_panel_2, 2, 1, 1, 1);

        celcius_label_3 = new QLabel(widget_21);
        celcius_label_3->setObjectName(QStringLiteral("celcius_label_3"));
        celcius_label_3->setMaximumSize(QSize(40, 16777215));

        gridLayout_16->addWidget(celcius_label_3, 2, 2, 1, 1);

        rocket_weight_label_2 = new QLabel(widget_21);
        rocket_weight_label_2->setObjectName(QStringLiteral("rocket_weight_label_2"));

        gridLayout_16->addWidget(rocket_weight_label_2, 3, 0, 1, 1);

        rocket_weight_panel_2 = new QLabel(widget_21);
        rocket_weight_panel_2->setObjectName(QStringLiteral("rocket_weight_panel_2"));
        rocket_weight_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(rocket_weight_panel_2, 3, 1, 1, 1);

        kg_label_2 = new QLabel(widget_21);
        kg_label_2->setObjectName(QStringLiteral("kg_label_2"));
        kg_label_2->setMaximumSize(QSize(40, 16777215));

        gridLayout_16->addWidget(kg_label_2, 3, 2, 1, 1);

        battery_level_label = new QLabel(widget_21);
        battery_level_label->setObjectName(QStringLiteral("battery_level_label"));

        gridLayout_16->addWidget(battery_level_label, 4, 0, 1, 1);

        battery_level_panel = new QLabel(widget_21);
        battery_level_panel->setObjectName(QStringLiteral("battery_level_panel"));
        battery_level_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(battery_level_panel, 4, 1, 1, 1);

        voltunit_label = new QLabel(widget_21);
        voltunit_label->setObjectName(QStringLiteral("voltunit_label"));

        gridLayout_16->addWidget(voltunit_label, 4, 2, 1, 1);

        main_current_label = new QLabel(widget_21);
        main_current_label->setObjectName(QStringLiteral("main_current_label"));

        gridLayout_16->addWidget(main_current_label, 5, 0, 1, 1);

        main_current_panel = new QLabel(widget_21);
        main_current_panel->setObjectName(QStringLiteral("main_current_panel"));
        main_current_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(main_current_panel, 5, 1, 1, 1);

        m_a_unit_label = new QLabel(widget_21);
        m_a_unit_label->setObjectName(QStringLiteral("m_a_unit_label"));

        gridLayout_16->addWidget(m_a_unit_label, 5, 2, 1, 1);

        label_8 = new QLabel(widget_21);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_16->addWidget(label_8, 6, 0, 1, 1);

        secondary_current_panel = new QLabel(widget_21);
        secondary_current_panel->setObjectName(QStringLiteral("secondary_current_panel"));
        secondary_current_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(secondary_current_panel, 6, 1, 1, 1);

        ma_unit_label = new QLabel(widget_21);
        ma_unit_label->setObjectName(QStringLiteral("ma_unit_label"));

        gridLayout_16->addWidget(ma_unit_label, 6, 2, 1, 1);

        label_11 = new QLabel(widget_21);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_16->addWidget(label_11, 7, 0, 1, 1);

        wind_speed_panel = new QLabel(widget_21);
        wind_speed_panel->setObjectName(QStringLiteral("wind_speed_panel"));
        wind_speed_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(wind_speed_panel, 7, 1, 1, 1);

        m_s_unit_label_2 = new QLabel(widget_21);
        m_s_unit_label_2->setObjectName(QStringLiteral("m_s_unit_label_2"));

        gridLayout_16->addWidget(m_s_unit_label_2, 7, 2, 1, 1);

        tank_temp_panel_2 = new QLabel(widget_21);
        tank_temp_panel_2->setObjectName(QStringLiteral("tank_temp_panel_2"));
        tank_temp_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(tank_temp_panel_2, 0, 1, 1, 1);


        horizontalLayout_9->addWidget(widget_21);

        tabWidget_4->addTab(tab_10, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        horizontalLayout_7 = new QHBoxLayout(tab_9);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        gse_control_box = new QWidget(tab_9);
        gse_control_box->setObjectName(QStringLiteral("gse_control_box"));
        gridLayout_15 = new QGridLayout(gse_control_box);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        filling_open_button = new QPushButton(gse_control_box);
        filling_open_button->setObjectName(QStringLiteral("filling_open_button"));
        filling_open_button->setStyleSheet(QStringLiteral(""));

        gridLayout_15->addWidget(filling_open_button, 0, 1, 1, 1);

        purge_open_button = new QPushButton(gse_control_box);
        purge_open_button->setObjectName(QStringLiteral("purge_open_button"));

        gridLayout_15->addWidget(purge_open_button, 1, 1, 1, 1);

        purge_label = new QLabel(gse_control_box);
        purge_label->setObjectName(QStringLiteral("purge_label"));

        gridLayout_15->addWidget(purge_label, 1, 0, 1, 1);

        purge_close_button = new QPushButton(gse_control_box);
        purge_close_button->setObjectName(QStringLiteral("purge_close_button"));

        gridLayout_15->addWidget(purge_close_button, 1, 2, 1, 1);

        filling_label = new QLabel(gse_control_box);
        filling_label->setObjectName(QStringLiteral("filling_label"));
        filling_label->setStyleSheet(QStringLiteral(""));

        gridLayout_15->addWidget(filling_label, 0, 0, 1, 1);

        filling_close_button = new QPushButton(gse_control_box);
        filling_close_button->setObjectName(QStringLiteral("filling_close_button"));

        gridLayout_15->addWidget(filling_close_button, 0, 2, 1, 1);

        disconnect_wire_button = new QPushButton(gse_control_box);
        disconnect_wire_button->setObjectName(QStringLiteral("disconnect_wire_button"));

        gridLayout_15->addWidget(disconnect_wire_button, 2, 1, 1, 2);

        echo_button = new QPushButton(gse_control_box);
        echo_button->setObjectName(QStringLiteral("echo_button"));

        gridLayout_15->addWidget(echo_button, 2, 0, 1, 1);


        horizontalLayout_7->addWidget(gse_control_box);

        tabWidget_4->addTab(tab_9, QString());

        gridLayout_9->addWidget(tabWidget_4, 1, 0, 1, 3);

        upper_widget = new QWidget(right_widget);
        upper_widget->setObjectName(QStringLiteral("upper_widget"));
        upper_widget->setMaximumSize(QSize(16777215, 16777215));
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
        manual_mode_button->setStyleSheet(QStringLiteral(""));

        gridLayout_5->addWidget(manual_mode_button, 0, 0, 1, 1);

        request_rssi = new QPushButton(upper_widget);
        request_rssi->setObjectName(QStringLiteral("request_rssi"));
        request_rssi->setStyleSheet(QStringLiteral(""));

        gridLayout_5->addWidget(request_rssi, 2, 0, 1, 1);

        dbm_label = new QLabel(upper_widget);
        dbm_label->setObjectName(QStringLiteral("dbm_label"));
        dbm_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(dbm_label, 2, 2, 1, 1);

        rssi_panel = new QLCDNumber(upper_widget);
        rssi_panel->setObjectName(QStringLiteral("rssi_panel"));

        gridLayout_5->addWidget(rssi_panel, 2, 1, 1, 1);


        gridLayout_9->addWidget(upper_widget, 0, 0, 1, 3);

        av_states_box = new QGroupBox(right_widget);
        av_states_box->setObjectName(QStringLiteral("av_states_box"));
        sizePolicy1.setHeightForWidth(av_states_box->sizePolicy().hasHeightForWidth());
        av_states_box->setSizePolicy(sizePolicy1);
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


        gridLayout_9->addWidget(av_states_box, 2, 1, 1, 1);


        horizontalLayout_11->addWidget(right_widget);


        retranslateUi(Form);

        tabWidget_5->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(2);
        tabWidget_3->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);
        tabWidget_4->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "GSBellaLui2020", Q_NULLPTR));
        com_box->setTitle(QApplication::translate("Form", "COM", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        packets_second_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        packets_second_label->setText(QApplication::translate("Form", "Total Rx Packet rate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
        last_datagram_id->setText(QApplication::translate("Form", "AV Rx Packet rate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        av_packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        av_packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pl_packet_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The last received packet's number (defined by TX)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pl_packet_label->setText(QApplication::translate("Form", "PL Rx Packet rate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pl_packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pl_packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
        gse_packet_label->setText(QApplication::translate("Form", "GSE Rx Packet rate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gse_packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        gse_packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
        pp_packets_second_label->setText(QApplication::translate("Form", "PP Rx Packet rate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pp_packets_second_bar->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pp_packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        received_pack_cnt_label->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        received_pack_cnt_label->setText(QApplication::translate("Form", "Total packets", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        received_pack_cnt_panel->setToolTip(QApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        received_pack_cnt_panel->setText(QString());
        time_since_last_label->setText(QApplication::translate("Form", "Time since last packet", Q_NULLPTR));
        time_since_last_panel->setText(QString());
        corrupted_label->setText(QApplication::translate("Form", "Corrupted Packets", Q_NULLPTR));
        corrupted_panel->setText(QString());
        groupBox_7->setTitle(QApplication::translate("Form", "Altitude", Q_NULLPTR));
        altitude_label_gps->setText(QApplication::translate("Form", "ALTITUDE", Q_NULLPTR));
        ft_unit_label_2->setText(QApplication::translate("Form", "ft", Q_NULLPTR));
        m_unit_label_2->setText(QApplication::translate("Form", "m", Q_NULLPTR));
        altitude_max_label->setText(QApplication::translate("Form", "ALTITUDE MAX", Q_NULLPTR));
        m_unit_label->setText(QApplication::translate("Form", "m", Q_NULLPTR));
        ft_unit_label->setText(QApplication::translate("Form", "ft", Q_NULLPTR));
        gps_box->setTitle(QApplication::translate("Form", "GPS", Q_NULLPTR));
        longitude_label->setText(QApplication::translate("Form", "LONG.", Q_NULLPTR));
        hdop_label->setText(QApplication::translate("Form", "HDOP", Q_NULLPTR));
        latitude_panel->setText(QString());
        sat_nbr_label->setText(QApplication::translate("Form", "SAT.NO", Q_NULLPTR));
        sat_nbr_panel->setText(QString());
        latitude_label->setText(QApplication::translate("Form", "LAT.", Q_NULLPTR));
        longitude_panel->setText(QString());
        hdop_panel->setText(QString());
        avionics_box->setTitle(QApplication::translate("Form", "Avionics Data", Q_NULLPTR));
        hpa_unit_label->setText(QApplication::translate("Form", "[hPa]", Q_NULLPTR));
        avionics_state_label->setText(QApplication::translate("Form", "AV. STATE", Q_NULLPTR));
        pressure_label->setText(QApplication::translate("Form", "PRESS.", Q_NULLPTR));
        altitude_panel_telemetry->setText(QString());
        speed_label->setText(QApplication::translate("Form", "SPEED", Q_NULLPTR));
        m_unit_label_3->setText(QApplication::translate("Form", "[m]", Q_NULLPTR));
        altitude_label_telemetry->setText(QApplication::translate("Form", "ALT.", Q_NULLPTR));
        speed_panel->setText(QString());
        temperature_panel->setText(QString());
        pressure_panel->setText(QString());
        m_s_unit_label->setText(QApplication::translate("Form", "[m/s]", Q_NULLPTR));
        temperature_label->setText(QApplication::translate("Form", "TEMP", Q_NULLPTR));
        celcius_label->setText(QApplication::translate("Form", "<html><head/><body><p>[<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", Q_NULLPTR));
        avionics_state_panel->setText(QString());
        euler_z_label->setText(QApplication::translate("Form", "Z", Q_NULLPTR));
        euler_y_label->setText(QApplication::translate("Form", "Y", Q_NULLPTR));
        euler_x_label->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        euler_x_panel->setText(QString());
        euler_y_panel->setText(QString());
        euler_z_panel->setText(QString());
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_12), QApplication::translate("Form", "Angles", Q_NULLPTR));
        accel_x_panel->setText(QString());
        accel_x_label->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        accel_z_panel->setText(QString());
        accel_z_label->setText(QApplication::translate("Form", "Z", Q_NULLPTR));
        accel_y_label->setText(QApplication::translate("Form", "Y", Q_NULLPTR));
        accel_y_panel->setText(QString());
        norm_panel->setText(QString());
        norm_label->setText(QApplication::translate("Form", "Norm", Q_NULLPTR));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_11), QApplication::translate("Form", "Accel.", Q_NULLPTR));
        gse_state_box->setTitle(QApplication::translate("Form", "GSE States", Q_NULLPTR));
        purge_valve_state_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        fill_valve_state_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        purge_valve_label->setText(QApplication::translate("Form", "Purge Valve", Q_NULLPTR));
        secondary_ignition_state_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        main_ignition_state_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        main_ignition_label->setText(QApplication::translate("Form", "Main Ignition", Q_NULLPTR));
        hose_disconnect_state_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        secondary_ignition_label->setText(QApplication::translate("Form", "Secondary Ignition", Q_NULLPTR));
        hose_disconnect_label->setText(QApplication::translate("Form", "Hose disconnect", Q_NULLPTR));
        fill_valve_label->setText(QApplication::translate("Form", "Fill Valve", Q_NULLPTR));
        pl_bme_humidity_label->setText(QApplication::translate("Form", "Humidity", Q_NULLPTR));
        pl_bme_temperature_label->setText(QApplication::translate("Form", "Temperature", Q_NULLPTR));
        pl_bme_pressure_label->setText(QApplication::translate("Form", "Pressure", Q_NULLPTR));
        pl_bme_temperature_panel->setText(QString());
        pl_bme_altitude_label->setText(QApplication::translate("Form", "Altitude", Q_NULLPTR));
        pl_bme_altitude_panel->setText(QString());
        pl_bme_humidity_panel->setText(QString());
        pl_bme_pressure_panel->setText(QString());
        pl_celcius_label_2->setText(QApplication::translate("Form", "<html><head/><body><p>[\302\260C]</p></body></html>", Q_NULLPTR));
        pl_hpa_label->setText(QApplication::translate("Form", "[hPa]", Q_NULLPTR));
        pl_percentage_label->setText(QApplication::translate("Form", "%", Q_NULLPTR));
        pl_m_label->setText(QApplication::translate("Form", "[m]", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("Form", "PL BME", Q_NULLPTR));
        pl_latitude_label->setText(QApplication::translate("Form", "Latitude", Q_NULLPTR));
        pl_sat_nbr_panel->setText(QString());
        pl_latitude_panel->setText(QString());
        pl_satellites_label->setText(QApplication::translate("Form", "Satellites", Q_NULLPTR));
        pl_longitude_label->setText(QApplication::translate("Form", "Longitude", Q_NULLPTR));
        pl_longitude_panel->setText(QString());
        pl_gps_altitude_label->setText(QApplication::translate("Form", "Altitude", Q_NULLPTR));
        pl_gps_altitude_panel->setText(QString());
        pl_hdop_label->setText(QApplication::translate("Form", "HDOP", Q_NULLPTR));
        pl_hdop_panel->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("Form", "PL GPS", Q_NULLPTR));
        pl_bno_az_panel->setText(QString());
        pl_bno_oy_label->setText(QApplication::translate("Form", "Oy", Q_NULLPTR));
        pl_bno_ox_panel->setText(QString());
        pl_bno_ax_panel->setText(QString());
        pl_bno_oz_label->setText(QApplication::translate("Form", "Oz", Q_NULLPTR));
        pl_bno_ax_label->setText(QApplication::translate("Form", "Ax", Q_NULLPTR));
        pl_bno_ay_label->setText(QApplication::translate("Form", "Ay", Q_NULLPTR));
        pl_bno_az_label->setText(QApplication::translate("Form", "Az", Q_NULLPTR));
        pl_bno_ay_panel->setText(QString());
        pl_bno_oy_panel->setText(QString());
        pl_bno_temperature_label->setText(QApplication::translate("Form", "Temp.", Q_NULLPTR));
        pl_bno_temperature_panel->setText(QString());
        pl_bno_oz_panel->setText(QString());
        deg_label_2->setText(QApplication::translate("Form", "[deg]", Q_NULLPTR));
        deg_label_3->setText(QApplication::translate("Form", "[deg]", Q_NULLPTR));
        deg_label->setText(QApplication::translate("Form", "[deg]", Q_NULLPTR));
        pl_bno_ox_label->setText(QApplication::translate("Form", "Ox", Q_NULLPTR));
        ms2_label_2->setText(QApplication::translate("Form", "<html><head/><body><p>[m/s<span style=\" vertical-align:super;\">2</span>]</p></body></html>", Q_NULLPTR));
        ms2_label_3->setText(QApplication::translate("Form", "<html><head/><body><p>[m/s<span style=\" vertical-align:super;\">2</span>]</p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" vertical-align:super;\">O</span>C</p></body></html>", Q_NULLPTR));
        ms2_label->setText(QApplication::translate("Form", "<html><head/><body><p>[m/s<span style=\" vertical-align:super;\">2</span>]</p></body></html>", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("Form", "PL BNO", Q_NULLPTR));
        label_15->setText(QApplication::translate("Form", "Status", Q_NULLPTR));
        label_13->setText(QApplication::translate("Form", "Temp 2", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "Pressure 2", Q_NULLPTR));
        label_9->setText(QApplication::translate("Form", "Temp 1", Q_NULLPTR));
        pp_pressure_1_panel->setText(QString());
        pp_temperature_1_panel->setText(QString());
        pp_pressure_2_panel->setText(QString());
        label_12->setText(QApplication::translate("Form", "<html><head/><body><p>[m<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("Form", "Temp 3", Q_NULLPTR));
        label_6->setText(QApplication::translate("Form", "[mBar]", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "[mBar]", Q_NULLPTR));
        label_5->setText(QApplication::translate("Form", "Pressure 1", Q_NULLPTR));
        label_16->setText(QApplication::translate("Form", "Motor pos", Q_NULLPTR));
        pp_temperature_2_panel->setText(QString());
        label_18->setText(QApplication::translate("Form", "<html><head/><body><p>[m<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", Q_NULLPTR));
        pp_temperature_3_panel->setText(QString());
        label_20->setText(QApplication::translate("Form", "<html><head/><body><p>[m<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", Q_NULLPTR));
        pp_status_panel->setText(QString());
        pp_motor_position_panel->setText(QApplication::translate("Form", "002", Q_NULLPTR));
        label_24->setText(QApplication::translate("Form", "[deg]", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("Form", "PP Data", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "Start Fueling", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Form", "Start Homing", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Form", "Start Valve OP", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Form", "Stop Fueling", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Form", "ABORT", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("Form", "PP Control", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        logo->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Project Bella Lui 2020</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        logo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form", "Logo", Q_NULLPTR));
        serial_status_label->setText(QApplication::translate("Form", "XBee status", Q_NULLPTR));
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
        change_theme->setText(QApplication::translate("Form", "Color Theme", Q_NULLPTR));
        serial_status_panel->setText(QApplication::translate("Form", "...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Form", "Config", Q_NULLPTR));
        ignition_button->setText(QApplication::translate("Form", "Ready For Ignition", Q_NULLPTR));
        ready_ignition_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        key_1_label->setText(QApplication::translate("Form", "KEY 1", Q_NULLPTR));
        key_1_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        key_2_label->setText(QApplication::translate("Form", "KEY 2", Q_NULLPTR));
        key_2_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        red_button_label->setText(QApplication::translate("Form", "Red Button", Q_NULLPTR));
        red_button_panel->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        code_3->setText(QString());
        code_2->setText(QString());
        code_1->setText(QString());
        code_0->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_8), QApplication::translate("Form", "Ignition", Q_NULLPTR));
        tank_temp_label_2->setText(QApplication::translate("Form", "Tank Temp", Q_NULLPTR));
        celcius_label2_2->setText(QApplication::translate("Form", "[\302\260C]", Q_NULLPTR));
        hose_pressure_label_2->setText(QApplication::translate("Form", "Hose Pressure", Q_NULLPTR));
        hose_pressure_panel_2->setText(QString());
        hpa_panel_2->setText(QApplication::translate("Form", "[mbar]", Q_NULLPTR));
        hoes_temp_label_2->setText(QApplication::translate("Form", "Hose Temp", Q_NULLPTR));
        hose_temp_panel_2->setText(QString());
        celcius_label_3->setText(QApplication::translate("Form", "[\302\260C]", Q_NULLPTR));
        rocket_weight_label_2->setText(QApplication::translate("Form", "Rocket Weight", Q_NULLPTR));
        rocket_weight_panel_2->setText(QString());
        kg_label_2->setText(QApplication::translate("Form", "[kg]", Q_NULLPTR));
        battery_level_label->setText(QApplication::translate("Form", "Battery level", Q_NULLPTR));
        battery_level_panel->setText(QString());
        voltunit_label->setText(QApplication::translate("Form", "[V]", Q_NULLPTR));
        main_current_label->setText(QApplication::translate("Form", "Main current", Q_NULLPTR));
        main_current_panel->setText(QString());
        m_a_unit_label->setText(QApplication::translate("Form", "[mA]", Q_NULLPTR));
        label_8->setText(QApplication::translate("Form", "Secondary current", Q_NULLPTR));
        secondary_current_panel->setText(QString());
        ma_unit_label->setText(QApplication::translate("Form", "[mA]", Q_NULLPTR));
        label_11->setText(QApplication::translate("Form", "Wind speed", Q_NULLPTR));
        wind_speed_panel->setText(QString());
        m_s_unit_label_2->setText(QApplication::translate("Form", "[m/s]", Q_NULLPTR));
        tank_temp_panel_2->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_10), QApplication::translate("Form", "GSE Data", Q_NULLPTR));
        filling_open_button->setText(QApplication::translate("Form", "Open", Q_NULLPTR));
        purge_open_button->setText(QApplication::translate("Form", "Open", Q_NULLPTR));
        purge_label->setText(QApplication::translate("Form", "Purge", Q_NULLPTR));
        purge_close_button->setText(QApplication::translate("Form", "Close", Q_NULLPTR));
        filling_label->setText(QApplication::translate("Form", "Filling", Q_NULLPTR));
        filling_close_button->setText(QApplication::translate("Form", "Close", Q_NULLPTR));
        disconnect_wire_button->setText(QApplication::translate("Form", "Disconnect Wire", Q_NULLPTR));
        echo_button->setText(QApplication::translate("Form", "Echo", Q_NULLPTR));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QApplication::translate("Form", "GSE Control", Q_NULLPTR));
        time_panel->setText(QApplication::translate("Form", "44:44:44", Q_NULLPTR));
        manual_mode_button->setText(QApplication::translate("Form", "Manual Mode", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        request_rssi->setToolTip(QApplication::translate("Form", "<html><head/><body><p>Get RSSI</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        request_rssi->setText(QApplication::translate("Form", "RSSI", Q_NULLPTR));
        dbm_label->setText(QApplication::translate("Form", "dBm", Q_NULLPTR));
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
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WASSERFALLENGUIE24228_H
