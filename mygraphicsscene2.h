#ifndef MYGRAPHICSSCENE2_H
#define MYGRAPHICSSCENE2_H
#include <QDebug>
#include <QMouseEvent>
#include "cube.h"
#include "mygraphicsscene.h"

class MainWindow;


class MyGraphicsScene2 : public MyGraphicsScene
{
public:
    //constructor
    MyGraphicsScene2(MainWindow *w);

    //functions
    virtual bool eventFilter(QObject *object, QEvent *ev) override;
    bool detectCollisionCube(Cube* cube, int x, int y);
    void checkIfPuzzleSolved();

private:
    int savedX;
    int savedY;

    Cube* cubeLourd;
    Cube* cubeMoyen;
    Cube* cubeLeger;

    QGraphicsPixmapItem* lourdImg;
    QGraphicsPixmapItem* moyenImg;
    QGraphicsPixmapItem* legerImg;
};

#endif // MYGRAPHICSSCENE2_H
