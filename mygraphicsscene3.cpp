#include "mygraphicsscene3.h"
#include "mainwindow.h"

MyGraphicsScene3::MyGraphicsScene3(MainWindow *w) :
    QGraphicsScene(w),
    mCursorX(0),
    mCursorY(0)
{
    this->setSceneRect(0,0,1024,768);

    installEventFilter(this);
    this->mainWindow = w;
    backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene3/0.png");
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


bool MyGraphicsScene3::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::GraphicsSceneMousePress) {
        if (checkGoNext()) {
            if (state == 0) {
                state = 1;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene3/1.png");
                lbl->setText("<h2>La porte est ouverte !!!</h2> <h4>Goerges peut déjà voir la lumière de l'autre coté, il s'approche donc de la sortie...quand tout à coup..</h4>");
                lbl->show();
                fondBlanc->show();
            } else if (state == 1) {
                state = 2;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene3/2.png");
                lbl->setText("<h2>Tout s'éffondre autour de lui et Goerges tombe D: oh nyoo</h4>");
                fondBlanc->show();

            } else if (state == 2) {
                state = 3;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene3/3.png");
                lbl->hide();
                fondBlanc->hide();

            } else if (state == 3) {
                state = 4;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene3/4.png");
                lbl->setText("<h2>Au loin il voit une porte de sortie, qui semble être gardée par une sorte de puzzle</h2>");

            } else if (state == 4) {
                state = 5;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene3/5.png");
                lbl->setText("<h2>Ce n'était qu'un mauvais rêve !</h2>");
                lbl->show();
                fondBlanc->show();

            } else if (state == 5) {
               state = 6;
               backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene3/6.png");
               lbl->hide();
               fondBlanc->hide();
            }
            this->setBackgroundBrush(QBrush(backgroundImg));
            this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
        }
    }
    return false;
}

void MyGraphicsScene3::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Escape) {
        this->mainWindow->close();
    }
}

bool MyGraphicsScene3::checkGoNext() {
    mCursorX = QCursor::pos().x();
    if (mCursorX > mainWindow->width() - 100) {
        return true;
    }
    return false;
}


