#ifndef MYGRAPHICSSCENE1_H
#define MYGRAPHICSSCENE1_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QMainWindow>
class MainWindow;


class MyGraphicsScene1 : public QGraphicsScene
{
public:
    //constructor
    MyGraphicsScene1(MainWindow *w);

    //functions
    virtual bool eventFilter(QObject *object, QEvent *ev) override;
    void keyPressEvent(QKeyEvent * event);

    //elements
    MainWindow * mainWindow;

private:
    int mCursorX;
    int mCursorY;
};

#endif // MYGRAPHICSSCENE1_H
