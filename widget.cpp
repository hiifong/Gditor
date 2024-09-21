#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->b->move(100,100);
    this->l->setGeometry(100,130, 100, 30);
    this->s->setGeometry(100,160, 100, 20);
    this->s->setRange(0,100);
    this->s->setOrientation(Qt::Orientation::Horizontal);
    this->l->setText("Hello World!");
    connect(this->s, &QSlider::valueChanged, this, &Widget::on_horizontal_slider_valueChanged);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontal_slider_valueChanged(int value)
{
    this->b->setPowerLevel(value);      //设置电池电量
    QString  str=QString::asprintf("当前电量：%d %%",value);
    this->l->setText(str);
}
