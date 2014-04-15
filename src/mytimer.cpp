#include "mytimer.h"

MyTimer::MyTimer(QObject *parent) :
    QTimer(parent)
{
    connect(this, SIGNAL(timeout()), this, SLOT(tickManager()));
    start(100);
}

void MyTimer::tickManager()
{
    // go through list and tick all elapsing objects there
}
