#include "Foo.h"



Foo::Foo(QObject *parent)
    : QObject(parent)
{

}

void Foo::run()
{
    connect(this, &Foo::signal, this, [] { std::cout << "activated foo\n"; }, Qt::QueuedConnection);

    std::thread t([this] { emit signal(); });
    if (t.joinable()) t.join();
}
