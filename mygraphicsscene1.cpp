#include "mygraphicsscene1.h"
#include "mygraphicsscene2.h"
#include "mainwindow.h"

MyGraphicsScene1::MyGraphicsScene1(MainWindow *w) :
    mCursorX(0),
    mCursorY(0)
{
    installEventFilter(this);
    this->mainWindow = w;
    QPixmap bkgnd("C:/Users/M2IHM/Documents/projet_hap/img/backgroundimg.png");
    this->setBackgroundBrush(QBrush(bkgnd));
    this->setBackgroundBrush(QBrush(bkgnd.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
}

bool MyGraphicsScene1::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::MouseButtonPress) {
        qDebug() << "Mouse pressed on page 1";
    }

    return false;
}

void MyGraphicsScene1::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Escape) {
        this->mainWindow->close();
    }

    if (event->key() == Qt::Key_Right) {
        this->mainWindow->SetScene(new MyGraphicsScene2(this->mainWindow));
    }
}
