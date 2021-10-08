/********************************************************************************
** Form generated from reading UI file 'MainGUIgkogUE.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINGUIGKOGUE_H
#define MAINGUIGKOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QLabel *temperature_panel;
    QLabel *m_unit_label_3;
    QLabel *pressure_label;
    QLabel *altitude_label_telemetry;
    QLabel *speed_panel;
    QLabel *avionics_state_panel;
    QLabel *speed_label;
    QLabel *avionics_state_label;
    QLabel *temperature_label;
    QLabel *celcius_label;
    QLabel *pressure_panel;
    QLabel *m_s_unit_label;
    QLabel *hpa_unit_label;
    QLabel *altitude_panel_telemetry;
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
    QLabel *label_28;
    QLabel *purge_valve_state_panel;
    QLabel *hose_disconnect_label;
    QLabel *secondary_ignition_label;
    QLabel *secondary_disconnect_state_panel;
    QLabel *main_disconnect_state_panel;
    QLabel *main_ignition_state_panel;
    QLabel *secondary_ignition_state_panel;
    QLabel *main_ignition_label;
    QLabel *purge_valve_label;
    QLabel *fill_valve_label;
    QLabel *fill_valve_state_panel;
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
    QWidget *tab_6;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_6;
    QGridLayout *gridLayout_21;
    QLabel *label_20;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *pp_venting_panel;
    QLabel *label_27;
    QLabel *label_3;
    QLabel *pp_pressure_2_panel;
    QLabel *label_26;
    QLabel *label_12;
    QLabel *pp_motor_position_panel;
    QLabel *label_5;
    QLabel *pp_status_panel;
    QLabel *label_16;
    QLabel *pp_temperature_2_panel;
    QLabel *label_6;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label;
    QLabel *label_24;
    QLabel *label_18;
    QLabel *pp_temperature_1_panel;
    QLabel *pp_temperature_3_panel;
    QLabel *pp_pressure_1_panel;
    QLabel *label_29;
    QLabel *pp_psu_voltage_panel;
    QLabel *label_31;
    QLabel *pp_thrust_target_panel;
    QLabel *label_32;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_12;
    QPushButton *recover_button;
    QPushButton *close_venting_button;
    QPushButton *abort_button;
    QPushButton *start_calibration_button;
    QPushButton *arm_button;
    QPushButton *open_venting_button;
    QPushButton *disarm_button;
    QWidget *tab_tvc;
    QHBoxLayout *horizontalLayout_21;
    QWidget *widget1;
    QGridLayout *gridLayout_121;
    QPushButton *tvc_shutdown_button;
    QPushButton *tvc_abort_button;
    QPushButton *tvc_recover_button;
    QSpacerItem *verticalSpacer;
    QPushButton *tvc_boot_button;
    QLabel *tvc_status_panel;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *tvc_rpi_status_panel;
    QWidget *right_widget;
    QGridLayout *gridLayout_9;
    QGroupBox *av_states_box;
    QGridLayout *gridLayout_11;
    QLabel *touchdown_label;
    QLabel *idle_state_ok_panel;
    QLabel *sleep_state_ok_panel;
    QLabel *second_event_label;
    QLabel *coast_label;
    QLabel *liftoff_label;
    QLabel *liftoff_state_ok_panel;
    QLabel *calibration_label;
    QLabel *sleep_label;
    QLabel *touchdown_event_ok_panel;
    QLabel *calibration_state_ok_panel;
    QLabel *coast_state_ok_panel;
    QLabel *second_event_ok_panel;
    QLabel *idle_label;
    QLabel *first_event_ok_panel;
    QLabel *first_event_label;
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
    QWidget *widget_7;
    QGridLayout *gridLayout_16;
    QLabel *label_19;
    QLabel *main_current_panel;
    QLabel *kg_label_2;
    QLabel *hose_pressure_label_2;
    QLabel *label_10;
    QLabel *hose_pressure_panel_2;
    QLabel *secondary_disconnect_current_panel;
    QLabel *rocket_weight_label_2;
    QLabel *voltunit_label;
    QLabel *battery_level_panel;
    QLabel *hoes_temp_label_2;
    QLabel *label_22;
    QLabel *label_4;
    QLabel *m_a_unit_label;
    QLabel *ma_unit_label;
    QLabel *main_current_label;
    QLabel *rocket_weight_panel_2;
    QLabel *purge_valve_current_label;
    QLabel *wind_speed_panel;
    QLabel *m_s_unit_label_2;
    QLabel *label_25;
    QLabel *label_11;
    QLabel *tank_temp_label_2;
    QLabel *label_23;
    QLabel *celcius_label_3;
    QLabel *label_17;
    QLabel *tank_temp_panel_2;
    QLabel *label_8;
    QLabel *celcius_label2_2;
    QLabel *label_21;
    QLabel *hose_temp_panel_2;
    QLabel *battery_level_label;
    QLabel *fill_valve_current_label;
    QLabel *secondary_current_panel;
    QLabel *hpa_panel_2;
    QLabel *main_disconnect_current_panel;
    QWidget *tab_9;
    QHBoxLayout *horizontalLayout_7;
    QWidget *gse_control_box;
    QGridLayout *gridLayout_15;
    QPushButton *filling_open_button;
    QLabel *purge_label;
    QLabel *label_2;
    QPushButton *echo_button;
    QPushButton *disconnect_on_button;
    QPushButton *purge_close_button;
    QLabel *filling_label;
    QPushButton *ignition_off_button;
    QPushButton *filling_close_button;
    QPushButton *disconnect_off_button;
    QPushButton *purge_open_button;
    QWidget *lcs_tab;
    QHBoxLayout *horizontalLayout_71;
    QWidget *lcs_container;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *lcs_button;
    QWidget *lcs_check_container;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *lcs_check_1;
    QCheckBox *lcs_check_2;
    QCheckBox *lcs_check_3;
    QCheckBox *lcs_check_4;
    QWidget *upper_widget;
    QGridLayout *gridLayout_5;
    QPushButton *manual_mode_button;
    QLabel *dbm_label;
    QLCDNumber *rssi_panel;
    QLabel *time_panel;
    QPushButton *request_rssi;
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
    QWidget *upper_widget_2;
    QHBoxLayout *horizontalLayout_19;
    QLabel *gse_launch_ack_label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1038, 695);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(0, 0));
        Form->setMaximumSize(QSize(9999, 9999));
        Form->setMouseTracking(false);
        Form->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout_11 = new QHBoxLayout(Form);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        left_widget = new QWidget(Form);
        left_widget->setObjectName(QString::fromUtf8("left_widget"));
        verticalLayout = new QVBoxLayout(left_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        com_box = new QGroupBox(left_widget);
        com_box->setObjectName(QString::fromUtf8("com_box"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(com_box->sizePolicy().hasHeightForWidth());
        com_box->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(com_box);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        packets_second_label = new QLabel(com_box);
        packets_second_label->setObjectName(QString::fromUtf8("packets_second_label"));

        gridLayout_4->addWidget(packets_second_label, 0, 0, 1, 1);

        packets_second_bar = new QProgressBar(com_box);
        packets_second_bar->setObjectName(QString::fromUtf8("packets_second_bar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(packets_second_bar->sizePolicy().hasHeightForWidth());
        packets_second_bar->setSizePolicy(sizePolicy2);
        packets_second_bar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk:horizontal { \n"
"background:rgb(0, 160, 250);} "));
        packets_second_bar->setMaximum(40);
        packets_second_bar->setValue(30);
        packets_second_bar->setAlignment(Qt::AlignCenter);
        packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(packets_second_bar, 0, 1, 1, 1);

        last_datagram_id = new QLabel(com_box);
        last_datagram_id->setObjectName(QString::fromUtf8("last_datagram_id"));

        gridLayout_4->addWidget(last_datagram_id, 1, 0, 1, 1);

        av_packets_second_bar = new QProgressBar(com_box);
        av_packets_second_bar->setObjectName(QString::fromUtf8("av_packets_second_bar"));
        sizePolicy2.setHeightForWidth(av_packets_second_bar->sizePolicy().hasHeightForWidth());
        av_packets_second_bar->setSizePolicy(sizePolicy2);
        av_packets_second_bar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk:horizontal { \n"
"background:rgb(52, 101, 164);} "));
        av_packets_second_bar->setMaximum(40);
        av_packets_second_bar->setValue(30);
        av_packets_second_bar->setAlignment(Qt::AlignCenter);
        av_packets_second_bar->setTextVisible(true);
        av_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(av_packets_second_bar, 1, 1, 1, 1);

        pl_packet_label = new QLabel(com_box);
        pl_packet_label->setObjectName(QString::fromUtf8("pl_packet_label"));

        gridLayout_4->addWidget(pl_packet_label, 2, 0, 1, 1);

        pl_packets_second_bar = new QProgressBar(com_box);
        pl_packets_second_bar->setObjectName(QString::fromUtf8("pl_packets_second_bar"));
        sizePolicy2.setHeightForWidth(pl_packets_second_bar->sizePolicy().hasHeightForWidth());
        pl_packets_second_bar->setSizePolicy(sizePolicy2);
        pl_packets_second_bar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk:horizontal { \n"
"background:rgb(52, 101, 164);} "));
        pl_packets_second_bar->setMaximum(40);
        pl_packets_second_bar->setValue(30);
        pl_packets_second_bar->setAlignment(Qt::AlignCenter);
        pl_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(pl_packets_second_bar, 2, 1, 1, 1);

        gse_packet_label = new QLabel(com_box);
        gse_packet_label->setObjectName(QString::fromUtf8("gse_packet_label"));

        gridLayout_4->addWidget(gse_packet_label, 3, 0, 1, 1);

        gse_packets_second_bar = new QProgressBar(com_box);
        gse_packets_second_bar->setObjectName(QString::fromUtf8("gse_packets_second_bar"));
        sizePolicy2.setHeightForWidth(gse_packets_second_bar->sizePolicy().hasHeightForWidth());
        gse_packets_second_bar->setSizePolicy(sizePolicy2);
        gse_packets_second_bar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk:horizontal { \n"
"background:rgb(52, 101, 164);} "));
        gse_packets_second_bar->setMaximum(40);
        gse_packets_second_bar->setValue(30);
        gse_packets_second_bar->setAlignment(Qt::AlignCenter);
        gse_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(gse_packets_second_bar, 3, 1, 1, 1);

        pp_packets_second_label = new QLabel(com_box);
        pp_packets_second_label->setObjectName(QString::fromUtf8("pp_packets_second_label"));

        gridLayout_4->addWidget(pp_packets_second_label, 4, 0, 1, 1);

        pp_packets_second_bar = new QProgressBar(com_box);
        pp_packets_second_bar->setObjectName(QString::fromUtf8("pp_packets_second_bar"));
        sizePolicy2.setHeightForWidth(pp_packets_second_bar->sizePolicy().hasHeightForWidth());
        pp_packets_second_bar->setSizePolicy(sizePolicy2);
        pp_packets_second_bar->setStyleSheet(QString::fromUtf8("QProgressBar::chunk:horizontal { \n"
"background:rgb(52, 101, 164);} "));
        pp_packets_second_bar->setMaximum(40);
        pp_packets_second_bar->setValue(30);
        pp_packets_second_bar->setAlignment(Qt::AlignCenter);
        pp_packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(pp_packets_second_bar, 4, 1, 1, 1);

        received_pack_cnt_label = new QLabel(com_box);
        received_pack_cnt_label->setObjectName(QString::fromUtf8("received_pack_cnt_label"));
        received_pack_cnt_label->setMinimumSize(QSize(155, 0));

        gridLayout_4->addWidget(received_pack_cnt_label, 5, 0, 1, 1);

        received_pack_cnt_panel = new QLabel(com_box);
        received_pack_cnt_panel->setObjectName(QString::fromUtf8("received_pack_cnt_panel"));

        gridLayout_4->addWidget(received_pack_cnt_panel, 5, 1, 1, 1);

        time_since_last_label = new QLabel(com_box);
        time_since_last_label->setObjectName(QString::fromUtf8("time_since_last_label"));

        gridLayout_4->addWidget(time_since_last_label, 6, 0, 1, 1);

        time_since_last_panel = new QLabel(com_box);
        time_since_last_panel->setObjectName(QString::fromUtf8("time_since_last_panel"));

        gridLayout_4->addWidget(time_since_last_panel, 6, 1, 1, 1);

        corrupted_label = new QLabel(com_box);
        corrupted_label->setObjectName(QString::fromUtf8("corrupted_label"));

        gridLayout_4->addWidget(corrupted_label, 7, 0, 1, 1);

        corrupted_panel = new QLabel(com_box);
        corrupted_panel->setObjectName(QString::fromUtf8("corrupted_panel"));

        gridLayout_4->addWidget(corrupted_panel, 7, 1, 1, 1);


        verticalLayout->addWidget(com_box);

        groupBox_7 = new QGroupBox(left_widget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_22 = new QGridLayout(groupBox_7);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        altitude_label_gps = new QLabel(groupBox_7);
        altitude_label_gps->setObjectName(QString::fromUtf8("altitude_label_gps"));

        gridLayout_22->addWidget(altitude_label_gps, 0, 0, 1, 1);

        altitude_lcd_gps = new QLCDNumber(groupBox_7);
        altitude_lcd_gps->setObjectName(QString::fromUtf8("altitude_lcd_gps"));
        altitude_lcd_gps->setSmallDecimalPoint(false);
        altitude_lcd_gps->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_lcd_gps, 0, 1, 1, 1);

        ft_unit_label_2 = new QLabel(groupBox_7);
        ft_unit_label_2->setObjectName(QString::fromUtf8("ft_unit_label_2"));
        ft_unit_label_2->setMaximumSize(QSize(20, 16777215));

        gridLayout_22->addWidget(ft_unit_label_2, 0, 4, 1, 1);

        m_unit_label_2 = new QLabel(groupBox_7);
        m_unit_label_2->setObjectName(QString::fromUtf8("m_unit_label_2"));
        m_unit_label_2->setMaximumSize(QSize(30, 16777215));

        gridLayout_22->addWidget(m_unit_label_2, 0, 2, 1, 1);

        altitude_lcd_gps_ft = new QLCDNumber(groupBox_7);
        altitude_lcd_gps_ft->setObjectName(QString::fromUtf8("altitude_lcd_gps_ft"));
        altitude_lcd_gps_ft->setFrameShadow(QFrame::Raised);
        altitude_lcd_gps_ft->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_lcd_gps_ft, 0, 3, 1, 1);

        altitude_max_label = new QLabel(groupBox_7);
        altitude_max_label->setObjectName(QString::fromUtf8("altitude_max_label"));

        gridLayout_22->addWidget(altitude_max_label, 1, 0, 1, 1);

        altitude_max_lcd_m = new QLCDNumber(groupBox_7);
        altitude_max_lcd_m->setObjectName(QString::fromUtf8("altitude_max_lcd_m"));
        altitude_max_lcd_m->setEnabled(true);
        altitude_max_lcd_m->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_max_lcd_m, 1, 1, 1, 1);

        m_unit_label = new QLabel(groupBox_7);
        m_unit_label->setObjectName(QString::fromUtf8("m_unit_label"));

        gridLayout_22->addWidget(m_unit_label, 1, 2, 1, 1);

        altitude_max_lcd_ft = new QLCDNumber(groupBox_7);
        altitude_max_lcd_ft->setObjectName(QString::fromUtf8("altitude_max_lcd_ft"));
        altitude_max_lcd_ft->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_22->addWidget(altitude_max_lcd_ft, 1, 3, 1, 1);

        ft_unit_label = new QLabel(groupBox_7);
        ft_unit_label->setObjectName(QString::fromUtf8("ft_unit_label"));

        gridLayout_22->addWidget(ft_unit_label, 1, 4, 1, 1);


        verticalLayout->addWidget(groupBox_7);

        gps_box = new QGroupBox(left_widget);
        gps_box->setObjectName(QString::fromUtf8("gps_box"));
        sizePolicy1.setHeightForWidth(gps_box->sizePolicy().hasHeightForWidth());
        gps_box->setSizePolicy(sizePolicy1);
        gps_box->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(gps_box);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        longitude_label = new QLabel(gps_box);
        longitude_label->setObjectName(QString::fromUtf8("longitude_label"));

        gridLayout_3->addWidget(longitude_label, 3, 0, 1, 1);

        hdop_label = new QLabel(gps_box);
        hdop_label->setObjectName(QString::fromUtf8("hdop_label"));

        gridLayout_3->addWidget(hdop_label, 6, 0, 1, 1);

        latitude_panel = new QLabel(gps_box);
        latitude_panel->setObjectName(QString::fromUtf8("latitude_panel"));
        latitude_panel->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(latitude_panel, 3, 6, 1, 1);

        sat_nbr_label = new QLabel(gps_box);
        sat_nbr_label->setObjectName(QString::fromUtf8("sat_nbr_label"));

        gridLayout_3->addWidget(sat_nbr_label, 6, 5, 1, 1);

        sat_nbr_panel = new QLabel(gps_box);
        sat_nbr_panel->setObjectName(QString::fromUtf8("sat_nbr_panel"));

        gridLayout_3->addWidget(sat_nbr_panel, 6, 6, 1, 1);

        latitude_label = new QLabel(gps_box);
        latitude_label->setObjectName(QString::fromUtf8("latitude_label"));

        gridLayout_3->addWidget(latitude_label, 3, 5, 1, 1);

        longitude_panel = new QLabel(gps_box);
        longitude_panel->setObjectName(QString::fromUtf8("longitude_panel"));

        gridLayout_3->addWidget(longitude_panel, 3, 1, 1, 1);

        hdop_panel = new QLabel(gps_box);
        hdop_panel->setObjectName(QString::fromUtf8("hdop_panel"));

        gridLayout_3->addWidget(hdop_panel, 6, 1, 1, 1);


        verticalLayout->addWidget(gps_box);

        avionics_box = new QGroupBox(left_widget);
        avionics_box->setObjectName(QString::fromUtf8("avionics_box"));
        sizePolicy1.setHeightForWidth(avionics_box->sizePolicy().hasHeightForWidth());
        avionics_box->setSizePolicy(sizePolicy1);
        gridLayout_8 = new QGridLayout(avionics_box);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        temperature_panel = new QLabel(avionics_box);
        temperature_panel->setObjectName(QString::fromUtf8("temperature_panel"));

        gridLayout_8->addWidget(temperature_panel, 0, 1, 1, 1);

        m_unit_label_3 = new QLabel(avionics_box);
        m_unit_label_3->setObjectName(QString::fromUtf8("m_unit_label_3"));
        m_unit_label_3->setMaximumSize(QSize(30, 16777215));
        m_unit_label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(m_unit_label_3, 6, 2, 1, 1);

        pressure_label = new QLabel(avionics_box);
        pressure_label->setObjectName(QString::fromUtf8("pressure_label"));

        gridLayout_8->addWidget(pressure_label, 3, 0, 1, 1);

        altitude_label_telemetry = new QLabel(avionics_box);
        altitude_label_telemetry->setObjectName(QString::fromUtf8("altitude_label_telemetry"));

        gridLayout_8->addWidget(altitude_label_telemetry, 6, 0, 1, 1);

        speed_panel = new QLabel(avionics_box);
        speed_panel->setObjectName(QString::fromUtf8("speed_panel"));

        gridLayout_8->addWidget(speed_panel, 4, 1, 1, 1);

        avionics_state_panel = new QLabel(avionics_box);
        avionics_state_panel->setObjectName(QString::fromUtf8("avionics_state_panel"));

        gridLayout_8->addWidget(avionics_state_panel, 7, 1, 1, 2);

        speed_label = new QLabel(avionics_box);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));

        gridLayout_8->addWidget(speed_label, 4, 0, 1, 1);

        avionics_state_label = new QLabel(avionics_box);
        avionics_state_label->setObjectName(QString::fromUtf8("avionics_state_label"));

        gridLayout_8->addWidget(avionics_state_label, 7, 0, 1, 1);

        temperature_label = new QLabel(avionics_box);
        temperature_label->setObjectName(QString::fromUtf8("temperature_label"));

        gridLayout_8->addWidget(temperature_label, 0, 0, 1, 1);

        celcius_label = new QLabel(avionics_box);
        celcius_label->setObjectName(QString::fromUtf8("celcius_label"));
        celcius_label->setMinimumSize(QSize(0, 0));
        celcius_label->setMaximumSize(QSize(30, 16777215));
        celcius_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(celcius_label, 0, 2, 1, 1);

        pressure_panel = new QLabel(avionics_box);
        pressure_panel->setObjectName(QString::fromUtf8("pressure_panel"));

        gridLayout_8->addWidget(pressure_panel, 3, 1, 1, 1);

        m_s_unit_label = new QLabel(avionics_box);
        m_s_unit_label->setObjectName(QString::fromUtf8("m_s_unit_label"));
        m_s_unit_label->setMinimumSize(QSize(45, 0));
        m_s_unit_label->setMaximumSize(QSize(30, 16777215));
        m_s_unit_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(m_s_unit_label, 4, 2, 1, 1);

        hpa_unit_label = new QLabel(avionics_box);
        hpa_unit_label->setObjectName(QString::fromUtf8("hpa_unit_label"));
        hpa_unit_label->setMinimumSize(QSize(40, 0));
        hpa_unit_label->setMaximumSize(QSize(30, 16777215));
        hpa_unit_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(hpa_unit_label, 3, 2, 1, 1);

        altitude_panel_telemetry = new QLabel(avionics_box);
        altitude_panel_telemetry->setObjectName(QString::fromUtf8("altitude_panel_telemetry"));

        gridLayout_8->addWidget(altitude_panel_telemetry, 6, 1, 1, 1);


        verticalLayout->addWidget(avionics_box);


        horizontalLayout_11->addWidget(left_widget);

        middle_widget = new QWidget(Form);
        middle_widget->setObjectName(QString::fromUtf8("middle_widget"));
        gridLayout_6 = new QGridLayout(middle_widget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        widget_3 = new QWidget(middle_widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_10 = new QHBoxLayout(widget_3);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        tabWidget_5 = new QTabWidget(widget_3);
        tabWidget_5->setObjectName(QString::fromUtf8("tabWidget_5"));
        tabWidget_5->setMinimumSize(QSize(150, 0));
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        gridLayout_7 = new QGridLayout(tab_12);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        euler_z_label = new QLabel(tab_12);
        euler_z_label->setObjectName(QString::fromUtf8("euler_z_label"));
        euler_z_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(euler_z_label, 2, 0, 1, 1);

        euler_y_label = new QLabel(tab_12);
        euler_y_label->setObjectName(QString::fromUtf8("euler_y_label"));
        euler_y_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(euler_y_label, 1, 0, 1, 1);

        euler_x_label = new QLabel(tab_12);
        euler_x_label->setObjectName(QString::fromUtf8("euler_x_label"));
        euler_x_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(euler_x_label, 0, 0, 1, 1);

        euler_x_panel = new QLabel(tab_12);
        euler_x_panel->setObjectName(QString::fromUtf8("euler_x_panel"));

        gridLayout_7->addWidget(euler_x_panel, 0, 1, 1, 1);

        euler_y_panel = new QLabel(tab_12);
        euler_y_panel->setObjectName(QString::fromUtf8("euler_y_panel"));

        gridLayout_7->addWidget(euler_y_panel, 1, 1, 1, 1);

        euler_z_panel = new QLabel(tab_12);
        euler_z_panel->setObjectName(QString::fromUtf8("euler_z_panel"));

        gridLayout_7->addWidget(euler_z_panel, 2, 1, 1, 1);

        tabWidget_5->addTab(tab_12, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        gridLayout_24 = new QGridLayout(tab_11);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        accel_x_panel = new QLabel(tab_11);
        accel_x_panel->setObjectName(QString::fromUtf8("accel_x_panel"));
        accel_x_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_24->addWidget(accel_x_panel, 0, 2, 1, 1);

        accel_x_label = new QLabel(tab_11);
        accel_x_label->setObjectName(QString::fromUtf8("accel_x_label"));
        accel_x_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_24->addWidget(accel_x_label, 0, 1, 1, 1);

        accel_z_panel = new QLabel(tab_11);
        accel_z_panel->setObjectName(QString::fromUtf8("accel_z_panel"));
        accel_z_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_24->addWidget(accel_z_panel, 2, 2, 1, 1);

        accel_z_label = new QLabel(tab_11);
        accel_z_label->setObjectName(QString::fromUtf8("accel_z_label"));
        accel_z_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_24->addWidget(accel_z_label, 2, 1, 1, 1);

        accel_y_label = new QLabel(tab_11);
        accel_y_label->setObjectName(QString::fromUtf8("accel_y_label"));
        accel_y_label->setMaximumSize(QSize(25, 16777215));

        gridLayout_24->addWidget(accel_y_label, 1, 1, 1, 1);

        accel_y_panel = new QLabel(tab_11);
        accel_y_panel->setObjectName(QString::fromUtf8("accel_y_panel"));
        accel_y_panel->setFrameShape(QFrame::NoFrame);

        gridLayout_24->addWidget(accel_y_panel, 1, 2, 1, 1);

        norm_panel = new QLabel(tab_11);
        norm_panel->setObjectName(QString::fromUtf8("norm_panel"));

        gridLayout_24->addWidget(norm_panel, 3, 2, 1, 1);

        norm_label = new QLabel(tab_11);
        norm_label->setObjectName(QString::fromUtf8("norm_label"));

        gridLayout_24->addWidget(norm_label, 3, 1, 1, 1);

        tabWidget_5->addTab(tab_11, QString());

        horizontalLayout_10->addWidget(tabWidget_5);

        gse_state_box = new QGroupBox(widget_3);
        gse_state_box->setObjectName(QString::fromUtf8("gse_state_box"));
        sizePolicy1.setHeightForWidth(gse_state_box->sizePolicy().hasHeightForWidth());
        gse_state_box->setSizePolicy(sizePolicy1);
        gridLayout_17 = new QGridLayout(gse_state_box);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        label_28 = new QLabel(gse_state_box);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_17->addWidget(label_28, 6, 0, 1, 1);

        purge_valve_state_panel = new QLabel(gse_state_box);
        purge_valve_state_panel->setObjectName(QString::fromUtf8("purge_valve_state_panel"));
        purge_valve_state_panel->setMinimumSize(QSize(23, 0));
        purge_valve_state_panel->setMaximumSize(QSize(23, 16777215));
        purge_valve_state_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        purge_valve_state_panel->setFrameShape(QFrame::NoFrame);
        purge_valve_state_panel->setLineWidth(1);
        purge_valve_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(purge_valve_state_panel, 1, 1, 1, 1);

        hose_disconnect_label = new QLabel(gse_state_box);
        hose_disconnect_label->setObjectName(QString::fromUtf8("hose_disconnect_label"));

        gridLayout_17->addWidget(hose_disconnect_label, 5, 0, 1, 1);

        secondary_ignition_label = new QLabel(gse_state_box);
        secondary_ignition_label->setObjectName(QString::fromUtf8("secondary_ignition_label"));

        gridLayout_17->addWidget(secondary_ignition_label, 4, 0, 1, 1);

        secondary_disconnect_state_panel = new QLabel(gse_state_box);
        secondary_disconnect_state_panel->setObjectName(QString::fromUtf8("secondary_disconnect_state_panel"));
        secondary_disconnect_state_panel->setMinimumSize(QSize(23, 0));
        secondary_disconnect_state_panel->setMaximumSize(QSize(23, 16777215));
        secondary_disconnect_state_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        secondary_disconnect_state_panel->setFrameShape(QFrame::NoFrame);
        secondary_disconnect_state_panel->setLineWidth(1);
        secondary_disconnect_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(secondary_disconnect_state_panel, 6, 1, 1, 1);

        main_disconnect_state_panel = new QLabel(gse_state_box);
        main_disconnect_state_panel->setObjectName(QString::fromUtf8("main_disconnect_state_panel"));
        main_disconnect_state_panel->setMinimumSize(QSize(23, 0));
        main_disconnect_state_panel->setMaximumSize(QSize(23, 16777215));
        main_disconnect_state_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        main_disconnect_state_panel->setFrameShape(QFrame::NoFrame);
        main_disconnect_state_panel->setLineWidth(1);
        main_disconnect_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(main_disconnect_state_panel, 5, 1, 1, 1);

        main_ignition_state_panel = new QLabel(gse_state_box);
        main_ignition_state_panel->setObjectName(QString::fromUtf8("main_ignition_state_panel"));
        main_ignition_state_panel->setMinimumSize(QSize(23, 0));
        main_ignition_state_panel->setMaximumSize(QSize(23, 16777215));
        main_ignition_state_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        main_ignition_state_panel->setFrameShape(QFrame::NoFrame);
        main_ignition_state_panel->setLineWidth(1);
        main_ignition_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(main_ignition_state_panel, 3, 1, 1, 1);

        secondary_ignition_state_panel = new QLabel(gse_state_box);
        secondary_ignition_state_panel->setObjectName(QString::fromUtf8("secondary_ignition_state_panel"));
        secondary_ignition_state_panel->setMinimumSize(QSize(23, 0));
        secondary_ignition_state_panel->setMaximumSize(QSize(23, 16777215));
        secondary_ignition_state_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        secondary_ignition_state_panel->setFrameShape(QFrame::NoFrame);
        secondary_ignition_state_panel->setLineWidth(1);
        secondary_ignition_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(secondary_ignition_state_panel, 4, 1, 1, 1);

        main_ignition_label = new QLabel(gse_state_box);
        main_ignition_label->setObjectName(QString::fromUtf8("main_ignition_label"));

        gridLayout_17->addWidget(main_ignition_label, 3, 0, 1, 1);

        purge_valve_label = new QLabel(gse_state_box);
        purge_valve_label->setObjectName(QString::fromUtf8("purge_valve_label"));

        gridLayout_17->addWidget(purge_valve_label, 1, 0, 1, 1);

        fill_valve_label = new QLabel(gse_state_box);
        fill_valve_label->setObjectName(QString::fromUtf8("fill_valve_label"));

        gridLayout_17->addWidget(fill_valve_label, 0, 0, 1, 1);

        fill_valve_state_panel = new QLabel(gse_state_box);
        fill_valve_state_panel->setObjectName(QString::fromUtf8("fill_valve_state_panel"));
        fill_valve_state_panel->setMinimumSize(QSize(23, 0));
        fill_valve_state_panel->setMaximumSize(QSize(23, 16777215));
        fill_valve_state_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        fill_valve_state_panel->setFrameShape(QFrame::NoFrame);
        fill_valve_state_panel->setLineWidth(1);
        fill_valve_state_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(fill_valve_state_panel, 0, 1, 1, 1);


        horizontalLayout_10->addWidget(gse_state_box);


        gridLayout_6->addWidget(widget_3, 2, 0, 1, 1);

        tabWidget_2 = new QTabWidget(middle_widget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(250, 0));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget_4 = new QWidget(tab_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        gridLayout_19 = new QGridLayout(widget_4);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        pl_bme_humidity_label = new QLabel(widget_4);
        pl_bme_humidity_label->setObjectName(QString::fromUtf8("pl_bme_humidity_label"));

        gridLayout_19->addWidget(pl_bme_humidity_label, 2, 0, 1, 1);

        pl_bme_temperature_label = new QLabel(widget_4);
        pl_bme_temperature_label->setObjectName(QString::fromUtf8("pl_bme_temperature_label"));

        gridLayout_19->addWidget(pl_bme_temperature_label, 0, 0, 1, 1);

        pl_bme_pressure_label = new QLabel(widget_4);
        pl_bme_pressure_label->setObjectName(QString::fromUtf8("pl_bme_pressure_label"));

        gridLayout_19->addWidget(pl_bme_pressure_label, 1, 0, 1, 1);

        pl_bme_temperature_panel = new QLabel(widget_4);
        pl_bme_temperature_panel->setObjectName(QString::fromUtf8("pl_bme_temperature_panel"));
        pl_bme_temperature_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_bme_temperature_panel, 0, 1, 1, 1);

        pl_bme_altitude_label = new QLabel(widget_4);
        pl_bme_altitude_label->setObjectName(QString::fromUtf8("pl_bme_altitude_label"));

        gridLayout_19->addWidget(pl_bme_altitude_label, 3, 0, 1, 1);

        pl_bme_altitude_panel = new QLabel(widget_4);
        pl_bme_altitude_panel->setObjectName(QString::fromUtf8("pl_bme_altitude_panel"));
        pl_bme_altitude_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_bme_altitude_panel, 3, 1, 1, 1);

        pl_bme_humidity_panel = new QLabel(widget_4);
        pl_bme_humidity_panel->setObjectName(QString::fromUtf8("pl_bme_humidity_panel"));
        pl_bme_humidity_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_bme_humidity_panel, 2, 1, 1, 1);

        pl_bme_pressure_panel = new QLabel(widget_4);
        pl_bme_pressure_panel->setObjectName(QString::fromUtf8("pl_bme_pressure_panel"));
        pl_bme_pressure_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_bme_pressure_panel, 1, 1, 1, 1);

        pl_celcius_label_2 = new QLabel(widget_4);
        pl_celcius_label_2->setObjectName(QString::fromUtf8("pl_celcius_label_2"));
        pl_celcius_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_celcius_label_2, 0, 2, 1, 1);

        pl_hpa_label = new QLabel(widget_4);
        pl_hpa_label->setObjectName(QString::fromUtf8("pl_hpa_label"));
        pl_hpa_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_hpa_label, 1, 2, 1, 1);

        pl_percentage_label = new QLabel(widget_4);
        pl_percentage_label->setObjectName(QString::fromUtf8("pl_percentage_label"));
        pl_percentage_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_percentage_label, 2, 2, 1, 1);

        pl_m_label = new QLabel(widget_4);
        pl_m_label->setObjectName(QString::fromUtf8("pl_m_label"));
        pl_m_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(pl_m_label, 3, 2, 1, 1);


        horizontalLayout_3->addWidget(widget_4);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_4 = new QHBoxLayout(tab_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget_31 = new QWidget(tab_4);
        widget_31->setObjectName(QString::fromUtf8("widget_31"));
        sizePolicy1.setHeightForWidth(widget_31->sizePolicy().hasHeightForWidth());
        widget_31->setSizePolicy(sizePolicy1);
        gridLayout_18 = new QGridLayout(widget_31);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        pl_latitude_label = new QLabel(widget_31);
        pl_latitude_label->setObjectName(QString::fromUtf8("pl_latitude_label"));

        gridLayout_18->addWidget(pl_latitude_label, 3, 0, 1, 1);

        pl_sat_nbr_panel = new QLabel(widget_31);
        pl_sat_nbr_panel->setObjectName(QString::fromUtf8("pl_sat_nbr_panel"));

        gridLayout_18->addWidget(pl_sat_nbr_panel, 2, 2, 1, 1);

        pl_latitude_panel = new QLabel(widget_31);
        pl_latitude_panel->setObjectName(QString::fromUtf8("pl_latitude_panel"));

        gridLayout_18->addWidget(pl_latitude_panel, 3, 2, 1, 1);

        pl_satellites_label = new QLabel(widget_31);
        pl_satellites_label->setObjectName(QString::fromUtf8("pl_satellites_label"));

        gridLayout_18->addWidget(pl_satellites_label, 2, 0, 1, 1);

        pl_longitude_label = new QLabel(widget_31);
        pl_longitude_label->setObjectName(QString::fromUtf8("pl_longitude_label"));

        gridLayout_18->addWidget(pl_longitude_label, 4, 0, 1, 1);

        pl_longitude_panel = new QLabel(widget_31);
        pl_longitude_panel->setObjectName(QString::fromUtf8("pl_longitude_panel"));

        gridLayout_18->addWidget(pl_longitude_panel, 4, 2, 1, 1);

        pl_gps_altitude_label = new QLabel(widget_31);
        pl_gps_altitude_label->setObjectName(QString::fromUtf8("pl_gps_altitude_label"));

        gridLayout_18->addWidget(pl_gps_altitude_label, 5, 0, 1, 1);

        pl_gps_altitude_panel = new QLabel(widget_31);
        pl_gps_altitude_panel->setObjectName(QString::fromUtf8("pl_gps_altitude_panel"));

        gridLayout_18->addWidget(pl_gps_altitude_panel, 5, 2, 1, 1);

        pl_hdop_label = new QLabel(widget_31);
        pl_hdop_label->setObjectName(QString::fromUtf8("pl_hdop_label"));

        gridLayout_18->addWidget(pl_hdop_label, 6, 0, 1, 1);

        pl_hdop_panel = new QLabel(widget_31);
        pl_hdop_panel->setObjectName(QString::fromUtf8("pl_hdop_panel"));

        gridLayout_18->addWidget(pl_hdop_panel, 6, 2, 1, 1);


        horizontalLayout_4->addWidget(widget_31);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        horizontalLayout_5 = new QHBoxLayout(tab_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_5 = new QWidget(tab_5);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        gridLayout_20 = new QGridLayout(widget_5);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        pl_bno_az_panel = new QLabel(widget_5);
        pl_bno_az_panel->setObjectName(QString::fromUtf8("pl_bno_az_panel"));

        gridLayout_20->addWidget(pl_bno_az_panel, 6, 1, 1, 1);

        pl_bno_oy_label = new QLabel(widget_5);
        pl_bno_oy_label->setObjectName(QString::fromUtf8("pl_bno_oy_label"));

        gridLayout_20->addWidget(pl_bno_oy_label, 2, 0, 1, 1);

        pl_bno_ox_panel = new QLabel(widget_5);
        pl_bno_ox_panel->setObjectName(QString::fromUtf8("pl_bno_ox_panel"));

        gridLayout_20->addWidget(pl_bno_ox_panel, 1, 1, 1, 1);

        pl_bno_ax_panel = new QLabel(widget_5);
        pl_bno_ax_panel->setObjectName(QString::fromUtf8("pl_bno_ax_panel"));

        gridLayout_20->addWidget(pl_bno_ax_panel, 4, 1, 1, 1);

        pl_bno_oz_label = new QLabel(widget_5);
        pl_bno_oz_label->setObjectName(QString::fromUtf8("pl_bno_oz_label"));

        gridLayout_20->addWidget(pl_bno_oz_label, 3, 0, 1, 1);

        pl_bno_ax_label = new QLabel(widget_5);
        pl_bno_ax_label->setObjectName(QString::fromUtf8("pl_bno_ax_label"));

        gridLayout_20->addWidget(pl_bno_ax_label, 4, 0, 1, 1);

        pl_bno_ay_label = new QLabel(widget_5);
        pl_bno_ay_label->setObjectName(QString::fromUtf8("pl_bno_ay_label"));

        gridLayout_20->addWidget(pl_bno_ay_label, 5, 0, 1, 1);

        pl_bno_az_label = new QLabel(widget_5);
        pl_bno_az_label->setObjectName(QString::fromUtf8("pl_bno_az_label"));

        gridLayout_20->addWidget(pl_bno_az_label, 6, 0, 1, 1);

        pl_bno_ay_panel = new QLabel(widget_5);
        pl_bno_ay_panel->setObjectName(QString::fromUtf8("pl_bno_ay_panel"));

        gridLayout_20->addWidget(pl_bno_ay_panel, 5, 1, 1, 1);

        pl_bno_oy_panel = new QLabel(widget_5);
        pl_bno_oy_panel->setObjectName(QString::fromUtf8("pl_bno_oy_panel"));

        gridLayout_20->addWidget(pl_bno_oy_panel, 2, 1, 1, 1);

        pl_bno_temperature_label = new QLabel(widget_5);
        pl_bno_temperature_label->setObjectName(QString::fromUtf8("pl_bno_temperature_label"));

        gridLayout_20->addWidget(pl_bno_temperature_label, 0, 0, 1, 1);

        pl_bno_temperature_panel = new QLabel(widget_5);
        pl_bno_temperature_panel->setObjectName(QString::fromUtf8("pl_bno_temperature_panel"));

        gridLayout_20->addWidget(pl_bno_temperature_panel, 0, 1, 1, 1);

        pl_bno_oz_panel = new QLabel(widget_5);
        pl_bno_oz_panel->setObjectName(QString::fromUtf8("pl_bno_oz_panel"));

        gridLayout_20->addWidget(pl_bno_oz_panel, 3, 1, 1, 1);

        deg_label_2 = new QLabel(widget_5);
        deg_label_2->setObjectName(QString::fromUtf8("deg_label_2"));
        deg_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_20->addWidget(deg_label_2, 2, 2, 1, 1);

        deg_label_3 = new QLabel(widget_5);
        deg_label_3->setObjectName(QString::fromUtf8("deg_label_3"));
        deg_label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_20->addWidget(deg_label_3, 1, 2, 1, 1);

        deg_label = new QLabel(widget_5);
        deg_label->setObjectName(QString::fromUtf8("deg_label"));
        deg_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_20->addWidget(deg_label, 3, 2, 1, 1);

        pl_bno_ox_label = new QLabel(widget_5);
        pl_bno_ox_label->setObjectName(QString::fromUtf8("pl_bno_ox_label"));

        gridLayout_20->addWidget(pl_bno_ox_label, 1, 0, 1, 1);

        ms2_label_2 = new QLabel(widget_5);
        ms2_label_2->setObjectName(QString::fromUtf8("ms2_label_2"));
        ms2_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_20->addWidget(ms2_label_2, 5, 2, 1, 1);

        ms2_label_3 = new QLabel(widget_5);
        ms2_label_3->setObjectName(QString::fromUtf8("ms2_label_3"));
        ms2_label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_20->addWidget(ms2_label_3, 4, 2, 1, 1);

        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_20->addWidget(label_7, 0, 2, 1, 1);

        ms2_label = new QLabel(widget_5);
        ms2_label->setObjectName(QString::fromUtf8("ms2_label"));
        ms2_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_20->addWidget(ms2_label, 6, 2, 1, 1);


        horizontalLayout_5->addWidget(widget_5);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        horizontalLayout_6 = new QHBoxLayout(tab_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widget_6 = new QWidget(tab_6);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_21 = new QGridLayout(widget_6);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        label_20 = new QLabel(widget_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_20, 4, 2, 1, 1);

        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_21->addWidget(label_9, 2, 0, 1, 1);

        label_13 = new QLabel(widget_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_21->addWidget(label_13, 3, 0, 1, 1);

        pp_venting_panel = new QLabel(widget_6);
        pp_venting_panel->setObjectName(QString::fromUtf8("pp_venting_panel"));

        gridLayout_21->addWidget(pp_venting_panel, 6, 1, 1, 1);

        label_27 = new QLabel(widget_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_21->addWidget(label_27, 7, 0, 1, 1);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_3, 1, 2, 1, 1);

        pp_pressure_2_panel = new QLabel(widget_6);
        pp_pressure_2_panel->setObjectName(QString::fromUtf8("pp_pressure_2_panel"));

        gridLayout_21->addWidget(pp_pressure_2_panel, 1, 1, 1, 1);

        label_26 = new QLabel(widget_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_21->addWidget(label_26, 6, 0, 1, 1);

        label_12 = new QLabel(widget_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_12, 2, 2, 1, 1);

        pp_motor_position_panel = new QLabel(widget_6);
        pp_motor_position_panel->setObjectName(QString::fromUtf8("pp_motor_position_panel"));

        gridLayout_21->addWidget(pp_motor_position_panel, 8, 1, 1, 1);

        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_21->addWidget(label_5, 0, 0, 1, 1);

        pp_status_panel = new QLabel(widget_6);
        pp_status_panel->setObjectName(QString::fromUtf8("pp_status_panel"));

        gridLayout_21->addWidget(pp_status_panel, 5, 1, 1, 1);

        label_16 = new QLabel(widget_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_21->addWidget(label_16, 8, 0, 1, 1);

        pp_temperature_2_panel = new QLabel(widget_6);
        pp_temperature_2_panel->setObjectName(QString::fromUtf8("pp_temperature_2_panel"));

        gridLayout_21->addWidget(pp_temperature_2_panel, 3, 1, 1, 1);

        label_6 = new QLabel(widget_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_6, 0, 2, 1, 1);

        label_14 = new QLabel(widget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_21->addWidget(label_14, 4, 0, 1, 1);

        label_15 = new QLabel(widget_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_21->addWidget(label_15, 5, 0, 1, 1);

        label = new QLabel(widget_6);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_21->addWidget(label, 1, 0, 1, 1);

        label_24 = new QLabel(widget_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_24, 8, 2, 1, 1);

        label_18 = new QLabel(widget_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_18, 3, 2, 1, 1);

        pp_temperature_1_panel = new QLabel(widget_6);
        pp_temperature_1_panel->setObjectName(QString::fromUtf8("pp_temperature_1_panel"));

        gridLayout_21->addWidget(pp_temperature_1_panel, 2, 1, 1, 1);

        pp_temperature_3_panel = new QLabel(widget_6);
        pp_temperature_3_panel->setObjectName(QString::fromUtf8("pp_temperature_3_panel"));

        gridLayout_21->addWidget(pp_temperature_3_panel, 4, 1, 1, 1);

        pp_pressure_1_panel = new QLabel(widget_6);
        pp_pressure_1_panel->setObjectName(QString::fromUtf8("pp_pressure_1_panel"));

        gridLayout_21->addWidget(pp_pressure_1_panel, 0, 1, 1, 1);

        label_29 = new QLabel(widget_6);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_29, 7, 2, 1, 1);

        pp_psu_voltage_panel = new QLabel(widget_6);
        pp_psu_voltage_panel->setObjectName(QString::fromUtf8("pp_psu_voltage_panel"));

        gridLayout_21->addWidget(pp_psu_voltage_panel, 7, 1, 1, 1);

        label_31 = new QLabel(widget_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_21->addWidget(label_31, 9, 0, 1, 1);

        pp_thrust_target_panel = new QLabel(widget_6);
        pp_thrust_target_panel->setObjectName(QString::fromUtf8("pp_thrust_target_panel"));

        gridLayout_21->addWidget(pp_thrust_target_panel, 9, 1, 1, 1);

        label_32 = new QLabel(widget_6);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(label_32, 9, 2, 1, 1);


        horizontalLayout_6->addWidget(widget_6);

        tabWidget_2->addTab(tab_6, QString());

        gridLayout_6->addWidget(tabWidget_2, 0, 0, 1, 1);

        tabWidget_3 = new QTabWidget(middle_widget);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        horizontalLayout_2 = new QHBoxLayout(tab_7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(tab_7);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_12 = new QGridLayout(widget);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        recover_button = new QPushButton(widget);
        recover_button->setObjectName(QString::fromUtf8("recover_button"));

        gridLayout_12->addWidget(recover_button, 2, 1, 1, 1);

        close_venting_button = new QPushButton(widget);
        close_venting_button->setObjectName(QString::fromUtf8("close_venting_button"));

        gridLayout_12->addWidget(close_venting_button, 1, 1, 1, 1);

        abort_button = new QPushButton(widget);
        abort_button->setObjectName(QString::fromUtf8("abort_button"));
        abort_button->setStyleSheet(QString::fromUtf8("color: rgb(204, 0, 0);"));

        gridLayout_12->addWidget(abort_button, 3, 0, 1, 2);

        start_calibration_button = new QPushButton(widget);
        start_calibration_button->setObjectName(QString::fromUtf8("start_calibration_button"));

        gridLayout_12->addWidget(start_calibration_button, 2, 0, 1, 1);

        arm_button = new QPushButton(widget);
        arm_button->setObjectName(QString::fromUtf8("arm_button"));
        arm_button->setStyleSheet(QString::fromUtf8(""));

        gridLayout_12->addWidget(arm_button, 0, 0, 1, 1);

        open_venting_button = new QPushButton(widget);
        open_venting_button->setObjectName(QString::fromUtf8("open_venting_button"));

        gridLayout_12->addWidget(open_venting_button, 1, 0, 1, 1);

        disarm_button = new QPushButton(widget);
        disarm_button->setObjectName(QString::fromUtf8("disarm_button"));

        gridLayout_12->addWidget(disarm_button, 0, 1, 1, 1);


        horizontalLayout_2->addWidget(widget);

        tabWidget_3->addTab(tab_7, QString());
        tab_tvc = new QWidget();
        tab_tvc->setObjectName(QString::fromUtf8("tab_tvc"));
        horizontalLayout_21 = new QHBoxLayout(tab_tvc);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        widget1 = new QWidget(tab_tvc);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        gridLayout_121 = new QGridLayout(widget1);
        gridLayout_121->setObjectName(QString::fromUtf8("gridLayout_121"));
        tvc_shutdown_button = new QPushButton(widget1);
        tvc_shutdown_button->setObjectName(QString::fromUtf8("tvc_shutdown_button"));

        gridLayout_121->addWidget(tvc_shutdown_button, 0, 1, 1, 1);

        tvc_abort_button = new QPushButton(widget1);
        tvc_abort_button->setObjectName(QString::fromUtf8("tvc_abort_button"));

        gridLayout_121->addWidget(tvc_abort_button, 1, 0, 1, 1);

        tvc_recover_button = new QPushButton(widget1);
        tvc_recover_button->setObjectName(QString::fromUtf8("tvc_recover_button"));

        gridLayout_121->addWidget(tvc_recover_button, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_121->addItem(verticalSpacer, 2, 0, 1, 1);

        tvc_boot_button = new QPushButton(widget1);
        tvc_boot_button->setObjectName(QString::fromUtf8("tvc_boot_button"));
        tvc_boot_button->setStyleSheet(QString::fromUtf8(""));

        gridLayout_121->addWidget(tvc_boot_button, 0, 0, 1, 1);

        tvc_status_panel = new QLabel(widget1);
        tvc_status_panel->setObjectName(QString::fromUtf8("tvc_status_panel"));

        gridLayout_121->addWidget(tvc_status_panel, 3, 1, 1, 1);

        label_33 = new QLabel(widget1);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_121->addWidget(label_33, 3, 0, 1, 1);

        label_34 = new QLabel(widget1);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_121->addWidget(label_34, 4, 0, 1, 1);

        tvc_rpi_status_panel = new QLabel(widget1);
        tvc_rpi_status_panel->setObjectName(QString::fromUtf8("tvc_rpi_status_panel"));

        gridLayout_121->addWidget(tvc_rpi_status_panel, 4, 1, 1, 1);


        horizontalLayout_21->addWidget(widget1);

        tabWidget_3->addTab(tab_tvc, QString());

        gridLayout_6->addWidget(tabWidget_3, 1, 0, 1, 1);


        horizontalLayout_11->addWidget(middle_widget);

        right_widget = new QWidget(Form);
        right_widget->setObjectName(QString::fromUtf8("right_widget"));
        gridLayout_9 = new QGridLayout(right_widget);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        av_states_box = new QGroupBox(right_widget);
        av_states_box->setObjectName(QString::fromUtf8("av_states_box"));
        sizePolicy1.setHeightForWidth(av_states_box->sizePolicy().hasHeightForWidth());
        av_states_box->setSizePolicy(sizePolicy1);
        gridLayout_11 = new QGridLayout(av_states_box);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        touchdown_label = new QLabel(av_states_box);
        touchdown_label->setObjectName(QString::fromUtf8("touchdown_label"));

        gridLayout_11->addWidget(touchdown_label, 8, 1, 1, 1);

        idle_state_ok_panel = new QLabel(av_states_box);
        idle_state_ok_panel->setObjectName(QString::fromUtf8("idle_state_ok_panel"));
        idle_state_ok_panel->setMinimumSize(QSize(23, 0));
        idle_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        idle_state_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        idle_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(idle_state_ok_panel, 3, 2, 1, 1);

        sleep_state_ok_panel = new QLabel(av_states_box);
        sleep_state_ok_panel->setObjectName(QString::fromUtf8("sleep_state_ok_panel"));
        sleep_state_ok_panel->setMinimumSize(QSize(23, 0));
        sleep_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        sleep_state_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        sleep_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(sleep_state_ok_panel, 1, 2, 1, 1);

        second_event_label = new QLabel(av_states_box);
        second_event_label->setObjectName(QString::fromUtf8("second_event_label"));

        gridLayout_11->addWidget(second_event_label, 7, 1, 1, 1);

        coast_label = new QLabel(av_states_box);
        coast_label->setObjectName(QString::fromUtf8("coast_label"));

        gridLayout_11->addWidget(coast_label, 5, 1, 1, 1);

        liftoff_label = new QLabel(av_states_box);
        liftoff_label->setObjectName(QString::fromUtf8("liftoff_label"));

        gridLayout_11->addWidget(liftoff_label, 4, 1, 1, 1);

        liftoff_state_ok_panel = new QLabel(av_states_box);
        liftoff_state_ok_panel->setObjectName(QString::fromUtf8("liftoff_state_ok_panel"));
        liftoff_state_ok_panel->setMinimumSize(QSize(23, 0));
        liftoff_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        liftoff_state_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        liftoff_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(liftoff_state_ok_panel, 4, 2, 1, 1);

        calibration_label = new QLabel(av_states_box);
        calibration_label->setObjectName(QString::fromUtf8("calibration_label"));
        calibration_label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_11->addWidget(calibration_label, 2, 1, 1, 1);

        sleep_label = new QLabel(av_states_box);
        sleep_label->setObjectName(QString::fromUtf8("sleep_label"));

        gridLayout_11->addWidget(sleep_label, 1, 1, 1, 1);

        touchdown_event_ok_panel = new QLabel(av_states_box);
        touchdown_event_ok_panel->setObjectName(QString::fromUtf8("touchdown_event_ok_panel"));
        touchdown_event_ok_panel->setMinimumSize(QSize(23, 0));
        touchdown_event_ok_panel->setMaximumSize(QSize(23, 16777215));
        touchdown_event_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        touchdown_event_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(touchdown_event_ok_panel, 8, 2, 1, 1);

        calibration_state_ok_panel = new QLabel(av_states_box);
        calibration_state_ok_panel->setObjectName(QString::fromUtf8("calibration_state_ok_panel"));
        calibration_state_ok_panel->setMinimumSize(QSize(23, 0));
        calibration_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        calibration_state_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        calibration_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(calibration_state_ok_panel, 2, 2, 1, 1);

        coast_state_ok_panel = new QLabel(av_states_box);
        coast_state_ok_panel->setObjectName(QString::fromUtf8("coast_state_ok_panel"));
        coast_state_ok_panel->setMinimumSize(QSize(23, 0));
        coast_state_ok_panel->setMaximumSize(QSize(23, 16777215));
        coast_state_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        coast_state_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(coast_state_ok_panel, 5, 2, 1, 1);

        second_event_ok_panel = new QLabel(av_states_box);
        second_event_ok_panel->setObjectName(QString::fromUtf8("second_event_ok_panel"));
        second_event_ok_panel->setMinimumSize(QSize(23, 0));
        second_event_ok_panel->setMaximumSize(QSize(23, 16777215));
        second_event_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        second_event_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(second_event_ok_panel, 7, 2, 1, 1);

        idle_label = new QLabel(av_states_box);
        idle_label->setObjectName(QString::fromUtf8("idle_label"));
        idle_label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_11->addWidget(idle_label, 3, 1, 1, 1);

        first_event_ok_panel = new QLabel(av_states_box);
        first_event_ok_panel->setObjectName(QString::fromUtf8("first_event_ok_panel"));
        first_event_ok_panel->setMinimumSize(QSize(23, 0));
        first_event_ok_panel->setMaximumSize(QSize(23, 16777215));
        first_event_ok_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        first_event_ok_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(first_event_ok_panel, 6, 2, 1, 1);

        first_event_label = new QLabel(av_states_box);
        first_event_label->setObjectName(QString::fromUtf8("first_event_label"));

        gridLayout_11->addWidget(first_event_label, 6, 1, 1, 1);


        gridLayout_9->addWidget(av_states_box, 5, 1, 1, 1);

        tabWidget_4 = new QTabWidget(right_widget);
        tabWidget_4->setObjectName(QString::fromUtf8("tabWidget_4"));
        tabWidget_4->setMaximumSize(QSize(999999, 16777215));
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        horizontalLayout_8 = new QHBoxLayout(tab_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        ignition_box = new QWidget(tab_8);
        ignition_box->setObjectName(QString::fromUtf8("ignition_box"));
        ignition_box->setMinimumSize(QSize(200, 203));
        gridLayout_2 = new QGridLayout(ignition_box);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ignition_button = new QPushButton(ignition_box);
        ignition_button->setObjectName(QString::fromUtf8("ignition_button"));
        ignition_button->setMinimumSize(QSize(0, 20));
        ignition_button->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(ignition_button, 0, 0, 1, 1);

        ready_ignition_panel = new QLabel(ignition_box);
        ready_ignition_panel->setObjectName(QString::fromUtf8("ready_ignition_panel"));
        ready_ignition_panel->setMinimumSize(QSize(0, 0));
        ready_ignition_panel->setMaximumSize(QSize(23, 16777215));
        ready_ignition_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        ready_ignition_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(ready_ignition_panel, 0, 1, 1, 1);

        key_1_label = new QLabel(ignition_box);
        key_1_label->setObjectName(QString::fromUtf8("key_1_label"));

        gridLayout_2->addWidget(key_1_label, 1, 0, 1, 1);

        key_1_panel = new QLabel(ignition_box);
        key_1_panel->setObjectName(QString::fromUtf8("key_1_panel"));
        key_1_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        key_1_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(key_1_panel, 1, 1, 1, 1);

        key_2_label = new QLabel(ignition_box);
        key_2_label->setObjectName(QString::fromUtf8("key_2_label"));

        gridLayout_2->addWidget(key_2_label, 2, 0, 1, 1);

        key_2_panel = new QLabel(ignition_box);
        key_2_panel->setObjectName(QString::fromUtf8("key_2_panel"));
        key_2_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        key_2_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(key_2_panel, 2, 1, 1, 1);

        red_button_label = new QLabel(ignition_box);
        red_button_label->setObjectName(QString::fromUtf8("red_button_label"));

        gridLayout_2->addWidget(red_button_label, 3, 0, 1, 1);

        red_button_panel = new QLabel(ignition_box);
        red_button_panel->setObjectName(QString::fromUtf8("red_button_panel"));
        red_button_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        red_button_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(red_button_panel, 3, 1, 1, 1);

        ignition_frame = new QFrame(ignition_box);
        ignition_frame->setObjectName(QString::fromUtf8("ignition_frame"));
        ignition_frame->setMinimumSize(QSize(0, 30));
        ignition_frame->setMaximumSize(QSize(16777215, 1999999));
        ignition_frame->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);\n"
"gridline-color: rgb(255, 0, 0);"));
        ignition_frame->setFrameShape(QFrame::WinPanel);
        ignition_frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(ignition_frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        code_3 = new QLabel(ignition_frame);
        code_3->setObjectName(QString::fromUtf8("code_3"));
        code_3->setMinimumSize(QSize(21, 21));
        code_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_3);

        code_2 = new QLabel(ignition_frame);
        code_2->setObjectName(QString::fromUtf8("code_2"));
        code_2->setMinimumSize(QSize(21, 21));
        code_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_2);

        code_1 = new QLabel(ignition_frame);
        code_1->setObjectName(QString::fromUtf8("code_1"));
        code_1->setMinimumSize(QSize(21, 21));
        code_1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_1);

        code_0 = new QLabel(ignition_frame);
        code_0->setObjectName(QString::fromUtf8("code_0"));
        code_0->setMinimumSize(QSize(21, 21));
        code_0->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(code_0);


        gridLayout_2->addWidget(ignition_frame, 4, 0, 1, 2);


        horizontalLayout_8->addWidget(ignition_box);

        tabWidget_4->addTab(tab_8, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        horizontalLayout_9 = new QHBoxLayout(tab_10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        widget_7 = new QWidget(tab_10);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        sizePolicy1.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy1);
        gridLayout_16 = new QGridLayout(widget_7);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(-1, -1, 9, -1);
        label_19 = new QLabel(widget_7);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_16->addWidget(label_19, 9, 0, 1, 1);

        main_current_panel = new QLabel(widget_7);
        main_current_panel->setObjectName(QString::fromUtf8("main_current_panel"));
        main_current_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(main_current_panel, 5, 1, 1, 1);

        kg_label_2 = new QLabel(widget_7);
        kg_label_2->setObjectName(QString::fromUtf8("kg_label_2"));
        kg_label_2->setMaximumSize(QSize(40, 16777215));
        kg_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(kg_label_2, 3, 2, 1, 1);

        hose_pressure_label_2 = new QLabel(widget_7);
        hose_pressure_label_2->setObjectName(QString::fromUtf8("hose_pressure_label_2"));

        gridLayout_16->addWidget(hose_pressure_label_2, 1, 0, 1, 1);

        label_10 = new QLabel(widget_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setLayoutDirection(Qt::RightToLeft);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_10, 7, 2, 1, 1);

        hose_pressure_panel_2 = new QLabel(widget_7);
        hose_pressure_panel_2->setObjectName(QString::fromUtf8("hose_pressure_panel_2"));
        hose_pressure_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(hose_pressure_panel_2, 1, 1, 1, 1);

        secondary_disconnect_current_panel = new QLabel(widget_7);
        secondary_disconnect_current_panel->setObjectName(QString::fromUtf8("secondary_disconnect_current_panel"));
        secondary_disconnect_current_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(secondary_disconnect_current_panel, 8, 1, 1, 1);

        rocket_weight_label_2 = new QLabel(widget_7);
        rocket_weight_label_2->setObjectName(QString::fromUtf8("rocket_weight_label_2"));

        gridLayout_16->addWidget(rocket_weight_label_2, 3, 0, 1, 1);

        voltunit_label = new QLabel(widget_7);
        voltunit_label->setObjectName(QString::fromUtf8("voltunit_label"));
        voltunit_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(voltunit_label, 4, 2, 1, 1);

        battery_level_panel = new QLabel(widget_7);
        battery_level_panel->setObjectName(QString::fromUtf8("battery_level_panel"));
        battery_level_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(battery_level_panel, 4, 1, 1, 1);

        hoes_temp_label_2 = new QLabel(widget_7);
        hoes_temp_label_2->setObjectName(QString::fromUtf8("hoes_temp_label_2"));

        gridLayout_16->addWidget(hoes_temp_label_2, 2, 0, 1, 1);

        label_22 = new QLabel(widget_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_22, 8, 2, 1, 1);

        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_16->addWidget(label_4, 7, 0, 1, 1);

        m_a_unit_label = new QLabel(widget_7);
        m_a_unit_label->setObjectName(QString::fromUtf8("m_a_unit_label"));
        m_a_unit_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(m_a_unit_label, 5, 2, 1, 1);

        ma_unit_label = new QLabel(widget_7);
        ma_unit_label->setObjectName(QString::fromUtf8("ma_unit_label"));
        ma_unit_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(ma_unit_label, 6, 2, 1, 1);

        main_current_label = new QLabel(widget_7);
        main_current_label->setObjectName(QString::fromUtf8("main_current_label"));

        gridLayout_16->addWidget(main_current_label, 5, 0, 1, 1);

        rocket_weight_panel_2 = new QLabel(widget_7);
        rocket_weight_panel_2->setObjectName(QString::fromUtf8("rocket_weight_panel_2"));
        rocket_weight_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(rocket_weight_panel_2, 3, 1, 1, 1);

        purge_valve_current_label = new QLabel(widget_7);
        purge_valve_current_label->setObjectName(QString::fromUtf8("purge_valve_current_label"));
        purge_valve_current_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(purge_valve_current_label, 10, 1, 1, 1);

        wind_speed_panel = new QLabel(widget_7);
        wind_speed_panel->setObjectName(QString::fromUtf8("wind_speed_panel"));
        wind_speed_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(wind_speed_panel, 11, 1, 1, 1);

        m_s_unit_label_2 = new QLabel(widget_7);
        m_s_unit_label_2->setObjectName(QString::fromUtf8("m_s_unit_label_2"));
        m_s_unit_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(m_s_unit_label_2, 11, 2, 1, 1);

        label_25 = new QLabel(widget_7);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_25, 10, 2, 1, 1);

        label_11 = new QLabel(widget_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_16->addWidget(label_11, 11, 0, 1, 1);

        tank_temp_label_2 = new QLabel(widget_7);
        tank_temp_label_2->setObjectName(QString::fromUtf8("tank_temp_label_2"));

        gridLayout_16->addWidget(tank_temp_label_2, 0, 0, 1, 1);

        label_23 = new QLabel(widget_7);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_23, 9, 2, 1, 1);

        celcius_label_3 = new QLabel(widget_7);
        celcius_label_3->setObjectName(QString::fromUtf8("celcius_label_3"));
        celcius_label_3->setMaximumSize(QSize(40, 16777215));
        celcius_label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(celcius_label_3, 2, 2, 1, 1);

        label_17 = new QLabel(widget_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_16->addWidget(label_17, 8, 0, 1, 1);

        tank_temp_panel_2 = new QLabel(widget_7);
        tank_temp_panel_2->setObjectName(QString::fromUtf8("tank_temp_panel_2"));
        tank_temp_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(tank_temp_panel_2, 0, 1, 1, 1);

        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_16->addWidget(label_8, 6, 0, 1, 1);

        celcius_label2_2 = new QLabel(widget_7);
        celcius_label2_2->setObjectName(QString::fromUtf8("celcius_label2_2"));
        celcius_label2_2->setMaximumSize(QSize(40, 16777215));
        celcius_label2_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(celcius_label2_2, 0, 2, 1, 1);

        label_21 = new QLabel(widget_7);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_16->addWidget(label_21, 10, 0, 1, 1);

        hose_temp_panel_2 = new QLabel(widget_7);
        hose_temp_panel_2->setObjectName(QString::fromUtf8("hose_temp_panel_2"));
        hose_temp_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(hose_temp_panel_2, 2, 1, 1, 1);

        battery_level_label = new QLabel(widget_7);
        battery_level_label->setObjectName(QString::fromUtf8("battery_level_label"));

        gridLayout_16->addWidget(battery_level_label, 4, 0, 1, 1);

        fill_valve_current_label = new QLabel(widget_7);
        fill_valve_current_label->setObjectName(QString::fromUtf8("fill_valve_current_label"));
        fill_valve_current_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(fill_valve_current_label, 9, 1, 1, 1);

        secondary_current_panel = new QLabel(widget_7);
        secondary_current_panel->setObjectName(QString::fromUtf8("secondary_current_panel"));
        secondary_current_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(secondary_current_panel, 6, 1, 1, 1);

        hpa_panel_2 = new QLabel(widget_7);
        hpa_panel_2->setObjectName(QString::fromUtf8("hpa_panel_2"));
        hpa_panel_2->setMinimumSize(QSize(43, 0));
        hpa_panel_2->setMaximumSize(QSize(40, 16777215));
        hpa_panel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(hpa_panel_2, 1, 2, 1, 1);

        main_disconnect_current_panel = new QLabel(widget_7);
        main_disconnect_current_panel->setObjectName(QString::fromUtf8("main_disconnect_current_panel"));
        main_disconnect_current_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(main_disconnect_current_panel, 7, 1, 1, 1);


        horizontalLayout_9->addWidget(widget_7);

        tabWidget_4->addTab(tab_10, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        horizontalLayout_7 = new QHBoxLayout(tab_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        gse_control_box = new QWidget(tab_9);
        gse_control_box->setObjectName(QString::fromUtf8("gse_control_box"));
        gridLayout_15 = new QGridLayout(gse_control_box);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        filling_open_button = new QPushButton(gse_control_box);
        filling_open_button->setObjectName(QString::fromUtf8("filling_open_button"));
        filling_open_button->setStyleSheet(QString::fromUtf8(""));

        gridLayout_15->addWidget(filling_open_button, 0, 1, 1, 1);

        purge_label = new QLabel(gse_control_box);
        purge_label->setObjectName(QString::fromUtf8("purge_label"));

        gridLayout_15->addWidget(purge_label, 1, 0, 1, 1);

        label_2 = new QLabel(gse_control_box);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_15->addWidget(label_2, 2, 0, 1, 1);

        echo_button = new QPushButton(gse_control_box);
        echo_button->setObjectName(QString::fromUtf8("echo_button"));

        gridLayout_15->addWidget(echo_button, 3, 0, 1, 1);

        disconnect_on_button = new QPushButton(gse_control_box);
        disconnect_on_button->setObjectName(QString::fromUtf8("disconnect_on_button"));

        gridLayout_15->addWidget(disconnect_on_button, 2, 1, 1, 1);

        purge_close_button = new QPushButton(gse_control_box);
        purge_close_button->setObjectName(QString::fromUtf8("purge_close_button"));

        gridLayout_15->addWidget(purge_close_button, 1, 2, 1, 1);

        filling_label = new QLabel(gse_control_box);
        filling_label->setObjectName(QString::fromUtf8("filling_label"));
        filling_label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_15->addWidget(filling_label, 0, 0, 1, 1);

        ignition_off_button = new QPushButton(gse_control_box);
        ignition_off_button->setObjectName(QString::fromUtf8("ignition_off_button"));

        gridLayout_15->addWidget(ignition_off_button, 3, 1, 1, 2);

        filling_close_button = new QPushButton(gse_control_box);
        filling_close_button->setObjectName(QString::fromUtf8("filling_close_button"));

        gridLayout_15->addWidget(filling_close_button, 0, 2, 1, 1);

        disconnect_off_button = new QPushButton(gse_control_box);
        disconnect_off_button->setObjectName(QString::fromUtf8("disconnect_off_button"));

        gridLayout_15->addWidget(disconnect_off_button, 2, 2, 1, 1);

        purge_open_button = new QPushButton(gse_control_box);
        purge_open_button->setObjectName(QString::fromUtf8("purge_open_button"));

        gridLayout_15->addWidget(purge_open_button, 1, 1, 1, 1);


        horizontalLayout_7->addWidget(gse_control_box);

        tabWidget_4->addTab(tab_9, QString());
        lcs_tab = new QWidget();
        lcs_tab->setObjectName(QString::fromUtf8("lcs_tab"));
        horizontalLayout_71 = new QHBoxLayout(lcs_tab);
        horizontalLayout_71->setObjectName(QString::fromUtf8("horizontalLayout_71"));
        lcs_container = new QWidget(lcs_tab);
        lcs_container->setObjectName(QString::fromUtf8("lcs_container"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lcs_container->sizePolicy().hasHeightForWidth());
        lcs_container->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(lcs_container);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lcs_button = new QCheckBox(lcs_container);
        lcs_button->setObjectName(QString::fromUtf8("lcs_button"));
        lcs_button->setEnabled(true);
        sizePolicy.setHeightForWidth(lcs_button->sizePolicy().hasHeightForWidth());
        lcs_button->setSizePolicy(sizePolicy);
        lcs_button->setTabletTracking(false);
        lcs_button->setFocusPolicy(Qt::NoFocus);
        lcs_button->setAutoFillBackground(false);
        lcs_button->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	min-width: 100%;\n"
"	min-height:100%;\n"
"	spacing: 0;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"	width:180%;\n"
"	height: 180%;\n"
"	spacing: 0;\n"
"    subcontrol-position: center;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:\n"
"0.5, fx:0.5, fy:0.5, \n"
"stop:0 rgba(235, 0, 0, 255), \n"
"stop:0.999 rgba(235,0,0,255),\n"
"stop:0.9999 rgba(235,0,0,0));\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover {\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:\n"
"0.5, fx:0.5, fy:0.5, \n"
"stop:0 rgba(255, 0, 0, 255), \n"
"stop:0.999 rgba(255,0,0,235),\n"
"stop:0.9999 rgba(255,0,0,0));\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:pressed {\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:\n"
"0.5, fx:0.5, fy:0.5, \n"
"stop:0 rgba(200, 0, 0, 255), \n"
"stop:0.999 rgba(200,0,0,235),\n"
"stop:0.9999 rgba(200,0,0,0));\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"background"
                        "-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:\n"
"0.5, fx:0.5, fy:0.5, \n"
"stop:0 rgba(120, 0, 0, 255), \n"
"stop:0.999 rgba(120,0,0,235),\n"
"stop:0.9999 rgba(120,0,0,0));\n"
"}"));
        lcs_button->setCheckable(true);
        lcs_button->setChecked(false);
        lcs_button->setTristate(false);

        verticalLayout_2->addWidget(lcs_button);

        lcs_check_container = new QWidget(lcs_container);
        lcs_check_container->setObjectName(QString::fromUtf8("lcs_check_container"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lcs_check_container->sizePolicy().hasHeightForWidth());
        lcs_check_container->setSizePolicy(sizePolicy4);
        horizontalLayout_12 = new QHBoxLayout(lcs_check_container);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(10, -1, 10, -1);
        lcs_check_1 = new QCheckBox(lcs_check_container);
        lcs_check_1->setObjectName(QString::fromUtf8("lcs_check_1"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lcs_check_1->sizePolicy().hasHeightForWidth());
        lcs_check_1->setSizePolicy(sizePolicy5);
        lcs_check_1->setMinimumSize(QSize(30, 30));
        lcs_check_1->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"	width: 50%;\n"
"	height:50%;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(100, 0, 0), stop:0.4 rgba(55, 0, 0, 255), stop:0.5 rgba(55,0,0,200), stop:0.55 rgba(55, 0, 0, 0));\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(255, 100, 100), stop:0.4 rgba(255, 0, 0, 255), stop:0.5 rgba(255,0,0,255), stop:0.7 rgba(255, 158, 158, 0));\n"
"}"));
        lcs_check_1->setIconSize(QSize(0, 0));
        lcs_check_1->setChecked(false);
        lcs_check_1->setTristate(false);

        horizontalLayout_12->addWidget(lcs_check_1, 0, Qt::AlignHCenter);

        lcs_check_2 = new QCheckBox(lcs_check_container);
        lcs_check_2->setObjectName(QString::fromUtf8("lcs_check_2"));
        lcs_check_2->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"	width: 50%;\n"
"	height:50%;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(100, 0, 0), stop:0.4 rgba(55, 0, 0, 255), stop:0.5 rgba(55,0,0,200), stop:0.55 rgba(55, 0, 0, 0));\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(255, 100, 100), stop:0.4 rgba(255, 0, 0, 255), stop:0.5 rgba(255,0,0,255), stop:0.7 rgba(255, 158, 158, 0));\n"
"}"));

        horizontalLayout_12->addWidget(lcs_check_2, 0, Qt::AlignHCenter);

        lcs_check_3 = new QCheckBox(lcs_check_container);
        lcs_check_3->setObjectName(QString::fromUtf8("lcs_check_3"));
        sizePolicy.setHeightForWidth(lcs_check_3->sizePolicy().hasHeightForWidth());
        lcs_check_3->setSizePolicy(sizePolicy);
        lcs_check_3->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"	width: 50%;\n"
"	height:50%;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(100, 0, 0), stop:0.4 rgba(55, 0, 0, 255), stop:0.5 rgba(55,0,0,200), stop:0.55 rgba(55, 0, 0, 0));\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(255, 100, 100), stop:0.4 rgba(255, 0, 0, 255), stop:0.5 rgba(255,0,0,255), stop:0.7 rgba(255, 158, 158, 0));\n"
"}"));
        lcs_check_3->setChecked(false);

        horizontalLayout_12->addWidget(lcs_check_3, 0, Qt::AlignHCenter);

        lcs_check_4 = new QCheckBox(lcs_check_container);
        lcs_check_4->setObjectName(QString::fromUtf8("lcs_check_4"));
        lcs_check_4->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"	width: 50%;\n"
"	height:50%;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(100, 0, 0), stop:0.4 rgba(55, 0, 0, 255), stop:0.5 rgba(55,0,0,200), stop:0.55 rgba(55, 0, 0, 0));\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgb(255, 100, 100), stop:0.4 rgba(255, 0, 0, 255), stop:0.5 rgba(255,0,0,255), stop:0.7 rgba(255, 158, 158, 0));\n"
"}"));
        lcs_check_4->setChecked(false);

        horizontalLayout_12->addWidget(lcs_check_4, 0, Qt::AlignHCenter);


        verticalLayout_2->addWidget(lcs_check_container);


        horizontalLayout_71->addWidget(lcs_container);

        tabWidget_4->addTab(lcs_tab, QString());

        gridLayout_9->addWidget(tabWidget_4, 4, 0, 1, 4);

        upper_widget = new QWidget(right_widget);
        upper_widget->setObjectName(QString::fromUtf8("upper_widget"));
        upper_widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_5 = new QGridLayout(upper_widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        manual_mode_button = new QPushButton(upper_widget);
        manual_mode_button->setObjectName(QString::fromUtf8("manual_mode_button"));
        manual_mode_button->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(manual_mode_button, 0, 1, 1, 1);

        dbm_label = new QLabel(upper_widget);
        dbm_label->setObjectName(QString::fromUtf8("dbm_label"));
        dbm_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(dbm_label, 2, 3, 1, 1);

        rssi_panel = new QLCDNumber(upper_widget);
        rssi_panel->setObjectName(QString::fromUtf8("rssi_panel"));

        gridLayout_5->addWidget(rssi_panel, 2, 2, 1, 1);

        time_panel = new QLabel(upper_widget);
        time_panel->setObjectName(QString::fromUtf8("time_panel"));
        time_panel->setMinimumSize(QSize(0, 0));
        time_panel->setMaximumSize(QSize(999999, 16777215));
        time_panel->setStyleSheet(QString::fromUtf8(""));
        time_panel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(time_panel, 0, 2, 1, 2);

        request_rssi = new QPushButton(upper_widget);
        request_rssi->setObjectName(QString::fromUtf8("request_rssi"));
        request_rssi->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(request_rssi, 2, 1, 1, 1);


        gridLayout_9->addWidget(upper_widget, 0, 0, 1, 3);

        tabWidget = new QTabWidget(right_widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMaximumSize(QSize(9999999, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_13 = new QGridLayout(tab);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        logo = new QLabel(tab);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setStyleSheet(QString::fromUtf8("\n"
"\n"
"image: url(:/assets/logo.png);"));

        gridLayout_13->addWidget(logo, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_14 = new QGridLayout(tab_2);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serial_status_label = new QLabel(widget_2);
        serial_status_label->setObjectName(QString::fromUtf8("serial_status_label"));
        serial_status_label->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(serial_status_label, 0, 0, 1, 1);

        reset_button = new QPushButton(widget_2);
        reset_button->setObjectName(QString::fromUtf8("reset_button"));
        reset_button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(reset_button, 3, 0, 1, 2);

        xbee_button = new QPushButton(widget_2);
        xbee_button->setObjectName(QString::fromUtf8("xbee_button"));
        xbee_button->setMinimumSize(QSize(0, 0));
        xbee_button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(xbee_button, 2, 0, 1, 2);

        serialport_selector = new QComboBox(widget_2);
        serialport_selector->addItem(QString());
        serialport_selector->addItem(QString());
        serialport_selector->addItem(QString());
        serialport_selector->addItem(QString());
        serialport_selector->setObjectName(QString::fromUtf8("serialport_selector"));

        gridLayout->addWidget(serialport_selector, 1, 0, 1, 2);

        change_theme = new QPushButton(widget_2);
        change_theme->setObjectName(QString::fromUtf8("change_theme"));
        change_theme->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(change_theme, 4, 0, 1, 2);

        serial_status_panel = new QLabel(widget_2);
        serial_status_panel->setObjectName(QString::fromUtf8("serial_status_panel"));
        serial_status_panel->setMinimumSize(QSize(23, 0));
        serial_status_panel->setMaximumSize(QSize(23, 16777215));
        serial_status_panel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"color: rgb(0, 255, 255);"));
        serial_status_panel->setFrameShape(QFrame::NoFrame);
        serial_status_panel->setLineWidth(1);
        serial_status_panel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(serial_status_panel, 0, 1, 1, 1);


        gridLayout_14->addWidget(widget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_9->addWidget(tabWidget, 5, 2, 1, 1);

        upper_widget_2 = new QWidget(right_widget);
        upper_widget_2->setObjectName(QString::fromUtf8("upper_widget_2"));
        sizePolicy.setHeightForWidth(upper_widget_2->sizePolicy().hasHeightForWidth());
        upper_widget_2->setSizePolicy(sizePolicy);
        upper_widget_2->setMaximumSize(QSize(16777215, 16777215));
        upper_widget_2->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_19 = new QHBoxLayout(upper_widget_2);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        gse_launch_ack_label = new QLabel(upper_widget_2);
        gse_launch_ack_label->setObjectName(QString::fromUtf8("gse_launch_ack_label"));
        gse_launch_ack_label->setStyleSheet(QString::fromUtf8("color:red;"));
        gse_launch_ack_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(gse_launch_ack_label);


        gridLayout_9->addWidget(upper_widget_2, 2, 1, 1, 2);


        horizontalLayout_11->addWidget(right_widget);


        retranslateUi(Form);

        tabWidget_5->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(3);
        tabWidget_3->setCurrentIndex(1);
        tabWidget_4->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "GSBellaLui2020", nullptr));
        com_box->setTitle(QCoreApplication::translate("Form", "COM", nullptr));
#if QT_CONFIG(tooltip)
        packets_second_label->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        packets_second_label->setText(QCoreApplication::translate("Form", "Total Rx Packet rate", nullptr));
#if QT_CONFIG(tooltip)
        packets_second_bar->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        packets_second_bar->setFormat(QCoreApplication::translate("Form", "%v", nullptr));
        last_datagram_id->setText(QCoreApplication::translate("Form", "AV Rx Packet rate", nullptr));
#if QT_CONFIG(tooltip)
        av_packets_second_bar->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        av_packets_second_bar->setFormat(QCoreApplication::translate("Form", "%v", nullptr));
#if QT_CONFIG(tooltip)
        pl_packet_label->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The last received packet's number (defined by TX)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pl_packet_label->setText(QCoreApplication::translate("Form", "PL Rx Packet rate", nullptr));
#if QT_CONFIG(tooltip)
        pl_packets_second_bar->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pl_packets_second_bar->setFormat(QCoreApplication::translate("Form", "%v", nullptr));
        gse_packet_label->setText(QCoreApplication::translate("Form", "GSE Rx Packet rate", nullptr));
#if QT_CONFIG(tooltip)
        gse_packets_second_bar->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        gse_packets_second_bar->setFormat(QCoreApplication::translate("Form", "%v", nullptr));
        pp_packets_second_label->setText(QCoreApplication::translate("Form", "PP Rx Packet rate", nullptr));
#if QT_CONFIG(tooltip)
        pp_packets_second_bar->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The number of packets received in last second</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pp_packets_second_bar->setFormat(QCoreApplication::translate("Form", "%v", nullptr));
#if QT_CONFIG(tooltip)
        received_pack_cnt_label->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        received_pack_cnt_label->setText(QCoreApplication::translate("Form", "Total packets", nullptr));
#if QT_CONFIG(tooltip)
        received_pack_cnt_panel->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>The count of the received packets from the start of the program</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        received_pack_cnt_panel->setText(QString());
        time_since_last_label->setText(QCoreApplication::translate("Form", "Time since last packet", nullptr));
        time_since_last_panel->setText(QString());
        corrupted_label->setText(QCoreApplication::translate("Form", "Corrupted Packets", nullptr));
        corrupted_panel->setText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("Form", "Altitude", nullptr));
        altitude_label_gps->setText(QCoreApplication::translate("Form", "ALTITUDE", nullptr));
        ft_unit_label_2->setText(QCoreApplication::translate("Form", "ft", nullptr));
        m_unit_label_2->setText(QCoreApplication::translate("Form", "m", nullptr));
        altitude_max_label->setText(QCoreApplication::translate("Form", "ALTITUDE MAX", nullptr));
        m_unit_label->setText(QCoreApplication::translate("Form", "m", nullptr));
        ft_unit_label->setText(QCoreApplication::translate("Form", "ft", nullptr));
        gps_box->setTitle(QCoreApplication::translate("Form", "GPS", nullptr));
        longitude_label->setText(QCoreApplication::translate("Form", "LONG.", nullptr));
        hdop_label->setText(QCoreApplication::translate("Form", "HDOP", nullptr));
        latitude_panel->setText(QString());
        sat_nbr_label->setText(QCoreApplication::translate("Form", "SAT.NO", nullptr));
        sat_nbr_panel->setText(QString());
        latitude_label->setText(QCoreApplication::translate("Form", "LAT.", nullptr));
        longitude_panel->setText(QString());
        hdop_panel->setText(QString());
        avionics_box->setTitle(QCoreApplication::translate("Form", "Avionics Data", nullptr));
        temperature_panel->setText(QString());
        m_unit_label_3->setText(QCoreApplication::translate("Form", "[m]", nullptr));
        pressure_label->setText(QCoreApplication::translate("Form", "PRESS.", nullptr));
        altitude_label_telemetry->setText(QCoreApplication::translate("Form", "ALT.", nullptr));
        speed_panel->setText(QString());
        avionics_state_panel->setText(QString());
        speed_label->setText(QCoreApplication::translate("Form", "SPEED", nullptr));
        avionics_state_label->setText(QCoreApplication::translate("Form", "AV. STATE", nullptr));
        temperature_label->setText(QCoreApplication::translate("Form", "TEMP", nullptr));
        celcius_label->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", nullptr));
        pressure_panel->setText(QString());
        m_s_unit_label->setText(QCoreApplication::translate("Form", "[m/s]", nullptr));
        hpa_unit_label->setText(QCoreApplication::translate("Form", "[hPa]", nullptr));
        altitude_panel_telemetry->setText(QString());
        euler_z_label->setText(QCoreApplication::translate("Form", "Z", nullptr));
        euler_y_label->setText(QCoreApplication::translate("Form", "Y", nullptr));
        euler_x_label->setText(QCoreApplication::translate("Form", "X", nullptr));
        euler_x_panel->setText(QString());
        euler_y_panel->setText(QString());
        euler_z_panel->setText(QString());
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_12), QCoreApplication::translate("Form", "Angles", nullptr));
        accel_x_panel->setText(QString());
        accel_x_label->setText(QCoreApplication::translate("Form", "X", nullptr));
        accel_z_panel->setText(QString());
        accel_z_label->setText(QCoreApplication::translate("Form", "Z", nullptr));
        accel_y_label->setText(QCoreApplication::translate("Form", "Y", nullptr));
        accel_y_panel->setText(QString());
        norm_panel->setText(QString());
        norm_label->setText(QCoreApplication::translate("Form", "Norm", nullptr));
        tabWidget_5->setTabText(tabWidget_5->indexOf(tab_11), QCoreApplication::translate("Form", "Accel.", nullptr));
        gse_state_box->setTitle(QCoreApplication::translate("Form", "GSE States", nullptr));
        label_28->setText(QCoreApplication::translate("Form", "Secondary disconnect", nullptr));
        purge_valve_state_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        hose_disconnect_label->setText(QCoreApplication::translate("Form", "Main disconnect", nullptr));
        secondary_ignition_label->setText(QCoreApplication::translate("Form", "Secondary Ignition", nullptr));
        secondary_disconnect_state_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        main_disconnect_state_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        main_ignition_state_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        secondary_ignition_state_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        main_ignition_label->setText(QCoreApplication::translate("Form", "Main Ignition", nullptr));
        purge_valve_label->setText(QCoreApplication::translate("Form", "Purge Valve", nullptr));
        fill_valve_label->setText(QCoreApplication::translate("Form", "Fill Valve", nullptr));
        fill_valve_state_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        pl_bme_humidity_label->setText(QCoreApplication::translate("Form", "Humidity", nullptr));
        pl_bme_temperature_label->setText(QCoreApplication::translate("Form", "Temperature", nullptr));
        pl_bme_pressure_label->setText(QCoreApplication::translate("Form", "Pressure", nullptr));
        pl_bme_temperature_panel->setText(QString());
        pl_bme_altitude_label->setText(QCoreApplication::translate("Form", "Altitude", nullptr));
        pl_bme_altitude_panel->setText(QString());
        pl_bme_humidity_panel->setText(QString());
        pl_bme_pressure_panel->setText(QString());
        pl_celcius_label_2->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[\302\260C]</p></body></html>", nullptr));
        pl_hpa_label->setText(QCoreApplication::translate("Form", "[hPa]", nullptr));
        pl_percentage_label->setText(QCoreApplication::translate("Form", "%", nullptr));
        pl_m_label->setText(QCoreApplication::translate("Form", "[m]", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("Form", "PL BME", nullptr));
        pl_latitude_label->setText(QCoreApplication::translate("Form", "Latitude", nullptr));
        pl_sat_nbr_panel->setText(QString());
        pl_latitude_panel->setText(QString());
        pl_satellites_label->setText(QCoreApplication::translate("Form", "Satellites", nullptr));
        pl_longitude_label->setText(QCoreApplication::translate("Form", "Longitude", nullptr));
        pl_longitude_panel->setText(QString());
        pl_gps_altitude_label->setText(QCoreApplication::translate("Form", "Altitude", nullptr));
        pl_gps_altitude_panel->setText(QString());
        pl_hdop_label->setText(QCoreApplication::translate("Form", "HDOP", nullptr));
        pl_hdop_panel->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("Form", "PL GPS", nullptr));
        pl_bno_az_panel->setText(QString());
        pl_bno_oy_label->setText(QCoreApplication::translate("Form", "Oy", nullptr));
        pl_bno_ox_panel->setText(QString());
        pl_bno_ax_panel->setText(QString());
        pl_bno_oz_label->setText(QCoreApplication::translate("Form", "Oz", nullptr));
        pl_bno_ax_label->setText(QCoreApplication::translate("Form", "Ax", nullptr));
        pl_bno_ay_label->setText(QCoreApplication::translate("Form", "Ay", nullptr));
        pl_bno_az_label->setText(QCoreApplication::translate("Form", "Az", nullptr));
        pl_bno_ay_panel->setText(QString());
        pl_bno_oy_panel->setText(QString());
        pl_bno_temperature_label->setText(QCoreApplication::translate("Form", "Temp.", nullptr));
        pl_bno_temperature_panel->setText(QString());
        pl_bno_oz_panel->setText(QString());
        deg_label_2->setText(QCoreApplication::translate("Form", "[deg]", nullptr));
        deg_label_3->setText(QCoreApplication::translate("Form", "[deg]", nullptr));
        deg_label->setText(QCoreApplication::translate("Form", "[deg]", nullptr));
        pl_bno_ox_label->setText(QCoreApplication::translate("Form", "Ox", nullptr));
        ms2_label_2->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[m/s<span style=\" vertical-align:super;\">2</span>]</p></body></html>", nullptr));
        ms2_label_3->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[m/s<span style=\" vertical-align:super;\">2</span>]</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[<span style=\" vertical-align:super;\">O</span>C]</p></body></html>", nullptr));
        ms2_label->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[m/s<span style=\" vertical-align:super;\">2</span>]</p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("Form", "PL BNO", nullptr));
        label_20->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Form", "Temp 1", nullptr));
        label_13->setText(QCoreApplication::translate("Form", "Temp 2", nullptr));
        pp_venting_panel->setText(QString());
        label_27->setText(QCoreApplication::translate("Form", "PSU Voltage", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "[Bar]", nullptr));
        pp_pressure_2_panel->setText(QString());
        label_26->setText(QCoreApplication::translate("Form", "Venting", nullptr));
        label_12->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", nullptr));
        pp_motor_position_panel->setText(QString());
        label_5->setText(QCoreApplication::translate("Form", "CC Pressure", nullptr));
        pp_status_panel->setText(QString());
        label_16->setText(QCoreApplication::translate("Form", "Motor pos", nullptr));
        pp_temperature_2_panel->setText(QString());
        label_6->setText(QCoreApplication::translate("Form", "[Bar]", nullptr));
        label_14->setText(QCoreApplication::translate("Form", "Temp 3", nullptr));
        label_15->setText(QCoreApplication::translate("Form", "Status", nullptr));
        label->setText(QCoreApplication::translate("Form", "Tank Pressure", nullptr));
        label_24->setText(QCoreApplication::translate("Form", "[deg]", nullptr));
        label_18->setText(QCoreApplication::translate("Form", "<html><head/><body><p>[<span style=\" vertical-align:super;\">o</span>C]</p></body></html>", nullptr));
        pp_temperature_1_panel->setText(QString());
        pp_temperature_3_panel->setText(QString());
        pp_pressure_1_panel->setText(QString());
        label_29->setText(QCoreApplication::translate("Form", "[V]", nullptr));
        pp_psu_voltage_panel->setText(QString());
        label_31->setText(QCoreApplication::translate("Form", "Thrurst target", nullptr));
        pp_thrust_target_panel->setText(QString());
        label_32->setText(QCoreApplication::translate("Form", "[N]", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("Form", "PP Data", nullptr));
        recover_button->setText(QCoreApplication::translate("Form", "Recover", nullptr));
        close_venting_button->setText(QCoreApplication::translate("Form", "Close Venting", nullptr));
        abort_button->setText(QCoreApplication::translate("Form", "ABORT", nullptr));
        start_calibration_button->setText(QCoreApplication::translate("Form", "Start calibration", nullptr));
        arm_button->setText(QCoreApplication::translate("Form", "Arm", nullptr));
        open_venting_button->setText(QCoreApplication::translate("Form", "Open Venting", nullptr));
        disarm_button->setText(QCoreApplication::translate("Form", "Disarm", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QCoreApplication::translate("Form", "PP Control", nullptr));
        tvc_shutdown_button->setText(QCoreApplication::translate("Form", "Shutdown", nullptr));
        tvc_abort_button->setText(QCoreApplication::translate("Form", "Abort", nullptr));
        tvc_recover_button->setText(QCoreApplication::translate("Form", "Recover", nullptr));
        tvc_boot_button->setText(QCoreApplication::translate("Form", "Boot", nullptr));
        tvc_status_panel->setText(QString());
        label_33->setText(QCoreApplication::translate("Form", "HB Status", nullptr));
        label_34->setText(QCoreApplication::translate("Form", "RPi Status", nullptr));
        tvc_rpi_status_panel->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_tvc), QCoreApplication::translate("Form", "TVC Control", nullptr));
        av_states_box->setTitle(QCoreApplication::translate("Form", "AV States", nullptr));
        touchdown_label->setText(QCoreApplication::translate("Form", "Touchdown", nullptr));
        idle_state_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        sleep_state_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        second_event_label->setText(QCoreApplication::translate("Form", "2nd Event", nullptr));
        coast_label->setText(QCoreApplication::translate("Form", "Coast", nullptr));
        liftoff_label->setText(QCoreApplication::translate("Form", "Lift off", nullptr));
        liftoff_state_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        calibration_label->setText(QCoreApplication::translate("Form", "Calibration", nullptr));
        sleep_label->setText(QCoreApplication::translate("Form", "Sleep", nullptr));
        touchdown_event_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        calibration_state_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        coast_state_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        second_event_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        idle_label->setText(QCoreApplication::translate("Form", "IDLE", nullptr));
        first_event_ok_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        first_event_label->setText(QCoreApplication::translate("Form", "1st Event", nullptr));
        ignition_button->setText(QCoreApplication::translate("Form", "Ready For Ignition", nullptr));
        ready_ignition_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        key_1_label->setText(QCoreApplication::translate("Form", "KEY 1", nullptr));
        key_1_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        key_2_label->setText(QCoreApplication::translate("Form", "KEY 2", nullptr));
        key_2_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        red_button_label->setText(QCoreApplication::translate("Form", "Red Button", nullptr));
        red_button_panel->setText(QCoreApplication::translate("Form", "X", nullptr));
        code_3->setText(QString());
        code_2->setText(QString());
        code_1->setText(QString());
        code_0->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_8), QCoreApplication::translate("Form", "Ignition", nullptr));
        label_19->setText(QCoreApplication::translate("Form", "Fill valve current", nullptr));
        main_current_panel->setText(QString());
        kg_label_2->setText(QCoreApplication::translate("Form", "[kg]", nullptr));
        hose_pressure_label_2->setText(QCoreApplication::translate("Form", "Hose Pressure", nullptr));
        label_10->setText(QCoreApplication::translate("Form", " [A]", nullptr));
        hose_pressure_panel_2->setText(QString());
        secondary_disconnect_current_panel->setText(QString());
        rocket_weight_label_2->setText(QCoreApplication::translate("Form", "Rocket Weight", nullptr));
        voltunit_label->setText(QCoreApplication::translate("Form", "[V]", nullptr));
        battery_level_panel->setText(QString());
        hoes_temp_label_2->setText(QCoreApplication::translate("Form", "Hose Temp", nullptr));
        label_22->setText(QCoreApplication::translate("Form", " [A]", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Main disconnect current", nullptr));
        m_a_unit_label->setText(QCoreApplication::translate("Form", "[A]", nullptr));
        ma_unit_label->setText(QCoreApplication::translate("Form", "[A]", nullptr));
        main_current_label->setText(QCoreApplication::translate("Form", "Main ignition current", nullptr));
        rocket_weight_panel_2->setText(QString());
        purge_valve_current_label->setText(QString());
        wind_speed_panel->setText(QString());
        m_s_unit_label_2->setText(QCoreApplication::translate("Form", "[m/s]", nullptr));
        label_25->setText(QCoreApplication::translate("Form", " [A]", nullptr));
        label_11->setText(QCoreApplication::translate("Form", "Wind speed", nullptr));
        tank_temp_label_2->setText(QCoreApplication::translate("Form", "Tank Temp", nullptr));
        label_23->setText(QCoreApplication::translate("Form", " [A]", nullptr));
        celcius_label_3->setText(QCoreApplication::translate("Form", "[\302\260C]", nullptr));
        label_17->setText(QCoreApplication::translate("Form", "Secondary disconnect current", nullptr));
        tank_temp_panel_2->setText(QString());
        label_8->setText(QCoreApplication::translate("Form", "Secondary ignition current", nullptr));
        celcius_label2_2->setText(QCoreApplication::translate("Form", "[\302\260C]", nullptr));
        label_21->setText(QCoreApplication::translate("Form", "Purge valve current", nullptr));
        hose_temp_panel_2->setText(QString());
        battery_level_label->setText(QCoreApplication::translate("Form", "Battery level", nullptr));
        fill_valve_current_label->setText(QString());
        secondary_current_panel->setText(QString());
        hpa_panel_2->setText(QCoreApplication::translate("Form", "[bar]", nullptr));
        main_disconnect_current_panel->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_10), QCoreApplication::translate("Form", "GSE Data", nullptr));
        filling_open_button->setText(QCoreApplication::translate("Form", "Open", nullptr));
        purge_label->setText(QCoreApplication::translate("Form", "Purge", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Disconnect", nullptr));
        echo_button->setText(QCoreApplication::translate("Form", "Echo", nullptr));
        disconnect_on_button->setText(QCoreApplication::translate("Form", "On", nullptr));
        purge_close_button->setText(QCoreApplication::translate("Form", "Close", nullptr));
        filling_label->setText(QCoreApplication::translate("Form", "Filling", nullptr));
        ignition_off_button->setText(QCoreApplication::translate("Form", "Ignition Off", nullptr));
        filling_close_button->setText(QCoreApplication::translate("Form", "Close", nullptr));
        disconnect_off_button->setText(QCoreApplication::translate("Form", "Off", nullptr));
        purge_open_button->setText(QCoreApplication::translate("Form", "Open", nullptr));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QCoreApplication::translate("Form", "GSE Control", nullptr));
        lcs_button->setText(QString());
        lcs_check_1->setText(QString());
        lcs_check_2->setText(QString());
        lcs_check_3->setText(QString());
        lcs_check_4->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(lcs_tab), QCoreApplication::translate("Form", "LCS", nullptr));
        manual_mode_button->setText(QCoreApplication::translate("Form", "Manual Mode", nullptr));
        dbm_label->setText(QCoreApplication::translate("Form", "dBm", nullptr));
        time_panel->setText(QCoreApplication::translate("Form", "44:44:44", nullptr));
#if QT_CONFIG(tooltip)
        request_rssi->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>Get RSSI</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        request_rssi->setText(QCoreApplication::translate("Form", "RSSI", nullptr));
#if QT_CONFIG(tooltip)
        logo->setToolTip(QCoreApplication::translate("Form", "<html><head/><body><p>Project Bella Lui 2020</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        logo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Form", "Logo", nullptr));
        serial_status_label->setText(QCoreApplication::translate("Form", "XBee status", nullptr));
#if QT_CONFIG(tooltip)
        reset_button->setToolTip(QCoreApplication::translate("Form", "Resets saved data", nullptr));
#endif // QT_CONFIG(tooltip)
        reset_button->setText(QCoreApplication::translate("Form", "Reset", nullptr));
        xbee_button->setText(QCoreApplication::translate("Form", "START XBee", nullptr));
        serialport_selector->setItemText(0, QCoreApplication::translate("Form", "ttyUSB0", nullptr));
        serialport_selector->setItemText(1, QCoreApplication::translate("Form", "ttyUSB1", nullptr));
        serialport_selector->setItemText(2, QCoreApplication::translate("Form", "ttyS3", nullptr));
        serialport_selector->setItemText(3, QCoreApplication::translate("Form", "ttyS6", nullptr));

        change_theme->setText(QCoreApplication::translate("Form", "Color Theme", nullptr));
        serial_status_panel->setText(QCoreApplication::translate("Form", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Form", "Config", nullptr));
        gse_launch_ack_label->setText(QCoreApplication::translate("Form", "GSE Launch Acknowledge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINGUIGKOGUE_H
