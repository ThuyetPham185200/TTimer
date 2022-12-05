#ifndef TTIMER_H
#define TTIMER_H

#include <QObject>
#include <QEvent>
#include <chrono>
#include <iostream>
#include <thread>
class TTimer : public QObject
{
    Q_OBJECT
public:
    TTimer(QObject *parent = Q_NULLPTR);
    ~TTimer();
    inline bool isActive() const { return id >= 0; }
    int timerId() const { return id; }

    void setInterval(int msec);
    int interval() const { return inter; }


public Q_SLOTS:
    void start(int msec);
    void start();
    void stop();

Q_SIGNALS:
    void timeout();

protected:
    void timerEvent(QTimerEvent *);
private:
    Q_DISABLE_COPY(TTimer)

    inline int startTimer(int){ return -1;}
    inline void killTimer(int){}

    int id, inter, del;
    uint single : 1;
    uint nulltimer : 1;
};

#endif // TTIMER_H
