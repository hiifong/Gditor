#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "components/gbattery.h"
#include <QLabel>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    GBattery * b = new GBattery(this);
    QLabel * l = new QLabel(this);
    QSlider * s = new QSlider(this);

private slots:
    void on_horizontal_slider_valueChanged(int value);
};
#endif // WIDGET_H
