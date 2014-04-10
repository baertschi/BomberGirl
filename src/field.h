#ifndef FIELD_H
#define FIELD_H
#include <QImage>

class Field
{
    int x, y;
    QImage image;
public:
    Field();
    int onStep();
};

#endif // FIELD_H
