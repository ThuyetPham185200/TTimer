#include "TTimer.h"

static const int INV_TIMER = -1;
static const int INIT_INTER = 0;
static const int INIT_DEL = 0;
static const int INIT_SINGLE = 0;
static const int INIT_NULLTIMER = 0;
int count = 0;
TTimer::TTimer(QObject *parent)
    : QObject(parent)
{

}

TTimer::~TTimer()
{

}

void TTimer::start(int msec)
{
    msec_ = msec;
    std::cout << "isStart in start: " << isStart_ << std::endl;
    if(isStart_)
    {
        msec_ = msec;
        isStart_ = false;
        std::cout << "start timer inside: " << count_ << std::endl;
        t_ = std::move(std::thread(&TTimer::getEvent, this, msec));
        t_.detach();
    }
}

void TTimer::stop()
{
    std::cout << "stop outside" << std::endl;
    mutex_.lock();
    std::cout << "isStart in stop: " << isStart_ << std::endl;
    std::cout << "isStart int stop: " << isStart_ << std::endl;
    mutex_.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //emit timeout();
}

void TTimer::getEvent(int msec)
{
    while(!stop)
    {
        if(!isStart_)
        {
            std::cout << "isStart in event: " << isStart_ << std::endl;
            std::cout << "break event: " << msec_ << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(msec_));
            mutex_.lock();
            mutex_.unlock();
            if (count_ == 10)
            {
                t_.~thread();
                break;
            }
            emit timeout();
        }
        else
        {
            std::cout << "kill thread"<< std::endl;

            break;
        }
    }
}

void TTimer::myTimerEvent()
{
    tEvent_ = std::move(std::thread(&TTimer::stop, this));
    tEvent_.detach();
}


void TTimer::process()
{
    count_ ++;
    if (count_ == 10)
    {
        std::cout << "kill thread"<< std::endl;
        t_.~thread();
        //std::terminate();
    }
    start(100*count_);
    std::cout << "main processing---------------------------------" << count_ << std::endl;
}

void TTimer::run()
{
    std::cout << "oke fine" << std::endl;
    connect(this, &TTimer::timeout, this, &TTimer::process);
}


