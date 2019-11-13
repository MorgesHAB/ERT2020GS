/********************************************************************************
** Form generated from reading UI file 'press_alth11015.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PRESS_ALTH11015_H
#define PRESS_ALTH11015_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLCDNumber *altitude_lcd;
    QLCDNumber *speed_lcd;
    QLabel *speed_label;
    QLabel *altitude_label;
    QLabel *latitude_label;
    QLabel *rssi_panel;
    QLabel *rssi_label;
    QLabel *longitude_label;
    QLabel *longitude_panel;
    QLabel *latitude_panel;

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
        altitude_lcd = new QLCDNumber(Form);
        altitude_lcd->setObjectName(QStringLiteral("altitude_lcd"));
        altitude_lcd->setSmallDecimalPoint(false);

        gridLayout->addWidget(altitude_lcd, 0, 1, 1, 1);

        speed_lcd = new QLCDNumber(Form);
        speed_lcd->setObjectName(QStringLiteral("pressure_lcd"));

        gridLayout->addWidget(speed_lcd, 1, 1, 1, 1);

        speed_label = new QLabel(Form);
        speed_label->setObjectName(QStringLiteral("presure_label"));

        gridLayout->addWidget(speed_label, 1, 0, 1, 1);

        altitude_label = new QLabel(Form);
        altitude_label->setObjectName(QStringLiteral("altitude_label"));

        gridLayout->addWidget(altitude_label, 0, 0, 1, 1);

        latitude_label = new QLabel(Form);
        latitude_label->setObjectName(QStringLiteral("latitude_label"));

        gridLayout->addWidget(latitude_label, 2, 0, 1, 1);

        rssi_panel = new QLabel(Form);
        rssi_panel->setObjectName(QStringLiteral("rssi_panel"));

        gridLayout->addWidget(rssi_panel, 4, 1, 1, 1);

        rssi_label = new QLabel(Form);
        rssi_label->setObjectName(QStringLiteral("rssi_label"));

        gridLayout->addWidget(rssi_label, 4, 0, 1, 1);

        longitude_label = new QLabel(Form);
        longitude_label->setObjectName(QStringLiteral("longitude_label"));

        gridLayout->addWidget(longitude_label, 3, 0, 1, 1);

        longitude_panel = new QLabel(Form);
        longitude_panel->setObjectName(QStringLiteral("longitude_panel"));

        gridLayout->addWidget(longitude_panel, 3, 1, 1, 1);

        latitude_panel = new QLabel(Form);
        latitude_panel->setObjectName(QStringLiteral("latitude_panel"));

        gridLayout->addWidget(latitude_panel, 2, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        speed_label->setText(QApplication::translate("Form", "SPEED", Q_NULLPTR));
        altitude_label->setText(QApplication::translate("Form", "ALTITUDE", Q_NULLPTR));
        latitude_label->setText(QApplication::translate("Form", "LATITUDE", Q_NULLPTR));
        rssi_panel->setText(QString());
        rssi_label->setText(QApplication::translate("Form", "RSSI", Q_NULLPTR));
        longitude_label->setText(QApplication::translate("Form", "LONGITUDE", Q_NULLPTR));
        longitude_panel->setText(QString());
        latitude_panel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRESS_ALTH11015_H
