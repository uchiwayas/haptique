#ifndef MYGRAPHICSSCENE2_H
#define MYGRAPHICSSCENE2_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "cube.h"

class MainWindow;


class MyGraphicsScene2 : public QGraphicsScene
{
public:
    //constructor
    MyGraphicsScene2(MainWindow *w);

    //functions
    virtual bool eventFilter(QObject *object, QEvent *ev) override;
    void keyPressEvent(QKeyEvent * event);
    bool checkGoNext();
    bool detectCollisionCube(Cube* cube, int x, int y);
    void checkIfPuzzleSolved();

    //elements
    MainWindow * mainWindow;

private:
    int mCursorX;
    int mCursorY;

    int savedX;
    int savedY;

    QLabel* lbl;
    QGraphicsPixmapItem* fondBlanc;

    //etat du jeu
    int state = 0;
    QPixmap backgroundImg;

    Cube* cubeLourd;
    Cube* cubeMoyen;
    Cube* cubeLeger;

    QGraphicsPixmapItem* lourdImg;
    QGraphicsPixmapItem* moyenImg;
    QGraphicsPixmapItem* legerImg;
};

#endif // MYGRAPHICSSCENE2_H
