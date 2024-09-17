#ifndef GLINENUMBER_H
#define GLINENUMBER_H

#include <QWidget>

class GLineNumber : public QWidget
{
    Q_OBJECT
public:
    explicit GLineNumber(QWidget *parent = nullptr);


private:
    qint64 currentLineNumber;

signals:
};

#endif // GLINENUMBER_H
