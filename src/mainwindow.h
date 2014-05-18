#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>
#include <QWidget>
#include <QResizeEvent>
#include "playground.h"
#include "painttimer.h"

class PaintTimer;
#define DEFAULT_BLOCK_SIZE 48
#define MINIMUM_BLOCK_SIZE 16

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();


protected:
     void paintEvent(QPaintEvent *);
     void resizeEvent(QResizeEvent *event);
     void keyPressEvent(QKeyEvent *event);
//     void keyReleaseEvent(QKeyEvent *event);

private:
     QPixmap* images[17];

     int blockSize;
     PaintTimer *paint_tmr;
     Playground thePlayground;
};

#endif // MAINWINDOW_H
