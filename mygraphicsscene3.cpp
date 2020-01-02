#include "mygraphicsscene3.h"
#include "mainwindow.h"

MyGraphicsScene3::MyGraphicsScene3(MainWindow *w, GestionHaptique *mHap) :
    MyGraphicsScene(w, mHap)
{
    backgroundImg = QPixmap(":/images/img/scene3/0.png");
    this->setBackgroundBrush(QBrush(backgroundImg));
    this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
}


bool MyGraphicsScene3::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::GraphicsSceneMousePress) {
        if (checkGoNext()) {
            if (state == 0) {
                state = 1;
                backgroundImg = QPixmap(":/images/img/scene3/1.png");
                lbl->setText("<h2>La porte est ouverte !!!</h2> <h4>George peut déjà voir la lumière de l'autre coté, il s'approche donc de la sortie...quand tout à coup..</h4>");
                lbl->show();
                fondBlanc->show();
            } else if (state == 1) {
                state = 2;
                backgroundImg = QPixmap(":/images/img/scene3/2.png");
                lbl->setText("<h2>Tout s'éffondre autour de lui et George tombe D: oh nyoo</h4>");
                mHaptique->mTremblement->Start();
            } else if (state == 2) {
                state = 3;
                backgroundImg = QPixmap(":/images/img/scene3/3.png");
                lbl->hide();
                fondBlanc->hide();
                mHaptique->mTremblement->Stop();
            } else if (state == 3) {
                state = 4;
                backgroundImg = QPixmap(":/images/img/scene3/4.png");
                lbl->setText("<h2>Au loin il voit une porte de sortie, qui semble être gardée par une sorte de puzzle</h2>");

            } else if (state == 4) {
                state = 5;
                backgroundImg = QPixmap(":/images/img/scene3/5.png");
                lbl->setText("<h2>Ce n'était qu'un mauvais rêve !</h2>");
                lbl->show();
                fondBlanc->show();

            } else if (state == 5) {
               state = 6;
               backgroundImg = QPixmap(":/images/img/scene3/6.png");
               lbl->hide();
               fondBlanc->hide();
            }
            this->setBackgroundBrush(QBrush(backgroundImg));
            this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
        }
    }

    if (state == 2) {
        timer = timer - 1;
        if (timer == 0) {
            mHaptique->mTremblement->Stop();
        }
    }
    return false;
}

