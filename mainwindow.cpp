#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->b->setPowerLevel(value);      //设置电池电量
    // QString  str=QString::asprintf("当前电量：%d %%",value);
    // this->l->setText(str);
}
