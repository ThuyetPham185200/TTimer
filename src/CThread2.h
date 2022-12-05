#ifndef CTHREAD2_H
#define CTHREAD2_H

#include <QObject>
#include <iostream>
#include <QThread>

class CThread2 : public QThread
{
    Q_OBJECT
public:
    CThread2(QThread *parent = nullptr);
    void run();

};

#endif // CTHREAD2_H
