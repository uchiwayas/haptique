#ifndef MYGRAPHICSSCENE3_H
#define MYGRAPHICSSCENE3_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class MainWindow;

class MyGraphicsScene3 : public QGraphicsScene
{
public:
    //constructor
    MyGraphicsScene3(MainWindow *w);

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

#endif // MYGRAPHICSSCENE3_H
