#ifndef MYGRAPHICSSCENE3_H
#define MYGRAPHICSSCENE3_H
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
#include "mygraphicsscene.h"

class MainWindow;

class MyGraphicsScene3 : public MyGraphicsScene
{
public:
    //constructor
    /**
     * @brief MyGraphicsScene3::MyGraphicsScene3
     * Constructeur
     * @param w : window
     * @param mHap : gestion haptique
     */
    MyGraphicsScene3(MainWindow *w, GestionHaptique *mHap);

    //functions
    /**
     * @brief MyGraphicsScene2::eventFilter.
     * Gère les evenements souris
     * @param object
     * @param ev
     */
    bool eventFilter(QObject *object, QEvent *ev); //event souris

    //vars
    int timer = 200;
};

#endif // MYGRAPHICSSCENE3_H
