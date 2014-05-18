#include "painttimer.h"


PaintTimer::PaintTimer(QObject *parent, MainWindow *win) :   QTimer(parent)
{

    connect(this, SIGNAL(timeout()), this, SLOT(masterPaint()));
    start(20);
    window = win;

}

void PaintTimer::masterPaint(){
    window->update();
    //std::cout << "paint"<<std::endl;
}
