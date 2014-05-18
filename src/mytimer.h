#ifndef MYTIMER_H
#define MYTIMER_H

#include <iostream>
#include <QTimer>
#include <list>
#include "elapsing.h"
#include "ground.h"
#include "corefire.h"
#include "extensionfire.h"
#include "endfire.h"


typedef std::vector< std::vector< Field* > > mapMatrix;

class MyTimer : public QTimer
{
    Q_OBJECT
public:
    explicit MyTimer(QObject *parent = 0, mapMatrix *_map = NULL);

    void attach(Elapsing *observer);
    void detach(/*Elapsing *observer*/);

private:
    std::list< Elapsing *> elapsingList;
    mapMatrix *map;

signals:

public slots:
    void masterTick();

};

#endif // MYTIMER_H
