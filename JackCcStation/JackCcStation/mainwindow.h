#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include "serial_thread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    float recv_roll, recv_pitch, recv_yaw;
    QTimer *curve_timer;
    float X_t = 0;

    QVector<double>x;
    QVector<double>y[10];

    void curve_init();


private:
    Ui::MainWindow *ui;
    Serial_Thread *serial_thread;

    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void slot_showdata(QByteArray);
    void slot_updateAA(float roll);
    void slot_receiveAtt(float,float,float);
    void slot_curveTimerEvent();

    void on_Find_Btn_clicked();
    void on_OpenCOM_Btn_clicked();
    void on_Send_Btn_clicked();
    void on_Clear_Btn_clicked();
    void on_ASC_Btn_clicked();
    void on_ClearRecv_Btn_clicked();

signals:
    void senddata(QString);
};

#endif // MAINWINDOW_H
