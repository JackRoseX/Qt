#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:

    void on_Btn_GetTime_clicked();

    void on_BtnSetTime_clicked();

    void on_BtnSetDateTime_clicked();

    void on_BtnSetDate_clicked();

    void on_calendarWidget_selectionChanged();

    void on_timer_timeout();

    void on_BtnStart_clicked();

    void on_BtnStop_clicked();

    void on_BtnSet_clicked();

    void on_BtnReset_clicked();

private:
    Ui::Dialog *ui;

    QTimer *ftimer; // timer
    QTime   ftimercounter; // timer counter
};

#endif // DIALOG_H
