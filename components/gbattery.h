#ifndef GBATTERY_H
#define GBATTERY_H

#include <QWidget>

class GBattery : public QWidget
{
    Q_OBJECT
    // 自定义属性
    Q_PROPERTY(int powerLevel READ powerLevel WRITE setPowerLevel NOTIFY powerLevelChanged)
    Q_PROPERTY(int warnLevel READ warnLevel WRITE setWarnLevel)

private:
    QColor colorBack = Qt::white;   // 背景色
    QColor colorBorder = Qt::black; // 电池框边框颜色
    QColor colorPower = Qt::green;  // 电量柱颜色
    QColor colorWarning = Qt::red;  // 低电量颜色
    int powerLevelValue = 60;       // 电量值，0~100，属性powerLevel的存储变量
    int warnLevelValue = 20;        // 低电量阈值，属性warnLevel的存储变量

protected:
    void paintEvent(QPaintEvent *event);    // 组件绘制并显示效果

public:
    explicit GBattery(QWidget *parent);
    void setPowerLevel(int pow);        // 设置当前电量值
    int powerLevel();                   // 返回当前电量值
    void setWarnLevel(int warn);        // 设置低电量阈值
    int warnLevel();                    // 返回低电量阈值
    QSize sizeHint();                   // 重定义的函数，设置组件的合适大小

signals:
    void powerLevelChanged(int);         // 自定义信号
};

#endif // GBATTERY_H
