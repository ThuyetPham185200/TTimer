#ifndef CTHREAD1_H
#define CTHREAD1_H

#include <QObject>
#include <iostream>
#include <QThread>

class CThread1 : public QThread
{
    Q_OBJECT
public:
    CThread1(QThread *parent = nullptr);
    void run();

signals:
    void MySignal();
};

#endif // CTHREAD1_H
