/********************************************************************************
** Form generated from reading UI file 'press_altKx2191.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PRESS_ALTKX2191_H
#define PRESS_ALTKX2191_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *longitude_panel;
    QLCDNumber *pressure_lcd;
    QLabel *latitude_label;
    QLabel *presure_label;
    QLabel *longitude_label;
    QLCDNumber *altitude_lcd;
    QLabel *altitude_label;
    QLabel *latitude_panel;
    QLabel *rssi_label;
    QLabel *rssi_panel;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *ignition_button;
    QPushButton *xbee_button;
    QPushButton *button_send_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(400, 200);
        Form->setMinimumSize(QSize(400, 200));
        Form->setMaximumSize(QSize(400, 200));
        Form->setStyleSheet(QLatin1String("background-color: rgb(35, 35, 35);\n"
"color: rgb(51, 255, 0);"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        longitude_panel = new QLabel(widget);
        longitude_panel->setObjectName(QStringLiteral("longitude_panel"));

        gridLayout_2->addWidget(longitude_panel, 3, 1, 1, 1);

        pressure_lcd = new QLCDNumber(widget);
        pressure_lcd->setObjectName(QStringLiteral("pressure_lcd"));

        gridLayout_2->addWidget(pressure_lcd, 1, 1, 1, 1);

        latitude_label = new QLabel(widget);
        latitude_label->setObjectName(QStringLiteral("latitude_label"));

        gridLayout_2->addWidget(latitude_label, 2, 0, 1, 1);

        presure_label = new QLabel(widget);
        presure_label->setObjectName(QStringLiteral("presure_label"));

        gridLayout_2->addWidget(presure_label, 1, 0, 1, 1);

        longitude_label = new QLabel(widget);
        longitude_label->setObjectName(QStringLiteral("longitude_label"));

        gridLayout_2->addWidget(longitude_label, 3, 0, 1, 1);

        altitude_lcd = new QLCDNumber(widget);
        altitude_lcd->setObjectName(QStringLiteral("altitude_lcd"));
        altitude_lcd->setSmallDecimalPoint(false);

        gridLayout_2->addWidget(altitude_lcd, 0, 1, 1, 1);

        altitude_label = new QLabel(widget);
        altitude_label->setObjectName(QStringLiteral("altitude_label"));

        gridLayout_2->addWidget(altitude_label, 0, 0, 1, 1);

        latitude_panel = new QLabel(widget);
        latitude_panel->setObjectName(QStringLiteral("latitude_panel"));

        gridLayout_2->addWidget(latitude_panel, 2, 1, 1, 1);

        rssi_label = new QLabel(widget);
        rssi_label->setObjectName(QStringLiteral("rssi_label"));

        gridLayout_2->addWidget(rssi_label, 4, 0, 1, 1);

        rssi_panel = new QLabel(widget);
        rssi_panel->setObjectName(QStringLiteral("rssi_panel"));

        gridLayout_2->addWidget(rssi_panel, 4, 1, 1, 1);


        gridLayout->addWidget(widget, 1, 1, 1, 1);

        widget_2 = new QWidget(Form);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ignition_button = new QPushButton(widget_2);
        ignition_button->setObjectName(QStringLiteral("ignition_button"));

        verticalLayout->addWidget(ignition_button);

        xbee_button = new QPushButton(widget_2);
        xbee_button->setObjectName(QStringLiteral("xbee_button"));

        verticalLayout->addWidget(xbee_button);

        button_send_3 = new QPushButton(widget_2);
        button_send_3->setObjectName(QStringLiteral("button_send_3"));

        verticalLayout->addWidget(button_send_3);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        longitude_panel->setText(QString());
        latitude_label->setText(QApplication::translate("Form", "LATITUDE", Q_NULLPTR));
        presure_label->setText(QApplication::translate("Form", "SPEED", Q_NULLPTR));
        longitude_label->setText(QApplication::translate("Form", "LONGITUDE", Q_NULLPTR));
        altitude_label->setText(QApplication::translate("Form", "ALTITUDE", Q_NULLPTR));
        latitude_panel->setText(QString());
        rssi_label->setText(QApplication::translate("Form", "RSSI", Q_NULLPTR));
        rssi_panel->setText(QString());
        ignition_button->setText(QApplication::translate("Form", "Ignition", Q_NULLPTR));
        xbee_button->setText(QApplication::translate("Form", "Activate XBee", Q_NULLPTR));
        button_send_3->setText(QApplication::translate("Form", "Func. 2 Button", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRESS_ALTKX2191_H
