#include "mygraphicsscene.h"
#include "mainwindow.h"

MyGraphicsScene::MyGraphicsScene(MainWindow *w) :
    QGraphicsScene(w),
    mCursorX(0),
    mCursorY(0)
{
    this->setSceneRect(0,0,1024,768);

    installEventFilter(this);
    this->mainWindow = w;


    lbl = new QLabel("", this->mainWindow);
    lbl->setWordWrap(true);
    lbl->setFixedWidth(600);
    lbl->setFixedHeight(75);
    lbl->showFullScreen();
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setMouseTracking(false);

    QPixmap qpixmapFondBlanc("C:/Users/M2IHM/Documents/projet_hap/img/fond.png");
    fondBlanc = new QGraphicsPixmapItem(qpixmapFondBlanc);
    this->addItem(fondBlanc);

    //position de texte et fond blanc
    lbl->setGeometry(mainWindow->width()/2 - lbl->width()/2, 20, 600, 75);
    fondBlanc->setPos(mainWindow->width()/2 - lbl->width()/2, 20);

    lbl->hide();
    fondBlanc->hide();
}

bool MyGraphicsScene::checkGoNext() {
    mCursorX = QCursor::pos().x();
    if (mCursorX > mainWindow->width() - 150) {
        return true;
    }
    return false;
}

void MyGraphicsScene::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Escape) {
        this->mainWindow->close();
    }
}
