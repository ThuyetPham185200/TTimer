#ifndef MYOBJECT_H
#define MYOBJECT_H
#include <QObject>
#include <iostream>
#include <QThread>

class MyObject : public QObject
{
    Q_OBJECT
public:
    MyObject(QObject *parent = nullptr);
    ~MyObject();
public slots:
    void MySlot();
};

#endif // MYOBJECT_H
