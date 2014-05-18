#ifndef PAINTTIMER_H
#define PAINTTIMER_H


#include <QTimer>
#include "mainwindow.h"
class MainWindow;

class PaintTimer : public QTimer
{
    Q_OBJECT
public:
    explicit PaintTimer(QObject *parent = 0, MainWindow *win = NULL);

signals:

public slots:
    void masterPaint();

private:
    MainWindow *window;

};
#endif // PAINTTIMER_H
