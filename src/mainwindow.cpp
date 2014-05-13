#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
{
    // Initialize window
    blockSize = DEFAULT_BLOCK_SIZE;
    resize(blockSize*13, blockSize*11);
    setWindowTitle("BomberGirl");

    // Enable reception of key events
    setEnabled(true);

    // load images from built-in ressource
    images[groundImage] = new QPixmap(":/ground.png");
    images[bombImage] = new QPixmap(":/bomb.png");
    images[wallImage] = new QPixmap(":/wall.png");
    images[brickImage] = new QPixmap(":/brick.png");

    images[bombItemImage] = new QPixmap(":/bombItem.png");
    images[flashItemImage] = new QPixmap(":/flashItem.png");
/*
    images[coreFireImage] = new QPixmap(":/coreFire.png");
    images[extensionFireImage ] = new QPixmap(":/extensionFire.png");
    images[endFireImage] = new QPixmap(":/endFire.png");
    */
    ////////////////////////////////////////////////////////////////////////
    // For Debuging - no images created yet
    ////////////////////////////////////////////////////////////////////////

    images[coreFireImage] = new QPixmap(":/brick.png");
    images[extensionFireImage ] = new QPixmap(":/brick.png");
    images[endFireImage] = new QPixmap(":/brick.png");
    ////////////////////////////////////////////////////////////////////////

    images[player1Image] = new QPixmap(":/player1.png");
    images[player2Image] = new QPixmap(":/player2.png");

    // Enabele Master Tick
    //MainWindow::tick = new MyTimer(this);

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // draw the basic map
    Ground *pnt;
    for(int x = 0; x < 13; x++)
    {
        for(int y = 0; y < 11; y++)
        {

            // ground zeichnen, player zeichnen, brick zeichnen
            // draw groudn field

            painter.drawPixmap(blockSize*x, blockSize*y, blockSize, blockSize, *images[thePlayground.map[x][y]->image]);


            // draw item if there is any
            if(thePlayground.map[x][y]->image == groundImage){
                 pnt = static_cast<Ground *>(thePlayground.map[x][y]);
                 if(pnt->itemElement != NULL){
                     painter.drawPixmap(blockSize*x, blockSize*y, blockSize, blockSize, *images[pnt->itemElement->image]);
                 }
                 if(pnt->brickElement != NULL){
                     painter.drawPixmap(blockSize*x, blockSize*y, blockSize, blockSize, *images[brickImage]);

                  }
                  if(pnt->bombElement != NULL){
                      painter.drawPixmap(blockSize*x, blockSize*y, blockSize, blockSize, *images[bombImage]);
                  }
                  if(pnt->fireElement != NULL){
                      painter.drawPixmap(blockSize*x, blockSize*y, blockSize, blockSize, *images[pnt->fireElement->image]);
                  }
            }


        }
    }

    // draw the two players
    painter.drawPixmap(blockSize*thePlayground.player1.x, blockSize*thePlayground.player1.y,
                       blockSize, blockSize, *images[player1Image]);
    painter.drawPixmap(blockSize*thePlayground.player2.x, blockSize*thePlayground.player2.y,
                       blockSize, blockSize, *images[player2Image]);

    // draw fire if there is any
    // todo
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
/*void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    std::cout << "released: " << event->text().toStdString() << std::endl;
}*/

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //std::cout << "Key: " << event->text().toStdString() << std::endl;
    switch(event->key()) {
    case Qt::Key_A:
        thePlayground.player1.walk(LEFT, thePlayground.map);
        break;
    case Qt::Key_D:
        thePlayground.player1.walk(RIGHT, thePlayground.map);
        break;
    case Qt::Key_W:
        thePlayground.player1.walk(UP, thePlayground.map);
        break;
    case Qt::Key_S:
        thePlayground.player1.walk(DOWN, thePlayground.map);
        break;
    case Qt::Key_Tab:
        thePlayground.player1.placeBomb(thePlayground.map);
        break;


    case Qt::Key_Left:
        thePlayground.player2.walk(LEFT, thePlayground.map);
        break;
    case Qt::Key_Right:
        thePlayground.player2.walk(RIGHT, thePlayground.map);
        break;
    case Qt::Key_Up:
        thePlayground.player2.walk(UP, thePlayground.map);
        break;
    case Qt::Key_Down:
        thePlayground.player2.walk(DOWN, thePlayground.map);
        break;
    case Qt::Key_Period:
        thePlayground.player2.placeBomb(thePlayground.map);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }

    repaint();
}

