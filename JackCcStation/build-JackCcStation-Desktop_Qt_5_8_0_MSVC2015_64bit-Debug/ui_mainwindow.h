/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QLCDNumber *lcd_roll;
    QLCDNumber *lcd_pitch;
    QLCDNumber *lcd_yaw;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *Bandrate_Box;
    QPushButton *Send_Btn;
    QPushButton *OpenCOM_Btn;
    QPushButton *Clear_Btn;
    QPushButton *ASC_Btn;
    QComboBox *COM_Box;
    QPushButton *ClearRecv_Btn;
    QLabel *label_2;
    QPushButton *Find_Btn;
    QLineEdit *Send_Edit;
    QLabel *label;
    QTextBrowser *textBrowser;
    QCustomPlot *Curve_widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *Roll_CheckBox;
    QCheckBox *Pitch_CheckBox;
    QCheckBox *Yaw_CheckBox;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(739, 366);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 141, 31));
        lcd_roll = new QLCDNumber(centralwidget);
        lcd_roll->setObjectName(QStringLiteral("lcd_roll"));
        lcd_roll->setGeometry(QRect(60, 210, 71, 21));
        lcd_pitch = new QLCDNumber(centralwidget);
        lcd_pitch->setObjectName(QStringLiteral("lcd_pitch"));
        lcd_pitch->setGeometry(QRect(60, 250, 71, 21));
        lcd_yaw = new QLCDNumber(centralwidget);
        lcd_yaw->setObjectName(QStringLiteral("lcd_yaw"));
        lcd_yaw->setGeometry(QRect(60, 280, 71, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 211, 31, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 251, 31, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 280, 21, 21));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(510, 20, 211, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Bandrate_Box = new QComboBox(gridLayoutWidget);
        Bandrate_Box->setObjectName(QStringLiteral("Bandrate_Box"));

        gridLayout->addWidget(Bandrate_Box, 3, 1, 1, 1);

        Send_Btn = new QPushButton(gridLayoutWidget);
        Send_Btn->setObjectName(QStringLiteral("Send_Btn"));

        gridLayout->addWidget(Send_Btn, 7, 0, 1, 1);

        OpenCOM_Btn = new QPushButton(gridLayoutWidget);
        OpenCOM_Btn->setObjectName(QStringLiteral("OpenCOM_Btn"));

        gridLayout->addWidget(OpenCOM_Btn, 4, 1, 1, 1);

        Clear_Btn = new QPushButton(gridLayoutWidget);
        Clear_Btn->setObjectName(QStringLiteral("Clear_Btn"));

        gridLayout->addWidget(Clear_Btn, 7, 1, 1, 1);

        ASC_Btn = new QPushButton(gridLayoutWidget);
        ASC_Btn->setObjectName(QStringLiteral("ASC_Btn"));

        gridLayout->addWidget(ASC_Btn, 5, 0, 1, 1);

        COM_Box = new QComboBox(gridLayoutWidget);
        COM_Box->setObjectName(QStringLiteral("COM_Box"));

        gridLayout->addWidget(COM_Box, 2, 1, 1, 1);

        ClearRecv_Btn = new QPushButton(gridLayoutWidget);
        ClearRecv_Btn->setObjectName(QStringLiteral("ClearRecv_Btn"));

        gridLayout->addWidget(ClearRecv_Btn, 5, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        Find_Btn = new QPushButton(gridLayoutWidget);
        Find_Btn->setObjectName(QStringLiteral("Find_Btn"));

        gridLayout->addWidget(Find_Btn, 4, 0, 1, 1);

        Send_Edit = new QLineEdit(gridLayoutWidget);
        Send_Edit->setObjectName(QStringLiteral("Send_Edit"));

        gridLayout->addWidget(Send_Edit, 6, 0, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 2);

        Curve_widget = new QCustomPlot(centralwidget);
        Curve_widget->setObjectName(QStringLiteral("Curve_widget"));
        Curve_widget->setGeometry(QRect(210, 210, 291, 101));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 210, 61, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Roll_CheckBox = new QCheckBox(verticalLayoutWidget);
        Roll_CheckBox->setObjectName(QStringLiteral("Roll_CheckBox"));

        verticalLayout->addWidget(Roll_CheckBox);

        Pitch_CheckBox = new QCheckBox(verticalLayoutWidget);
        Pitch_CheckBox->setObjectName(QStringLiteral("Pitch_CheckBox"));

        verticalLayout->addWidget(Pitch_CheckBox);

        Yaw_CheckBox = new QCheckBox(verticalLayoutWidget);
        Yaw_CheckBox->setObjectName(QStringLiteral("Yaw_CheckBox"));

        verticalLayout->addWidget(Yaw_CheckBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 739, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "ROLL", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Pitch", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Yaw", Q_NULLPTR));
        Send_Btn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
        OpenCOM_Btn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        Clear_Btn->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201", Q_NULLPTR));
        ASC_Btn->setText(QApplication::translate("MainWindow", "ASCII", Q_NULLPTR));
        ClearRecv_Btn->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "     \346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        Find_Btn->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\344\270\262\345\217\243", Q_NULLPTR));
        Send_Edit->setInputMask(QString());
        Send_Edit->setText(QString());
        Send_Edit->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\276\205\345\217\221\351\200\201\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "      COM\345\217\243\357\274\232", Q_NULLPTR));
        Roll_CheckBox->setText(QApplication::translate("MainWindow", "Roll", Q_NULLPTR));
        Pitch_CheckBox->setText(QApplication::translate("MainWindow", "Pitch", Q_NULLPTR));
        Yaw_CheckBox->setText(QApplication::translate("MainWindow", "Yaw", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225\347\225\214\351\235\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
