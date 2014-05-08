#include "mytimer.h"


MyTimer::MyTimer(QObject *parent) :
    QTimer(parent)
{
    connect(this, SIGNAL(timeout()), this, SLOT(masterTick()));
    start(100);

}

void MyTimer::masterTick()
{
    std::cout << "tick";// go through list and tick all elapsing objects there
    detach();
}
void MyTimer::attach(Elapsing *observer)
{
    elapsingList.push_front(observer);
}

void MyTimer::detach(/*Elapsing *observer*/)
{
    std::list<Elapsing *>::iterator it;
    std::list<Elapsing *>::iterator iStart = elapsingList.begin();
    std::list<Elapsing *>::iterator iEnd = elapsingList.end();
    if(elapsingList.empty() == false){
        for(it = iStart; it != iEnd; it++){
            (*it)->onBurn();
        }

        elapsingList.clear();
    }

    //elapsingList.pop_back();


}
