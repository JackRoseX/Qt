#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QObject::tr("DateTime Timer"));

    ftimer = new QTimer(this);
    ftimer->stop();
    ftimer->setInterval(1000);  //unit: ms
    ui->TimeInterval->setText("1000");
    ui->ElapsTime->setText("Elaps Time: 0s,0ms");
    ui->progressBar->setValue(0);

    connect(ftimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_Btn_GetTime_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->stringTimeEdit->setText(curDateTime.time().toString("hh:mm:ss"));
    ui->dateEdit->setDate(curDateTime.date());
    ui->stringDateEdit->setText(curDateTime.date().toString("yyyy-MM-dd"));
    ui->dateTimeEdit->setDateTime(curDateTime);
    ui->stringDateTimeEdit->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Dialog::on_BtnSetTime_clicked()
{
    QString str = ui->stringTimeEdit->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QTime time = QTime::fromString(str, "hh:mm:ss");
        ui->timeEdit->setTime(time);
    }
}

void Dialog::on_BtnSetDateTime_clicked()
{
    QString str=ui->stringDateTimeEdit->text();
    str=str.trimmed();
    if (!str.isEmpty())
    {
        QDateTime datetime=QDateTime::fromString(str,"yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(datetime);
    }
}

void Dialog::on_BtnSetDate_clicked()
{
    QString str = ui->stringDateEdit->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QDate date = QDate::fromString(str, "yyyy-MM-dd");
        ui->dateEdit->setDate(date);
    }
}

void Dialog::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    ui->dateEdit->setDate(date);
    ui->stringDateEdit->setText(date.toString("yyyy-MM-dd"));
}

void Dialog::on_timer_timeout()
{
    QTime curTime = QTime::currentTime();
    ui->lcdHour->display(curTime.hour());
    ui->lcdMinute->display(curTime.minute());
    ui->lcdSecond->display(curTime.second());

    int va = ui->progressBar->value();
    va++;
    if(va>100)
        va = 0;
    ui->progressBar->setValue(va);
}

void Dialog::on_BtnStart_clicked()
{
   ftimer->start();
   ftimercounter.start();
   ui->BtnStart->setEnabled(false);
   ui->BtnStop->setEnabled(true);
   ui->BtnReset->setEnabled(true);
   ui->BtnSet->setEnabled(false);
}

void Dialog::on_BtnStop_clicked()
{
    ftimer->stop();
    int tmMsec = ftimercounter.elapsed();
    int ms = tmMsec%1000;
    int sec = tmMsec/1000;
    QString str = QString::asprintf("Elaps Time: %ds,%dms",sec, ms);
    ui->ElapsTime->setText(str);
    ui->BtnStart->setEnabled(true);
    ui->BtnStop->setEnabled(false);
    ui->BtnReset->setEnabled(true);
    ui->BtnSet->setEnabled(true);
}

void Dialog::on_BtnSet_clicked()
{
    int interval = ui->TimeInterval->text().toInt();
    ftimer->setInterval(interval);
}


void Dialog::on_BtnReset_clicked()
{
    ftimer->stop();

    ftimer->setInterval(1000);  //unit: ms
    ui->TimeInterval->setText("1000");
    ui->ElapsTime->setText("Elaps Time: 0s,0ms");
    ui->progressBar->setValue(0);
    ui->BtnStart->setEnabled(true);
    ui->BtnStop->setEnabled(false);
    ui->BtnReset->setEnabled(true);
    ui->BtnSet->setEnabled(true);
}
