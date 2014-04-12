#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>
#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

protected:
     void paintEvent(QPaintEvent *);

private:
     QPen pen;
     QPixmap* groundImage;
     QPixmap* bombImage;
};

#endif // MAINWINDOW_H
