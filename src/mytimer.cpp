#include "mytimer.h"


MyTimer::MyTimer(QObject *parent) :
    QTimer(parent)
{
    connect(this, SIGNAL(timeout()), this, SLOT(masterTick()));
    start(100);

}

void MyTimer::masterTick()
{
   // std::cout << "tick";// go through list and tick all elapsing objects there
    detach();
}
void MyTimer::attach(Elapsing *observer)
{
    elapsingList.push_front(observer);
}

void MyTimer::detach(/*Elapsing *observer*/)
{
    elapsingList.clear();
    //elapsingList.pop_back();

}
