/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QCalendarWidget *calendarWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *Date;
    QLineEdit *stringTimeEdit;
    QLineEdit *stringDateEdit;
    QLineEdit *stringDateTimeEdit;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *Btn_GetTime;
    QPushButton *pushButton_2;
    QPushButton *BtnSetTime;
    QPushButton *BtnSetDate;
    QPushButton *BtnSetDateTime;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLCDNumber *lcdMinute;
    QProgressBar *progressBar;
    QPushButton *BtnSet;
    QLineEdit *TimeInterval;
    QLCDNumber *lcdHour;
    QLCDNumber *lcdSecond;
    QPushButton *BtnStart;
    QPushButton *BtnStop;
    QPushButton *BtnReset;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *ElapsTime;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(662, 395);
        calendarWidget = new QCalendarWidget(Dialog);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(400, 20, 251, 201));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 361, 201));
        Date = new QGridLayout(gridLayoutWidget);
        Date->setSpacing(6);
        Date->setContentsMargins(11, 11, 11, 11);
        Date->setObjectName(QStringLiteral("Date"));
        Date->setContentsMargins(0, 0, 0, 0);
        stringTimeEdit = new QLineEdit(gridLayoutWidget);
        stringTimeEdit->setObjectName(QStringLiteral("stringTimeEdit"));

        Date->addWidget(stringTimeEdit, 2, 2, 1, 1);

        stringDateEdit = new QLineEdit(gridLayoutWidget);
        stringDateEdit->setObjectName(QStringLiteral("stringDateEdit"));

        Date->addWidget(stringDateEdit, 3, 2, 1, 1);

        stringDateTimeEdit = new QLineEdit(gridLayoutWidget);
        stringDateTimeEdit->setObjectName(QStringLiteral("stringDateTimeEdit"));

        Date->addWidget(stringDateTimeEdit, 4, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        Date->addWidget(label_2, 3, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        Date->addWidget(label, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        Date->addWidget(label_3, 4, 0, 1, 1);

        timeEdit = new QTimeEdit(gridLayoutWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        Date->addWidget(timeEdit, 2, 1, 1, 1);

        dateEdit = new QDateEdit(gridLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        Date->addWidget(dateEdit, 3, 1, 1, 1);

        dateTimeEdit = new QDateTimeEdit(gridLayoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        Date->addWidget(dateTimeEdit, 4, 1, 1, 1);

        Btn_GetTime = new QPushButton(gridLayoutWidget);
        Btn_GetTime->setObjectName(QStringLiteral("Btn_GetTime"));

        Date->addWidget(Btn_GetTime, 1, 0, 1, 2);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        Date->addWidget(pushButton_2, 1, 2, 1, 1);

        BtnSetTime = new QPushButton(gridLayoutWidget);
        BtnSetTime->setObjectName(QStringLiteral("BtnSetTime"));

        Date->addWidget(BtnSetTime, 2, 3, 1, 1);

        BtnSetDate = new QPushButton(gridLayoutWidget);
        BtnSetDate->setObjectName(QStringLiteral("BtnSetDate"));

        Date->addWidget(BtnSetDate, 3, 3, 1, 1);

        BtnSetDateTime = new QPushButton(gridLayoutWidget);
        BtnSetDateTime->setObjectName(QStringLiteral("BtnSetDateTime"));

        Date->addWidget(BtnSetDateTime, 4, 3, 1, 1);

        gridLayoutWidget_2 = new QWidget(Dialog);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(70, 230, 260, 135));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lcdMinute = new QLCDNumber(gridLayoutWidget_2);
        lcdMinute->setObjectName(QStringLiteral("lcdMinute"));

        gridLayout->addWidget(lcdMinute, 1, 1, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 4, 0, 1, 3);

        BtnSet = new QPushButton(gridLayoutWidget_2);
        BtnSet->setObjectName(QStringLiteral("BtnSet"));

        gridLayout->addWidget(BtnSet, 0, 2, 1, 1);

        TimeInterval = new QLineEdit(gridLayoutWidget_2);
        TimeInterval->setObjectName(QStringLiteral("TimeInterval"));

        gridLayout->addWidget(TimeInterval, 0, 1, 1, 1);

        lcdHour = new QLCDNumber(gridLayoutWidget_2);
        lcdHour->setObjectName(QStringLiteral("lcdHour"));

        gridLayout->addWidget(lcdHour, 1, 0, 1, 1);

        lcdSecond = new QLCDNumber(gridLayoutWidget_2);
        lcdSecond->setObjectName(QStringLiteral("lcdSecond"));

        gridLayout->addWidget(lcdSecond, 1, 2, 1, 2);

        BtnStart = new QPushButton(gridLayoutWidget_2);
        BtnStart->setObjectName(QStringLiteral("BtnStart"));

        gridLayout->addWidget(BtnStart, 3, 0, 1, 1);

        BtnStop = new QPushButton(gridLayoutWidget_2);
        BtnStop->setObjectName(QStringLiteral("BtnStop"));

        gridLayout->addWidget(BtnStop, 3, 1, 1, 1);

        BtnReset = new QPushButton(gridLayoutWidget_2);
        BtnReset->setObjectName(QStringLiteral("BtnReset"));

        gridLayout->addWidget(BtnReset, 3, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        ElapsTime = new QLineEdit(gridLayoutWidget_2);
        ElapsTime->setObjectName(QStringLiteral("ElapsTime"));

        gridLayout->addWidget(ElapsTime, 2, 1, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\346\227\245   \346\234\237", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "\346\227\266   \351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\346\227\245\346\234\237\346\227\266\351\227\264", Q_NULLPTR));
        Btn_GetTime->setText(QApplication::translate("Dialog", "\350\257\273\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "\345\255\227\347\254\246\344\270\262\346\230\276\347\244\272", Q_NULLPTR));
        BtnSetTime->setText(QApplication::translate("Dialog", "\350\256\276\347\275\256\346\227\266\351\227\264", Q_NULLPTR));
        BtnSetDate->setText(QApplication::translate("Dialog", "\350\256\276\347\275\256\346\227\245\346\234\237", Q_NULLPTR));
        BtnSetDateTime->setText(QApplication::translate("Dialog", "\350\256\276\347\275\256\346\227\245\346\234\237\346\227\266\351\227\264", Q_NULLPTR));
        BtnSet->setText(QApplication::translate("Dialog", "\350\256\276\347\275\256", Q_NULLPTR));
        BtnStart->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213", Q_NULLPTR));
        BtnStop->setText(QApplication::translate("Dialog", "\345\201\234\346\255\242", Q_NULLPTR));
        BtnReset->setText(QApplication::translate("Dialog", "\351\207\215\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "\345\256\232\346\227\266\345\221\250\346\234\237(ms\357\274\211", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "\346\265\201\351\200\235\346\227\266\351\227\264", Q_NULLPTR));
        ElapsTime->setInputMask(QString());
        ElapsTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
