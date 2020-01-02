#include "mygraphicsscene2.h"
#include "mygraphicsscene3.h"
#include "mainwindow.h"

MyGraphicsScene2::MyGraphicsScene2(MainWindow *w, GestionHaptique *mHap) :
    MyGraphicsScene(w, mHap)
{
    //cube lourd
    cubeLourd = new Cube(450, 300);
    lourdImg = cubeLourd->cubeImage;
    this->addItem(lourdImg);
    lourdImg->hide();
    lourdImg->setPos(cubeLourd->x, cubeLourd->y);

    //cube moyen
    cubeMoyen = new Cube(250, 300);
    moyenImg = cubeMoyen->cubeImage;
    this->addItem(moyenImg);
    moyenImg->hide();
    moyenImg->setPos(cubeMoyen->x, cubeMoyen->y);

    //cube leger
    cubeLeger = new Cube(650, 300);
    legerImg = cubeLeger->cubeImage;
    this->addItem(legerImg);
    legerImg->hide();
    legerImg->setPos(cubeLeger->x, cubeLeger->y);

    backgroundImg = QPixmap(":/images/img/scene2/0.png");
    this->setBackgroundBrush(QBrush(backgroundImg));
    this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
}

bool MyGraphicsScene2::eventFilter(QObject *object, QEvent *ev)
{
    if (ev->type() == QEvent::GraphicsSceneMousePress && state != 2) {
        if (checkGoNext()) {
            if (state == 0) {
                state = 1;
                lbl->setText("<h3>George s'approche de la table pour tenter de résoudre l'énigme</h3>");
                lbl->show();
                fondBlanc->show();
                backgroundImg = QPixmap(":/images/img/scene2/1.png");
            } else if (state == 1) {
                state = 2;
                lbl->hide();
                fondBlanc->hide();
                backgroundImg = QPixmap(":/images/img/scene2/2.png");
            } else if (state == 3) {
                lbl->hide();
                qDebug() << "passer a la prochaine scene";
                mainWindow->SetScene(new MyGraphicsScene3(mainWindow, this->mHaptique));
            }
            this->setBackgroundBrush(QBrush(backgroundImg));
            this->setBackgroundBrush(QBrush(backgroundImg.scaled(this->mainWindow->width(), this->mainWindow->height(), Qt::IgnoreAspectRatio)));
        }
    } else if (state == 2) {
        //recup la position de la souris
        mCursorX = QCursor::pos().x();
        mCursorY = QCursor::pos().y();

        //gestion des cubes

        //affichage
        lourdImg->show();
        moyenImg->show();
        legerImg->show();

        if (ev->type() == QEvent::GraphicsSceneMousePress) {                //selection du cube
            if (detectCollisionCube(cubeLourd, mCursorX, mCursorY)) {
                savedX = mCursorX - cubeLourd->x;
                savedY = mCursorX - cubeLourd->x;
                cubeLourd->clicked = true;
                mHaptique->mFriction10k->Start();
                mHaptique->mInertie10k->Start();
                qDebug() << "dans cube lourd";
            } else if (detectCollisionCube(cubeMoyen, mCursorX, mCursorY)) {
                savedX = mCursorX - cubeMoyen->x;
                savedY = mCursorX - cubeMoyen->x;
                cubeMoyen->clicked = true;
                mHaptique->mFriction5k->Start();
                mHaptique->mInertie5k->Start();
                qDebug() << "dans cube moyen";
            } else if (detectCollisionCube(cubeLeger, mCursorX, mCursorY)) {
                savedX = mCursorX - cubeLeger->x;
                savedY = mCursorX - cubeLeger->x;
                cubeLeger->clicked = true;
                qDebug() << "dans cube leger";
            }

        } else if (ev->type() == QEvent::GraphicsSceneMouseRelease) {       //déselection du cube
            cubeLourd->clicked = false;
            cubeMoyen->clicked = false;
            cubeLeger->clicked = false;

            mHaptique->mFriction10k->Stop();
            mHaptique->mFriction5k->Stop();

            mHaptique->mInertie10k->Stop();
            mHaptique->mInertie5k->Stop();

            checkIfPuzzleSolved();

        } else if (ev->type() == QMouseEvent::GraphicsSceneMouseMove){      //movement du cube
            if (cubeLourd->clicked) {
                cubeLourd->x = mCursorX - savedX;
                cubeLourd->y = mCursorY - savedY;
                lourdImg->setPos(cubeLourd->x, cubeLourd->y);
            } else if (cubeMoyen->clicked) {
                cubeMoyen->x = mCursorX - savedX;
                cubeMoyen->y = mCursorY - savedY;
                moyenImg->setPos(cubeMoyen->x, cubeMoyen->y);
            } else if (cubeLeger->clicked) {
                cubeLeger->x = mCursorX - savedX;
                cubeLeger->y = mCursorY - savedY;
                legerImg->setPos(cubeLeger->x, cubeLeger->y);
            }
        }
    }
    return false;
}

/*
    detecte si la souris est dans le cube
*/
bool MyGraphicsScene2::detectCollisionCube(Cube* cube, int x, int y) {
    bool dansX = (x > cube->x) && (x < (cube->x + cube->taille));
    bool dansY = (y > cube->y) && (y < (cube->y + cube->taille));
    return dansX && dansY;
}

/*
    check si les 3 cubes sont dans les bons emplacements
    puis passe à l'état 3 si c'est le cas
*/
void MyGraphicsScene2::checkIfPuzzleSolved() {
    bool legerOK = ((cubeLeger->x > 120 && cubeLeger->x + cubeLeger->taille < 270)
                    && (cubeLeger->y > 475 && cubeLeger->y + cubeLeger->taille < 625));
    bool moyenOK = ((cubeMoyen->x > 435 && cubeMoyen->x + cubeMoyen->taille < 585)
                    && (cubeMoyen->y > 475 && cubeMoyen->y + cubeMoyen->taille < 625));
    bool lourdOK = ((cubeLourd->x > 755 && cubeLourd->x + cubeLourd->taille < 905)
                    && (cubeLourd->y > 475 && cubeLourd->y + cubeLourd->taille < 625));


    if (lourdOK && moyenOK && legerOK) {
        lbl->setText("<h3>George a réussi à résoudre l'énigme ! il peut déjà voir la porte s'ouvrir</h3>Arrivera-t-il à s'échapper ? Appuyez à droite pour passer à la page suivante et découvrir la suite de l'histoire!");
        lbl->show();
        fondBlanc->show();
        state = 3;
    }
}
