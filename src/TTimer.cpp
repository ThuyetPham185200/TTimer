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
    this->id = INV_TIMER;
    this->inter = INIT_INTER;
    this->del = INIT_DEL;
    this->single = INIT_SINGLE;
    this->nulltimer = INIT_NULLTIMER;
}

TTimer::~TTimer()
{
    std::cout << "call destructor\n";
    if (id != INV_TIMER)
        stop();
}

void TTimer::start(int msec)
{
    inter = msec;
    start();
}

void TTimer::start()
{
    count++;
    //printf("start timer: %d\n", count);
    if (id != INV_TIMER)
        stop();
    nulltimer = (!inter && single);
    id = QObject::startTimer(inter);
    //QObject::startTimer(inter);
}

void TTimer::stop()
{
    if (id != INV_TIMER) {
        //printf("stop timer\n");
        QObject::killTimer(id);
        id = INV_TIMER;
    }
}

void TTimer::timerEvent(QTimerEvent* event)
{
    //printf("call event: %d\n", count);
    if (event->timerId() == id) {
        if (single)
            stop();
        emit timeout();
    }
}
