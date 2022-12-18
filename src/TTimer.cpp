#include "TTimer.h"

static const bool IS_START = true;
static const bool IS_STOP = false;
static const bool SET_THREAT = true;
static const bool NOT_SET_THREAT = false;
static const bool TRUE = true;
static const int INVALID_MSEC = 0;
static const int INIT_MSEC = 1;
static const int INIT_TEMP_COUNT = 0;
static const int INIT_START = 0;

TTimer::TTimer(QObject *parent)
    : QObject(parent)
{
    this->isStart_ = IS_START;
    this->setThreat_ = SET_THREAT;
    tempCount_ = INIT_TEMP_COUNT;
    tempInitStart_ = INIT_START;
}

TTimer::~TTimer()
{
}

void TTimer::start()
{
    msec_ = INIT_MSEC;
    isStart_ = IS_START;
    tempCount_ = INIT_TEMP_COUNT;
    tempInitStart_ = INIT_START;
    if(setThreat_ && tempInitStart_ == 0)
    {
        tempInitStart_++;
        t_ = std::move(std::thread(&TTimer::getEvent, this));
        t_.detach();
    }
}
void TTimer::start(int msec)
{
    msec_ = msec;
    isStart_ = IS_START;
    if(setThreat_ && tempInitStart_ != INIT_START)
    {
        setThreat_ = NOT_SET_THREAT;
        t_ = std::move(std::thread(&TTimer::getEvent, this));
        t_.detach();
    }
}

void TTimer::stop()
{
    isStart_ = IS_STOP;
    setThreat_ = SET_THREAT;
    std::cout << "stop timer" << std::endl;
}

void TTimer::getEvent()
{
    std::lock_guard<std::mutex> lk(m_);
    while(TRUE)
    {
        if(msec_ == INVALID_MSEC) msec_ = INIT_MSEC;
        std::this_thread::sleep_for(std::chrono::milliseconds(msec_));
        if (msec_ == INIT_MSEC && tempCount_ == INIT_TEMP_COUNT)
        {
            tempCount_++;
            emit timeout();
            isStart_ = false;
        }
        if(isStart_)
        {
            emit timeout();
        }
        else
        {
            break;
        }
    }
    std::cout << "out of event loop\n";
}
