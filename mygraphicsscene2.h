#ifndef MYGRAPHICSSCENE2_H
#define MYGRAPHICSSCENE2_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
class MainWindow;


class MyGraphicsScene2 : public QGraphicsScene
{
public:
    //constructor
    MyGraphicsScene2(MainWindow *w);

    //functions
    virtual bool eventFilter(QObject *object, QEvent *ev) override;
    void keyPressEvent(QKeyEvent * event);

    //elements
    MainWindow * mainWindow;

private:
    int mCursorX;
    int mCursorY;
};

#endif // MYGRAPHICSSCENE2_H
