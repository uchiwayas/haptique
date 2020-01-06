#ifndef MYGRAPHICSSCENE1_H
#define MYGRAPHICSSCENE1_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QMainWindow>
#include "mygraphicsscene.h"

class MainWindow;

class MyGraphicsScene1 : public MyGraphicsScene
{
public:
    //constructor

    /**
     * @brief MyGraphicsScene1::MyGraphicsScene1
     * Constructeur
     * @param w : window
     * @param mHap : gestion haptique
     */
    MyGraphicsScene1(MainWindow *w, GestionHaptique *mHap);

    //functions

    /**
     * @brief MyGraphicsScene1::eventFilter.
     * Gère les evenements souris
     * @param object
     * @param ev
     */
    bool eventFilter(QObject *object, QEvent *ev); //event souris

};

#endif // MYGRAPHICSSCENE1_H
