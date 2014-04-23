#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include <list>
#include "elapsing.h"

class MyTimer : public QTimer
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = 0);

    void attach(Elapsing &observer);
    void detach(Elapsing &observer);

private:
//    std::list< *Elapsing > elapsingList;

signals:

public slots:
    void masterTick();

};

#endif // MYTIMER_H
