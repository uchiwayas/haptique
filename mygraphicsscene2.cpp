#include "mygraphicsscene2.h"
#include "mainwindow.h"

MyGraphicsScene2::MyGraphicsScene2(MainWindow *w) :
    QGraphicsScene(w),
    mCursorX(0),
    mCursorY(0)
{
    this->setSceneRect(0,0,1024,768);

    installEventFilter(this);
    this->mainWindow = w;
    backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene2/0.png");
    this->setBackgroundBrush(QBrush(backgroundImg));
    this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));


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

bool MyGraphicsScene2::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::GraphicsSceneMousePress) {
        if (checkGoNext()) {
            if (state == 0) {
                state = 1;
                lbl->setText("page 1");
                lbl->show();
                fondBlanc->show();
                //backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene2/1.png");
            } else if (state == 1) {
                state = 2;

            } else if (state == 2) {
                state = 3;

            } else if (state == 3) {
                state = 4;

            } else if (state == 4) {

            }
            this->setBackgroundBrush(QBrush(backgroundImg));
            this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
        }
    }

    return false;
}

void MyGraphicsScene2::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Escape) {
        this->mainWindow->close();
    }
}


bool MyGraphicsScene2::checkGoNext() {
    mCursorX = QCursor::pos().x();
    if (mCursorX > mainWindow->width() - 100) {
        return true;
    }
    return false;
}

