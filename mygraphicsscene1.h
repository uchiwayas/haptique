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
    MyGraphicsScene1(MainWindow *w, GestionHaptique *mHap);

    //functions
    bool eventFilter(QObject *object, QEvent *ev);
};

#endif // MYGRAPHICSSCENE1_H
