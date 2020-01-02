#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <gestionhaptique.h>

class MainWindow;

/**
 * @brief The MyGraphicsScene class
 * Classe abstraite fille de QGraphicsScene qui permet d'avoir plusieurs
 * scenes / chapitres
 */
class MyGraphicsScene : public QGraphicsScene
{
public:
    //constructor
    MyGraphicsScene(MainWindow *w, GestionHaptique *mHap);

    //functions
    bool checkGoNext();                     //teste si la souris est cliquée sur le bord de l'écran pour passer à la page suivante
    void keyPressEvent(QKeyEvent * event);  //evenement appui clavier

    //elements
    MainWindow * mainWindow;
    int mCursorX;                    //souris position X
    int mCursorY;                    //souris position Y
    QLabel* lbl;                     //texte en haut de page
    QGraphicsPixmapItem* fondBlanc;  //fond blanc en haut de page

    //etat du jeu
    int state = 0;                   //état de la scene (page)
    QPixmap backgroundImg;           //fond d'écran

    //haptique
    GestionHaptique *mHaptique;
};

#endif // MYGRAPHICSSCENE_H