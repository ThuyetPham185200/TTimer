#include "CThread2.h"

CThread2::CThread2(QThread *parent)
    : QThread(parent)
{

}

void CThread2::run()
{
    std::cout << "thread 2 started\n" << std::endl;
    exec();
}
