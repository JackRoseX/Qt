#ifndef SERIAL_THREAD_H
#define SERIAL_THREAD_H

#include <QThread>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Serial_Thread : public QThread
{
    Q_OBJECT
public:
     Serial_Thread(QObject *parent = nullptr);
     ~Serial_Thread();
     void run();
     void stop();
     void com_init(QString , int);
     void parser_data1(quint8);
     void parser_data2(quint8 *, quint8);

public:
     bool run_flag;
     bool ascii_flag = true;

     QSerialPort *mycom;
     QByteArray  recv_data;

private slots:
     void slot_senddata(QString);

signals:
     void recv_signal(QByteArray);

     void sendATIOk(float);
     void signal_send_att(float ,float ,float );

};

#endif // SERIAL_THREAD_H
