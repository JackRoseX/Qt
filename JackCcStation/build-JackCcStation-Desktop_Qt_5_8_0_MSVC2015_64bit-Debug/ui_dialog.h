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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *LoginBtn;
    QPushButton *ExitBtn;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *UesrlineEdit;
    QLineEdit *PwdlineEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(387, 285);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/rose.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        LoginBtn = new QPushButton(Dialog);
        LoginBtn->setObjectName(QStringLiteral("LoginBtn"));
        LoginBtn->setGeometry(QRect(90, 200, 75, 23));
        ExitBtn = new QPushButton(Dialog);
        ExitBtn->setObjectName(QStringLiteral("ExitBtn"));
        ExitBtn->setGeometry(QRect(210, 200, 75, 23));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 60, 61, 16));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 130, 61, 16));
        UesrlineEdit = new QLineEdit(Dialog);
        UesrlineEdit->setObjectName(QStringLiteral("UesrlineEdit"));
        UesrlineEdit->setEnabled(true);
        UesrlineEdit->setGeometry(QRect(160, 60, 161, 21));
        UesrlineEdit->setEchoMode(QLineEdit::Normal);
        PwdlineEdit = new QLineEdit(Dialog);
        PwdlineEdit->setObjectName(QStringLiteral("PwdlineEdit"));
        PwdlineEdit->setEnabled(true);
        PwdlineEdit->setGeometry(QRect(160, 130, 161, 21));
        PwdlineEdit->setEchoMode(QLineEdit::Password);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        LoginBtn->setText(QApplication::translate("Dialog", "Login", Q_NULLPTR));
        ExitBtn->setText(QApplication::translate("Dialog", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "User Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Pass Word:", Q_NULLPTR));
        UesrlineEdit->setText(QString());
        UesrlineEdit->setPlaceholderText(QApplication::translate("Dialog", "please enter user name", Q_NULLPTR));
        PwdlineEdit->setText(QString());
        PwdlineEdit->setPlaceholderText(QApplication::translate("Dialog", "please enter pass word", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
