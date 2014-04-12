#include "mainwindow.h"
#include "playground.h"
#include <iostream>

MainWindow::MainWindow()
{
    setWindowTitle(tr("BomberGirl"));

    groundImage = new QPixmap();
    bombImage = new QPixmap();

    std::cout << groundImage->load(":/ground.png") << std::endl;
    std::cout <<   bombImage->load(":/bomb.png")   << std::endl;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(255, 0, 0)));

    painter.drawEllipse(200, 100, 100, 100);
    painter.drawPixmap(50, 50, *groundImage);
    painter.drawPixmap(50+48, 50, *groundImage);
    painter.drawPixmap(50+48, 50, *bombImage);

    //Playground thePlayground = Playground();
}
