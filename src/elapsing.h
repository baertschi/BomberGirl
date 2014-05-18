#ifndef ELAPSING_H
#define ELAPSING_H
#include "fieldcontent.h"

class Elapsing : public FieldContent
{
private:

    int maxCountdown;
public:
    Elapsing();
    void tick();
    void expire();

    int countdown;
};

#endif // ELAPSING_H
