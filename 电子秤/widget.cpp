#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Btn_Cal_clicked()
{
    // read num and price
    QString str = ui->Edit_num->text();
    float num = str.toFloat();
    str = ui->Edit_price->text();
    float price = str.toFloat();

    // calculate the result
    float sum = num * price;
    str = str.sprintf("%.2f", sum);
    ui->Edit_sum->setText(str);

}
