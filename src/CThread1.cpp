#include "CThread1.h"

CThread1::CThread1(QThread *parent)
    : QThread(parent)
{

}

void CThread1::run()
{
    std::cout << "thread 1 started\n" << std::endl;
    int i = 0;
    while(1)
    {
       msleep( 200 );
       i++;
       if(i%2 == 0)
          emit MySignal();
    }
}

//void CThread1::MySignal()
//{

//}
