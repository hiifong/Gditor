#include "gbattery.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPen>


GBattery::GBattery(QWidget *parent)
    : QWidget{parent}
{

}

void GBattery::paintEvent(QPaintEvent *event)
{
    // 绘制界面组件
    QPainter painter(this);
    QRect rect(0,0,width(), height());              // 视口矩形
    painter.setViewport(rect);
    painter.setWindow(0,0,120,50);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);


    // 绘制电池边框
    QPen pen(colorBorder);
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);

    painter.setPen(pen);

    QBrush brush(colorBack);
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);

    rect.setRect(1,1,109,48);

    painter.drawRect(rect);

    brush.setColor(colorBorder);
    painter.setBrush(brush);
    rect.setRect(110,15,10,20);
    painter.drawRect(rect);

    //画电量柱
    if (powerLevelValue>warnLevelValue) //正常颜色电量柱
    {
        brush.setColor(colorPower);
        pen.setColor(colorPower);
    }
    else        //电量低电量柱
    {
        brush.setColor(colorWarning);
        pen.setColor(colorWarning);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    if (powerLevelValue>0)
    {
        rect.setRect(5,5,powerLevelValue,40);
        painter.drawRect(rect);     //画电量柱
    }

    //绘制电量百分比文字
    QFontMetrics  textSize(this->font());
    QString powStr=QString::asprintf("%d%%",powerLevelValue);
    QRect textRect=textSize.boundingRect(powStr);   //得到字符串的矩形区
    painter.setFont(this->font());
    pen.setColor(colorBorder);
    painter.setPen(pen);
    painter.drawText(55-textRect.width()/2, 23+textRect.height()/2,  powStr);

    event->accept();        //表示事件已处理
}

void GBattery::setPowerLevel(int pow)
{ //设置当前电量值
    powerLevelValue=pow;
    emit powerLevelChanged(pow); //发射信号
    repaint();
}

int GBattery::powerLevel()
{ //返回当前电量值
    return powerLevelValue;
}

void GBattery::setWarnLevel(int warn)
{//设置电量低阈值
    warnLevelValue=warn;
    repaint();
}

int GBattery::warnLevel()
{//读取电量低阈值
    return  powerLevelValue;
}

QSize GBattery::sizeHint()
{//设置组件的合适大小
    int H=this->height();
    int W=H*12/5;
    QSize   size(W,H);
    return size;
}
