#include "logindialog.h"
#include "ui_logindialog.h"
#include "qmessagebox.h"


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginButton_clicked()
{   /* 判断用户及密码是否正确 */
    if((ui->userLineEdit->text().trimmed() == tr("JackCc")) &&  ui->pwdLineEdit->text() == tr("SX1701203"))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"),
                           tr("User name or Password Error!"),
                           QMessageBox::Yes);
        // 清空内容并定位光标
        ui->userLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->userLineEdit->setFocus();
    }
}
