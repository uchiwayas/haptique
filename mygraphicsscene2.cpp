#include "mygraphicsscene2.h"
#include "mainwindow.h"

MyGraphicsScene2::MyGraphicsScene2(MainWindow *w) :
    mCursorX(0),
    mCursorY(0)
{
    installEventFilter(this);
    this->mainWindow = w;
    QPixmap bkgnd("C:/Users/M2IHM/Documents/projet_hap/img/backgroundimg2.png");
    this->setBackgroundBrush(QBrush(bkgnd.scaled(w->width(), w->height(), Qt::IgnoreAspectRatio)));
}

bool MyGraphicsScene2::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::MouseButtonPress) {
        qDebug() << "Mouse pressed on page 1";
    }

    return false;

    /*
    if (ev->type() == QEvent::MouseButtonPress) {

          QMouseEvent* mouseEvent = (QMouseEvent*)ev;
          if (mouseEvent->type() == QMouseEvent::MouseButtonPress)
         {
             mCursorX = mouseEvent->x();
             mCursorY = mouseEvent->y();

             if (mCursorX > 900) {
                 //close();
             }
          }
    }

   return false;
    */

}

void MyGraphicsScene2::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Escape) {
        this->mainWindow->close();
    }

    if (event->key() == Qt::Key_Left) {
        this->mainWindow->SetScene(new MyGraphicsScene1(this->mainWindow));
    }
}
