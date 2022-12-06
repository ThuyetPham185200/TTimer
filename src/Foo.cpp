#include "Foo.h"



Foo::Foo(QObject *parent)
    : QObject(parent)
{

}

void Foo::run()
{
    connect(this, &Foo::signal, this, [] { std::cout << "activated foo new\n"; }, Qt::QueuedConnection);

    std::thread t([this] {
        int i = 0;
        while( i < 10)
        {
            i++;
            std::cout << "get event\n" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            emit signal();
        }

    });
    if (t.joinable()) t.detach();
//    while(1)
//    {
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//        std::cout << "main processing\n" << std::endl;
//    };
}

