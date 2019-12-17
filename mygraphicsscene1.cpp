#include "mygraphicsscene2.h"
#include "mainwindow.h"

MyGraphicsScene1::MyGraphicsScene1(MainWindow *w) :
    QGraphicsScene(w),
    mCursorX(0),
    mCursorY(0)
{
    this->setSceneRect(0,0,1024,768);

    installEventFilter(this);
    this->mainWindow = w;
    QPixmap bkgnd("C:/Users/M2IHM/Documents/projet_hap/img/backgroundimg.png");
    this->setBackgroundBrush(QBrush(bkgnd));
    this->setBackgroundBrush(QBrush(bkgnd.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));


    lbl = new QLabel("Hello my firneifneoin pô,rjghpemor,j msolp,g", this->mainWindow);
    lbl->setFixedWidth(600);
    lbl->setFixedHeight(75);
    lbl->showFullScreen();
    lbl->setAlignment(Qt::AlignCenter);

    QPixmap owo("C:/Users/M2IHM/Documents/projet_hap/img/fond.png");
    QGraphicsView* view = new QGraphicsView(this);
    monImage = new QGraphicsPixmapItem(owo);
    this->addItem(monImage);
}

bool MyGraphicsScene1::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::GraphicsSceneMouseMove && this->buttonPressed)
    {
         QMouseEvent* mouseEvent = (QMouseEvent*)ev;
         if (mouseEvent->type() == QMouseEvent::GraphicsSceneMouseMove)
         {
             mCursorX = QCursor::pos().x();
             mCursorY = QCursor::pos().y();

             lbl->setGeometry(mCursorX, mCursorY, 600, 75);
             monImage->setPos(mCursorX, mCursorY);
             qDebug() << lbl->geometry().x();
         }
    }

    else if (ev->type() == QEvent::GraphicsSceneMousePress)
    {
         this->buttonPressed = true;
    }

    else if (ev->type() == QEvent::GraphicsSceneMouseRelease)
    {
         this->buttonPressed = false;
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
