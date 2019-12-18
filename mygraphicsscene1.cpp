#include "mygraphicsscene1.h"
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
    backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene1/couverture.png");
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

bool MyGraphicsScene1::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::GraphicsSceneMousePress) {
        if (checkGoNext()) {
            if (state == 0) {
                state = 1;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene1/0.png");
                lbl->hide();
                fondBlanc->hide();
            }
            else if (state == 1) {
                state = 2;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene1/1.png");
                lbl->setText("<h2>\"Mais...Où suis-je ?\"</h2>");
                lbl->show();
                fondBlanc->show();
            } else if (state == 2) {
                state = 3;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene1/2.png");
                lbl->setText("<h2>Goerges Lewdcas s'est réveillé dans une salle sombre et étrange, il décide de s'aventurer pour essayer de s'échaper</h2>");

            } else if (state == 3) {
                state = 4;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene1/3.png");
                lbl->setText("<h2>il trouve des trucs</h2>");

            } else if (state == 4) {
                state = 5;
                backgroundImg = QPixmap("C:/Users/M2IHM/Documents/projet_hap/img/scene1/4.png");
                lbl->setText("<h2>Au loin il voit une porte de sortie, qui semble être gardée par une sorte de puzzle</h2>");

            } else if (state == 5) {
                lbl->hide();
                qDebug() << "passer a la prochaine scene";
                mainWindow->SetScene(new MyGraphicsScene2(mainWindow));

            }
            this->setBackgroundBrush(QBrush(backgroundImg));
            this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
        }
    }
    return false;
}

void MyGraphicsScene1::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Escape) {
        this->mainWindow->close();
    }
}

bool MyGraphicsScene1::checkGoNext() {
    mCursorX = QCursor::pos().x();
    if (mCursorX > mainWindow->width() - 100) {
        return true;
    }
    return false;
}



