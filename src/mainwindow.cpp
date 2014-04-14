#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
{
    setWindowTitle("BomberGirl");

    blockSize = DEFAULT_BLOCK_SIZE;
    resize(blockSize*13, blockSize*11);

    // load images from built-in ressource
    images[groundImage] = new QPixmap(":/ground.png");
    images[bombImage] = new QPixmap(":/bomb.png");
    images[wallImage] = new QPixmap(":/wall.png");
    images[brickImage] = new QPixmap(":/brick.png");
    /*
    images[bombItemImage] = new QPixmap(":/bombItem.png");
    images[flashItemImage] = new QPixmap(":/flashItem.png");

    images[coreFireImage] = new QPixmap(":/coreFire.png");
    images[extensionFireImage] = new QPixmap(":/extensionFire.png");
    images[endFireImage] = new QPixmap(":/endFire.png");

    images[player1Image] = new QPixmap(":/player1.png");
    images[player2Image] = new QPixmap(":/player2.png");
    */
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for(int x = 0; x < 13; x++)
    {
        for(int y = 0; y < 11; y++)
        {
            painter.drawPixmap(blockSize*x, blockSize*y, blockSize, blockSize, *images[thePlayground.map[x][y]->image]);
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
