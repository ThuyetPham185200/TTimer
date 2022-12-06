#include <QCoreApplication>
#include "MyObject.h"
#include "CThread1.h"
#include "CThread2.h"
#include "Foo.h"
#include "TTimer.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TTimer *timer_ = new TTimer;
    timer_->run();
    //timer_->myTimerEvent();
    timer_->process();
    return a.exec();
}



//CThread1 oThread1;
//CThread2 oThread2;
//MyObject myObject;
///////////////////
//Foo b ;
//b.run();
///////////////////
//QObject::connect( & oThread1, SIGNAL( MySignal() ),
//    & myObject, SLOT( MySlot() ) );
//oThread2.start();
//myObject.moveToThread(&oThread2);
//oThread1.start();
