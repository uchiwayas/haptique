#ifndef MYGRAPHICSSCENE1_H
#define MYGRAPHICSSCENE1_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class MainWindow;

class MyGraphicsScene1 : public QGraphicsScene
{
public:
    //constructor
    MyGraphicsScene1(MainWindow *w);

    //functions
    bool eventFilter(QObject *object, QEvent *ev);
    void keyPressEvent(QKeyEvent * event);
    bool checkGoNext();

    //elements
    MainWindow * mainWindow;

private:
    int mCursorX;
    int mCursorY;
    QLabel* lbl;
    bool buttonPressed = false;
    QGraphicsPixmapItem* fondBlanc;

    //etat du jeu
    int state = 0;
    QPixmap backgroundImg;
};

#endif // MYGRAPHICSSCENE1_H
