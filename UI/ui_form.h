/********************************************************************************
** Form generated from reading UI file 'press_altcS6260.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PRESS_ALTCS6260_H
#define PRESS_ALTCS6260_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QLabel *last_refresh_label;
    QLabel *altitude_label;
    QLabel *presure_label;
    QLabel *latitude_label;
    QLCDNumber *pressure_lcd;
    QLabel *latitude_panel;
    QLabel *last_refresh_panel;
    QLabel *longitude_label;
    QLabel *longitude_panel;
    QLCDNumber *altitude_lcd;
    QWidget *button_widget;
    QGridLayout *gridLayout_2;
    QPushButton *xbee_button;
    QPushButton *stop_xbee;
    QPushButton *change_theme;
    QPushButton *ignition_button;
    QGroupBox *com_box;
    QGridLayout *gridLayout_4;
    QLabel *last_packet_nbr_label;
    QLabel *packets_second_label;
    QProgressBar *packets_second_bar;
    QLabel *last_packet_number_panel;
    QLabel *rssi_label;
    QLabel *rssi_panel;
    QLabel *logo;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(469, 360);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(0, 0));
        Form->setMaximumSize(QSize(1024, 720));
        Form->setStyleSheet(QLatin1String("background-color: rgb(10, 10, 10);\n"
"color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        telemetry_box = new QGroupBox(Form);
        telemetry_box->setObjectName(QStringLiteral("telemetry_box"));
        telemetry_box->setMinimumSize(QSize(0, 200));
        gridLayout_3 = new QGridLayout(telemetry_box);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        last_refresh_label = new QLabel(telemetry_box);
        last_refresh_label->setObjectName(QStringLiteral("last_refresh_label"));

        gridLayout_3->addWidget(last_refresh_label, 0, 0, 1, 1);

        altitude_label = new QLabel(telemetry_box);
        altitude_label->setObjectName(QStringLiteral("altitude_label"));

        gridLayout_3->addWidget(altitude_label, 1, 0, 1, 1);

        presure_label = new QLabel(telemetry_box);
        presure_label->setObjectName(QStringLiteral("presure_label"));

        gridLayout_3->addWidget(presure_label, 8, 0, 1, 1);

        latitude_label = new QLabel(telemetry_box);
        latitude_label->setObjectName(QStringLiteral("latitude_label"));

        gridLayout_3->addWidget(latitude_label, 3, 0, 1, 1);

        pressure_lcd = new QLCDNumber(telemetry_box);
        pressure_lcd->setObjectName(QStringLiteral("pressure_lcd"));

        gridLayout_3->addWidget(pressure_lcd, 8, 1, 1, 1);

        latitude_panel = new QLabel(telemetry_box);
        latitude_panel->setObjectName(QStringLiteral("latitude_panel"));
        latitude_panel->setMinimumSize(QSize(0, 0));

        gridLayout_3->addWidget(latitude_panel, 3, 1, 1, 1);

        last_refresh_panel = new QLabel(telemetry_box);
        last_refresh_panel->setObjectName(QStringLiteral("last_refresh_panel"));

        gridLayout_3->addWidget(last_refresh_panel, 0, 1, 1, 1);

        longitude_label = new QLabel(telemetry_box);
        longitude_label->setObjectName(QStringLiteral("longitude_label"));

        gridLayout_3->addWidget(longitude_label, 2, 0, 1, 1);

        longitude_panel = new QLabel(telemetry_box);
        longitude_panel->setObjectName(QStringLiteral("longitude_panel"));

        gridLayout_3->addWidget(longitude_panel, 2, 1, 1, 1);

        altitude_lcd = new QLCDNumber(telemetry_box);
        altitude_lcd->setObjectName(QStringLiteral("altitude_lcd"));
        altitude_lcd->setSmallDecimalPoint(false);

        gridLayout_3->addWidget(altitude_lcd, 1, 1, 1, 1);


        gridLayout->addWidget(telemetry_box, 1, 1, 1, 2);

        button_widget = new QWidget(Form);
        button_widget->setObjectName(QStringLiteral("button_widget"));
        gridLayout_2 = new QGridLayout(button_widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        xbee_button = new QPushButton(button_widget);
        xbee_button->setObjectName(QStringLiteral("xbee_button"));

        gridLayout_2->addWidget(xbee_button, 1, 0, 1, 1);

        stop_xbee = new QPushButton(button_widget);
        stop_xbee->setObjectName(QStringLiteral("stop_xbee"));

        gridLayout_2->addWidget(stop_xbee, 2, 0, 1, 1);

        change_theme = new QPushButton(button_widget);
        change_theme->setObjectName(QStringLiteral("change_theme"));

        gridLayout_2->addWidget(change_theme, 3, 0, 1, 1);

        ignition_button = new QPushButton(button_widget);
        ignition_button->setObjectName(QStringLiteral("ignition_button"));

        gridLayout_2->addWidget(ignition_button, 0, 0, 1, 1);


        gridLayout->addWidget(button_widget, 0, 1, 1, 1);

        com_box = new QGroupBox(Form);
        com_box->setObjectName(QStringLiteral("com_box"));
        gridLayout_4 = new QGridLayout(com_box);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        last_packet_nbr_label = new QLabel(com_box);
        last_packet_nbr_label->setObjectName(QStringLiteral("last_packet_nbr_label"));

        gridLayout_4->addWidget(last_packet_nbr_label, 0, 0, 1, 1);

        packets_second_label = new QLabel(com_box);
        packets_second_label->setObjectName(QStringLiteral("packets_second_label"));

        gridLayout_4->addWidget(packets_second_label, 2, 0, 1, 1);

        packets_second_bar = new QProgressBar(com_box);
        packets_second_bar->setObjectName(QStringLiteral("packets_second_bar"));
        packets_second_bar->setStyleSheet(QStringLiteral(""));
        packets_second_bar->setMaximum(70);
        packets_second_bar->setValue(60);
        packets_second_bar->setInvertedAppearance(false);

        gridLayout_4->addWidget(packets_second_bar, 2, 1, 1, 1);

        last_packet_number_panel = new QLabel(com_box);
        last_packet_number_panel->setObjectName(QStringLiteral("last_packet_number_panel"));

        gridLayout_4->addWidget(last_packet_number_panel, 0, 1, 1, 1);

        rssi_label = new QLabel(com_box);
        rssi_label->setObjectName(QStringLiteral("rssi_label"));

        gridLayout_4->addWidget(rssi_label, 1, 0, 1, 1);

        rssi_panel = new QLabel(com_box);
        rssi_panel->setObjectName(QStringLiteral("rssi_panel"));

        gridLayout_4->addWidget(rssi_panel, 1, 1, 1, 1);


        gridLayout->addWidget(com_box, 0, 2, 1, 2);

        logo = new QLabel(Form);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setStyleSheet(QStringLiteral("image: url(:/image.png);"));

        gridLayout->addWidget(logo, 1, 3, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "GSBellaLui2020", Q_NULLPTR));
        telemetry_box->setTitle(QApplication::translate("Form", "Telemetry", Q_NULLPTR));
        last_refresh_label->setText(QApplication::translate("Form", "Last Refresh", Q_NULLPTR));
        altitude_label->setText(QApplication::translate("Form", "ALTITUDE", Q_NULLPTR));
        presure_label->setText(QApplication::translate("Form", "SPEED", Q_NULLPTR));
        latitude_label->setText(QApplication::translate("Form", "LATITUDE", Q_NULLPTR));
        latitude_panel->setText(QString());
        last_refresh_panel->setText(QString());
        longitude_label->setText(QApplication::translate("Form", "LONGITUDE", Q_NULLPTR));
        longitude_panel->setText(QString());
        xbee_button->setText(QApplication::translate("Form", "Activate XBee", Q_NULLPTR));
        stop_xbee->setText(QApplication::translate("Form", "Stop XBee", Q_NULLPTR));
        change_theme->setText(QApplication::translate("Form", "Change Color Theme", Q_NULLPTR));
        ignition_button->setText(QApplication::translate("Form", "Ignition", Q_NULLPTR));
        com_box->setTitle(QApplication::translate("Form", "COM", Q_NULLPTR));
        last_packet_nbr_label->setText(QApplication::translate("Form", "Last Packet Number", Q_NULLPTR));
        packets_second_label->setText(QApplication::translate("Form", "Packets/second", Q_NULLPTR));
        packets_second_bar->setFormat(QApplication::translate("Form", "%v", Q_NULLPTR));
        last_packet_number_panel->setText(QString());
        rssi_label->setText(QApplication::translate("Form", "RSSI", Q_NULLPTR));
        rssi_panel->setText(QString());
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRESS_ALTCS6260_H
