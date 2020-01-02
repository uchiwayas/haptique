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
    MyGraphicsScene2(MainWindow *w, GestionHaptique *mHap);

    //functions
    virtual bool eventFilter(QObject *object, QEvent *ev) override; //event souris
    bool detectCollisionCube(Cube* cube, int x, int y);             //detecte si la souris est sur le cube
    void checkIfPuzzleSolved();                                     //check si on a résoud le puzzle des cubes

private:
    int savedX;         //derniere position x de la souris sur le cube
    int savedY;         //derniere position y de la souris sur le cube

    Cube* cubeLourd;    //cube lourd
    Cube* cubeMoyen;    //cube moyen
    Cube* cubeLeger;    //cube leger

    QGraphicsPixmapItem* lourdImg;  //image cube lourd
    QGraphicsPixmapItem* moyenImg;  //image cube moyen
    QGraphicsPixmapItem* legerImg;  //image cube leger
};

#endif // MYGRAPHICSSCENE2_H
