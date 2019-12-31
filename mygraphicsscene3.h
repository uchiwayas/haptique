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
    MyGraphicsScene3(MainWindow *w);

    //functions
    bool eventFilter(QObject *object, QEvent *ev);
};

#endif // MYGRAPHICSSCENE3_H
