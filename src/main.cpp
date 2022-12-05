#include <QCoreApplication>
#include "MyObject.h"
#include "CThread1.h"
#include "CThread2.h"
#include "Foo.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CThread1 oThread1;
    CThread2 oThread2;
    MyObject myObject;
    /////////////////
    Foo* b = new Foo(&a);
    QTimer::singleShot(0, b, &Foo::run);
    /////////////////
    QObject::connect( & oThread1, SIGNAL( MySignal() ),
        & myObject, SLOT( MySlot() ) );
    oThread2.start();
    myObject.moveToThread(&oThread2);
    oThread1.start();
    return a.exec();
}

