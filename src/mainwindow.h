#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>
#include <QWidget>
#include <QResizeEvent>
#include "playground.h"

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

private:
     QPixmap* images[11];

     int blockSize;

     Playground thePlayground;
};

#endif // MAINWINDOW_H
