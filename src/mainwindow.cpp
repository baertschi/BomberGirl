#include "mainwindow.h"
#include "playground.h"
#include <iostream>

MainWindow::MainWindow()
{
    setWindowTitle("BomberGirl");

    blockSize = DEFAULT_BLOCK_SIZE;
    resize(blockSize*13, blockSize*11);

    // load images from built-in ressource
    groundImage = new QPixmap(":/ground.png");
    bombImage = new QPixmap(":/bomb.png");
    wallImage = new QPixmap(":/wall.png");
    brickImage = new QPixmap(":/brick.png");
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    /*
    painter.drawPixmap(0*blockSize, 0, blockSize, blockSize, *groundImage);
    painter.drawPixmap(1*blockSize, 0, blockSize, blockSize, *groundImage);
    painter.drawPixmap(2*blockSize, 0, blockSize, blockSize, *wallImage);
    painter.drawPixmap(3*blockSize, 0, blockSize, blockSize, *brickImage);
    painter.drawPixmap(4*blockSize, 0, blockSize, blockSize, *groundImage);

    painter.drawPixmap(1*blockSize, 0, blockSize, blockSize, *bombImage);
    //painter.drawPixmap(4*blockSize, 0, blockSize, blockSize, *player1Image);
*/
    for(int x = 0; x < 13; x++)
    {
        for(int y = 0; y < 11; y++)
        {
            painter.drawPixmap(blockSize*x, blockSize*y, blockSize, blockSize, *thePlayground.map[x][y]->image);
        }
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    // gets called every time the window is resized.
    // Window width is kept as it is, but the height is being scaled accordingly.
    if((float)event->size().width() / (float)event->size().height() != 13.0 / 11.0)
    {
        // if aspect ratio isn't proportional to 13*11, change.
        blockSize = event->size().width()/13.0;
        if(blockSize < MINIMUM_BLOCK_SIZE)
            blockSize = 16;
        resize(blockSize*13, blockSize*11);
    }
}
