#ifndef ELAPSING_H
#define ELAPSING_H
#include "fieldcontent.h"

class Elapsing : public FieldContent
{
private:
    int countdown;
    int maxCountdown;
public:
    Elapsing();
    void tick();
    void expire();
};

#endif // ELAPSING_H
