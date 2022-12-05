#ifndef FOO_H
#define FOO_H


#include <QTimer>
#include <thread>
#include <iostream>

class Foo : public QObject
{
    Q_OBJECT
public:
    Foo(QObject* parent = nullptr);

public slots:
    void run();

signals:
    void signal() const;
};

#endif // FOO_H
