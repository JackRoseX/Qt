#include <QString>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTextCodec>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    /* 创建串口数据收发线程 */
    serial_thread = new Serial_Thread();
    /* 设置界面 */
    setWindowIcon(QIcon(":/images/rose.ico"));
    setWindowTitle(tr("JackCcStation"));
    QStringList band_rate;
    band_rate<<"9600"<<"115200";
    ui->Bandrate_Box->addItems(band_rate);
    /* 绘制曲线相关 */
    curve_init();
    curve_timer = new QTimer(this);
    curve_timer->start(100);
    /* 绑定自定义信号槽函数 */
    connect(serial_thread, SIGNAL(recv_signal(QByteArray)), this, SLOT(slot_showdata(QByteArray)));
    connect(this, SIGNAL(senddata(QString)), serial_thread, SLOT(slot_senddata(QString)));
    connect(serial_thread, SIGNAL(sendATIOk(float)), this, SLOT(slot_updateAA(float)));
    connect(serial_thread, SIGNAL(signal_send_att(float, float, float)), this, SLOT(slot_receiveAtt(float, float, float)));
    connect(curve_timer, SIGNAL(timeout()), this, SLOT(slot_curveTimerEvent()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serial_thread;
    delete curve_timer;
}

/* 输出接收到的数据槽函数 */
void MainWindow:: slot_showdata(QByteArray data)
{
    if(serial_thread->ascii_flag)
        ui->textBrowser->insertPlainText(data);
    else
    {
        QByteArray temp = data.toHex().toUpper();
        ui->textBrowser->insertPlainText(temp);
    }
    ui->textBrowser->document()->setMaximumBlockCount(100);
}

/* 查找可用串口按钮槽函数 */
void MainWindow::on_Find_Btn_clicked()
{
    if(ui->OpenCOM_Btn->text() == "关闭串口")
    {
        QMessageBox::critical(NULL, "提示", "串口处于打开状态，无法查找串口");
    }

    ui->COM_Box->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();

        ui->COM_Box->addItem(info.portName());
    }
}
/* 打开串口按钮槽函数 */
void MainWindow::on_OpenCOM_Btn_clicked()
{
    if(ui->OpenCOM_Btn->text() == "打开串口")
    {
        QString portname = ui->COM_Box->currentText();
        int bandrate = ui->Bandrate_Box->currentText().toInt();

        ui->OpenCOM_Btn->setText("关闭串口");

        serial_thread->com_init(portname, bandrate);

        serial_thread->start();
    }
    else if(ui->OpenCOM_Btn->text() == "关闭串口")
    {
         ui->OpenCOM_Btn->setText("打开串口");

         serial_thread->stop();
    }
}
/* 发送数据按钮槽函数 */
void MainWindow::on_Send_Btn_clicked()
{
    QString send_data = ui->Send_Edit->text();

    emit senddata(send_data);
}
/* 清除发送数据按钮槽函数 */
void MainWindow::on_Clear_Btn_clicked()
{
    ui->Send_Edit->clear();
}

void MainWindow::slot_updateAA(float roll)
{
    QString data = QString("float is %1").arg(roll);
    ui->textEdit->append(data);
    ui->textEdit->document()->setMaximumBlockCount(100);//设置最大行数
}

void MainWindow::slot_receiveAtt(float roll,float pitch,float yaw)
{
    ui->lcd_roll->display(roll);
    ui->lcd_pitch->display(pitch);
    ui->lcd_yaw->display(yaw);

    recv_roll=roll;
    recv_pitch=pitch;
    recv_yaw=yaw;
}
/* ASCII/十六进制显示 */
void MainWindow::on_ASC_Btn_clicked()
{
    if(ui->ASC_Btn->text() == "ASCII")
    {
        serial_thread->ascii_flag = false;
        ui->ASC_Btn->setText("十六进制");
    }
    else if(ui->ASC_Btn->text() == "十六进制")
    {
        serial_thread->ascii_flag = true;
        ui->ASC_Btn->setText("ASCII");
    }
}
/* 清除界面已显示数据 */
void MainWindow::on_ClearRecv_Btn_clicked()
{
    ui->textBrowser->clear();
}
/* 绘制曲线的初始化 */
void MainWindow::curve_init()
{
    ui->Curve_widget->installEventFilter(this); //注册监视对象
    for(int i = 0; i < 3; ++i)
    {
        ui->Curve_widget->addGraph();
        ui->Curve_widget->graph(i)->setVisible(false);
    }
    ui->Curve_widget->graph(0)->setPen(QPen(QColor("red")));
    ui->Curve_widget->graph(1)->setPen(QPen(QColor("black")));
    ui->Curve_widget->graph(2)->setPen(QPen(QColor("orange")));
//    ui->Curve_widget->graph(3)->setPen(QPen(QColor("green")));
//    ui->Curve_widget->graph(4)->setPen(QPen(QColor("yellow")));
//    ui->Curve_widget->graph(5)->setPen(QPen(QColor("blue")));
//    ui->Curve_widget->graph(6)->setPen(QPen(QColor("gray")));
//    ui->Curve_widget->graph(7)->setPen(QPen(QColor("dark gray")));
//    ui->Curve_widget->graph(8)->setPen(QPen(QColor("cyan")));
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->Curve_widget)
    {
        if(event->type() == QEvent::Paint)
        {
            if(ui->Roll_CheckBox->isChecked())
                ui->Curve_widget->graph(0)->setVisible(true);
            else
                ui->Curve_widget->graph(0)->setVisible(false);
            if(ui->Pitch_CheckBox->isChecked())
                ui->Curve_widget->graph(1)->setVisible(true);
            else
                ui->Curve_widget->graph(1)->setVisible(false);
            if(ui->Yaw_CheckBox->isChecked())
                ui->Curve_widget->graph(2)->setVisible(true);
            else
                ui->Curve_widget->graph(2)->setVisible(false);
        }
    }
    return QWidget::eventFilter(obj, event);
}
/* 定时器触发事件 */
void MainWindow::slot_curveTimerEvent()
{
    X_t += 0.1f;

    /* 相当于显示250个数据 */
    if(X_t>50)
        ui->Curve_widget->xAxis->setRange(X_t-50,X_t);
    else
        ui->Curve_widget->xAxis->setRange(0,50);

    x.append(X_t);

    y[0].append(recv_roll);
    ui->Curve_widget->graph(0)->setData(x,y[0]);
    y[1].append(recv_pitch);
    ui->Curve_widget->graph(1)->setData(x,y[1]);
    y[2].append(recv_yaw);
    ui->Curve_widget->graph(2)->setData(x,y[2]);

    ui->Curve_widget->yAxis->setRange(-15,15);
    ui->Curve_widget->yAxis->setAntialiased(1);//反锯齿

    ui->Curve_widget->replot();
    update();
}

