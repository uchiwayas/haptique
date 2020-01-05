#include "mygraphicsscene1.h"
#include "mygraphicsscene2.h"
#include "mainwindow.h"
#include "sonmanager.h"

/**
 * @brief MyGraphicsScene1::MyGraphicsScene1
 * Constructeur
 * @param w : window
 * @param mHap : gestion haptique
 */
MyGraphicsScene1::MyGraphicsScene1(MainWindow *w, GestionHaptique *mHap) :
    MyGraphicsScene(w, mHap)
{
    //premier background (chapitre 1)
    backgroundImg = QPixmap(":/images/couverture");
    this->setBackgroundBrush(QBrush(backgroundImg));
    this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));

    SonManager::play(SonManager::DEBUT);
}

/**
 * @brief MyGraphicsScene2::eventFilter.
 * Gère les evenements souris
 * @param object
 * @param ev
 */
bool MyGraphicsScene1::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::GraphicsSceneMousePress) { //si l'event est un clic souris
        if (checkGoNext()) {       //si on doit passer à la page suivante
            if (state == 0) {      //page 1
                state = 1;
                SonManager::clearAllSounds();
                SonManager::play(SonManager::CHAPITRE_1);
                backgroundImg = QPixmap(":/images/img/scene1/0.png");
                lbl->hide();
                fondBlanc->hide();
            }
            else if (state == 1) { //page 2
                state = 2;
                SonManager::clearAllSounds();
                SonManager::playBackground();
                backgroundImg = QPixmap(":/images/img/scene1/1.png");
                lbl->setText("<h2>\"Mais...Où suis-je ?\"</h2>");
                lbl->show();
                fondBlanc->show();
            } else if (state == 2) { //page 3
                state = 3;
                backgroundImg = QPixmap(":/images/img/scene1/2.png");
                lbl->setText("<h2>George s'est réveillé dans une salle sombre et étrange, il décide de s'aventurer pour essayer de s'échaper</h2>");

            } else if (state == 3) { //page 4
                state = 4;
                backgroundImg = QPixmap(":/images/img/scene1/3.png");
                lbl->setText("<h2>Il aperçoit des objects mis en évidences et il les touches !</h2>");
                mHaptique->mPaint->Start();
                mHaptique->mThrophee->Start();

            } else if (state == 4) { //page 5
                mHaptique->mPaint->Stop();
                mHaptique->mThrophee->Stop();
                mHaptique->mTextureRoche->Stop();
                state = 5;
                backgroundImg = QPixmap(":/images/img/scene1/4.png");
                lbl->setText("<h2>Au loin il voit une porte de sortie, qui semble être gardée par une sorte de puzzle</h2>");

            } else if (state == 5) { //page 6
                lbl->hide();
                qDebug() << "passer a la prochaine scene";
                SonManager::pauseBackground();
                //passage à la scene 2
                mainWindow->SetScene(new MyGraphicsScene2(mainWindow, this->mHaptique));
            }
            //après le mousepress on change de background pour passer à la page suivante
            this->setBackgroundBrush(QBrush(backgroundImg));
            this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
        }
    }

    //seulement pendant le state 4 : teste si la souris se trouve sur la roche pour changer la surface
    if (state == 4) {
        if ((QCursor::pos().x() > 405 && QCursor::pos().x() < 580) &&
                (QCursor::pos().y() > 251 && QCursor::pos().y() < 494)){
            mHaptique->mTextureRoche->Start();
        }
        else {
            mHaptique->mTextureRoche->Stop();
        }
    }
    return false;
}


