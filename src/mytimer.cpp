#include "mytimer.h"

MyTimer::MyTimer(QObject *parent) :
    QTimer(parent)
{
    connect(this, SIGNAL(timeout()), this, SLOT(masterTick()));
    start(100);
}

void MyTimer::masterTick()
{
    // go through list and tick all elapsing objects there
}
