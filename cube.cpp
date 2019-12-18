#include "cube.h"

Cube::Cube() {
    x = 0;
    y = 0;
    poids = 0;
    QPixmap cubeSprite("C:/Users/M2IHM/Documents/projet_hap/img/cube.png");
    cubeImage = new QGraphicsPixmapItem(cubeSprite.scaled(QSize(taille,taille)));
}

Cube::Cube(int _x, int _y, int _poids) {
    x = _x;
    y = _y;
    poids = _poids;
    QPixmap cubeSprite("C:/Users/M2IHM/Documents/projet_hap/img/cube.png");
    cubeImage = new QGraphicsPixmapItem(cubeSprite.scaled(QSize(taille,taille)));
}
