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
    /**
     * @brief MyGraphicsScene2::MyGraphicsScene2
     * Constructeur
     * @param w : window
     * @param mHap : gestion haptique
     */
    MyGraphicsScene2(MainWindow *w, GestionHaptique *mHap);

    //functions
    /**
     * @brief MyGraphicsScene2::eventFilter.
     * Gère les evenements souris
     * @param object
     * @param ev
     */
    virtual bool eventFilter(QObject *object, QEvent *ev) override; //event souris

    /**
     * @brief MyGraphicsScene2::detectCollisionCube
     * Detecte si la souris est dans le cube
     * @param cube
     * @param x : pos x de la souris
     * @param y : pos y de la souris
     * @return true si la souris est dans le cube, false sinon
     */
    bool detectCollisionCube(Cube* cube, int x, int y);             //detecte si la souris est sur le cube

    /**
     * @brief MyGraphicsScene2::checkIfPuzzleSolved
     * check si les 3 cubes sont dans les bons emplacements
     *  puis passe à l'état 3 si c'est le cas
     */
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
