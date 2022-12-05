#include "MyObject.h"

MyObject::MyObject(QObject *parent)
    : QObject(parent) {}

MyObject::~MyObject() {}
void MyObject::MySlot()
{
    std::cout << "slot called" << std::endl;
}
