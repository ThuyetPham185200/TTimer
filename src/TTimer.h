#ifndef TTIMER_H
#define TTIMER_H

#include <QObject>
#include <QEvent>
#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>


class TTimer : public QObject
{
    Q_OBJECT
public:
    TTimer(QObject *parent = Q_NULLPTR);
    ~TTimer();
    void start(int msec);
    void start();
    void stop();
    void getEvent(int msec);
    void myTimerEvent();
    void eventFunc();
signals:
    void timeout();
public slots:
    void run();
    void process();
private:
    int msec_;
    int id_ = 0;
    int count_ = 0;
    std::mutex mutex_;
    std::thread t_;
    std::thread tEvent_;
    bool isStart_ = true;
    bool isStop_ = false;
};

#endif // TTIMER_H
