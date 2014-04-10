#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle(tr("BomberGirl"));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(255, 0, 0)));

    painter.drawEllipse(200, 100, 100, 100);
}
