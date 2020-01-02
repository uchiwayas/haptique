#include "mygraphicsscene.h"
#include "mainwindow.h"

MyGraphicsScene::MyGraphicsScene(MainWindow *w, GestionHaptique *mHap) :
    QGraphicsScene(w),
    mCursorX(0),
    mCursorY(0),
    mHaptique(mHap)
{
    this->setSceneRect(0,0,1024,768);       //taille de l'écran

    installEventFilter(this);               //gestion des events
    this->mainWindow = w;                   //init de la main window

    lbl = new QLabel("", this->mainWindow); //init label
    lbl->setWordWrap(true);                 //retour a la ligne activé
    lbl->setFixedWidth(600);                //largeur max label
    lbl->setFixedHeight(75);                //hauteur max label
    lbl->showFullScreen();                  //fullscreen du label
    lbl->setAlignment(Qt::AlignCenter);     //label centré
    lbl->setMouseTracking(false);

    QPixmap qpixmapFondBlanc("C:/Users/M2IHM/Documents/projet_hap/img/fond.png");   //init fond blanc
    fondBlanc = new QGraphicsPixmapItem(qpixmapFondBlanc);
    this->addItem(fondBlanc);

    //position de texte et fond blanc
    lbl->setGeometry(mainWindow->width()/2 - lbl->width()/2, 20, 600, 75);
    fondBlanc->setPos(mainWindow->width()/2 - lbl->width()/2, 20);

    lbl->hide();
    fondBlanc->hide();
}

/**
 * @brief MyGraphicsScene::checkGoNext
 * check si on doit passer a la page suivante
 * @return true si on doit passer à la page suivante, false sinon
 */
bool MyGraphicsScene::checkGoNext() {
    mCursorX = QCursor::pos().x();
    if (mCursorX > mainWindow->width() - 150) {
        return true;
    }
    return false;
}

/**
 * @brief MyGraphicsScene::keyPressEvent
 * Gère les events clavier, echap = quitter
 * @param event
 */
void MyGraphicsScene::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Escape) {
        this->mainWindow->close();
    }
}
