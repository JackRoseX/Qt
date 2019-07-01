#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/images/rose.ico"));

    setWindowTitle(tr("Welcome to JackCcStation"));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_LoginBtn_clicked()
{
    // simplified()函数忽略空格
    if(ui->UesrlineEdit->text().trimmed() == tr("") &&
            ui->PwdlineEdit->text().trimmed() == tr(""))
    {
//        QMessageBox::warning(this, tr("waring:"), tr("Please enter user name or pass word!"), QMessageBox::Yes);
        // 清空内容并定位光标
//        ui->UesrlineEdit->clear();
//        ui->PwdlineEdit->clear();
//        ui->UesrlineEdit->setFocus();
         accept();
    }
    else
    {
        QMessageBox::warning(this, tr("waring:"), tr("User name or Pass word error!"), QMessageBox::Yes);
        ui->UesrlineEdit->clear();
        ui->PwdlineEdit->clear();
        ui->UesrlineEdit->setFocus();
    }
}

void Dialog::on_ExitBtn_clicked()
{
    if(!QMessageBox::information(this, tr("JackCcStation"), tr("Do you really want to exit JackCcStation?"),
                                tr("Yes"), tr("No")))
    {
        this->close();
    }
}

