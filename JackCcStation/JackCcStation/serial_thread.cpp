#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include "mainwindow.h"
#include "serial_thread.h"

Serial_Thread::Serial_Thread(QObject *parent)
    :QThread(parent)
{
    qDebug() << "serial thread start..." ;
    mycom = new QSerialPort;
}

Serial_Thread::~Serial_Thread()
{
    stop();
    delete mycom;
}

void Serial_Thread::run()
{
    QByteArray tempStr;
    char *ptr;
    int byte_num;

    run_flag = true;

    while(true)
    {
        if(!run_flag)
            break;
        if(mycom->isOpen() && mycom->bytesAvailable() > 0)
        {
            tempStr = mycom->readAll();
            /* 向主界面线程发送信号 */
            emit recv_signal(tempStr);

            byte_num = tempStr.length();
            ptr = tempStr.data();
            for(int i = 0; i < byte_num; ++i)
                parser_data1(*(ptr+i));
        }
    }
}

void Serial_Thread::stop()
{
    run_flag = false;
    /* 清空缓存 */
    mycom->readAll();
    if(mycom->isOpen())
        mycom->close();
}
/* com口初始化 */
void Serial_Thread::com_init(QString portname, int bandrate)
{
    if(mycom->isOpen())
        mycom->close();
    mycom->setPortName(portname);
    mycom->setBaudRate(bandrate);
    mycom->setDataBits(QSerialPort::Data8);
    mycom->setParity(QSerialPort::NoParity);
    mycom->setStopBits(QSerialPort::OneStop);
    mycom->setFlowControl(QSerialPort::NoFlowControl);
    if(!mycom->open(QIODevice::ReadWrite))
        QMessageBox::critical(NULL, "提示", "串口打开失败");

    qDebug() << "Connectted";
}
/* 发送数据槽函数 */
void Serial_Thread::slot_senddata(QString data)
{
    mycom->write(data.toLatin1());
}
/* 解析数据 */
void Serial_Thread::parser_data1(quint8 data)
{
   //一次最大接收数据120个
   static quint8 RxBuffer[120];
   static quint8 _data_len = 0,_data_cnt = 0;
   static quint8 state = 0;

   if(state==0&&data==0xAA)
   {
       state=1;
       RxBuffer[0]=data;
   }
   else if((state==1)&&(data==0xAA))
   {
       state=2;
       RxBuffer[1]=data;
   }
   else if(state==2&&(data==0X05||data==0X01))
   {
       state=3;
       RxBuffer[2]=data;
   }
   else if(state==3&&data<60)
   {
       state = 4;
       RxBuffer[3]=data;    //数据长度
       _data_len = data;
       _data_cnt = 0;
   }
   else if(state==4&&_data_len>0)
   {
       _data_len--;
       RxBuffer[4+_data_cnt++]=data;  //存储数据，_data_len中不包括帧头、帧尾校验和
       if(_data_len==0){state = 5;}
   }
   else if(state==5)
   {
       state = 0;
       RxBuffer[4+_data_cnt]=data; //应该是最后一个数据,校验和
       parser_data2(RxBuffer,_data_cnt+5);
   }
   else
       state = 0;
}

void Serial_Thread::parser_data2(quint8 *data_buf, quint8 num)
{
    quint8 sum = 0;
    float commRoll,commPitch,commYaw;
    for(qint8 i=0;i<(num-1);i++)
        sum += *(data_buf+i);
    if(!(sum==*(data_buf+num-1)))		return;		//判断sum
    if(!(*(data_buf)==0xAA && *(data_buf+1)==0xAA))		return;		//判断帧头

    if(*(data_buf+2)==0X05)   //接收姿态信息
    {
        //这里存在一个量纲的变化
//        commRoll=0.01*((qint16)(*(data_buf+4)<< 8 | *(data_buf+5)));
//        commPitch=0.01*((qint16)(*(data_buf+6)<< 8 | *(data_buf+7)));
//        commYaw=0.01*((qint16)(*(data_buf+8)<< 8 | *(data_buf+9)));
//        current_Yaw=10;
        commRoll=*(data_buf+4);
        qDebug()<<"running7";
        emit sendATIOk(commRoll);
    }
    if(*(data_buf+2)==0X01)   //接收姿态信息
    {
        //这里存在一个量纲的变化
        commRoll=0.01*((qint16)(*(data_buf+4)<< 8 | *(data_buf+5)));
        commPitch=0.01*((qint16)(*(data_buf+6)<< 8 | *(data_buf+7)));
        commYaw=0.01*((qint16)(*(data_buf+8)<< 8 | *(data_buf+9)));
//        current_Yaw=10;
//        commRoll=*(data_buf+4);

        emit signal_send_att(commRoll,commPitch,commYaw);
    }
}
