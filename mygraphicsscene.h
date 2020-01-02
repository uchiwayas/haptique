#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <gestionhaptique.h>

class MainWindow;

class MyGraphicsScene : public QGraphicsScene
{
public:
    //constructor
    MyGraphicsScene(MainWindow *w, GestionHaptique *mHap);

    //functions
    bool checkGoNext();
    void keyPressEvent(QKeyEvent * event);

    //elements
    MainWindow * mainWindow;
    int mCursorX;
    int mCursorY;
    QLabel* lbl;
    QGraphicsPixmapItem* fondBlanc;

    //etat du jeu
    int state = 0;
    QPixmap backgroundImg;

    //haptique
    GestionHaptique *mHaptique;
};

#endif // MYGRAPHICSSCENE_H
