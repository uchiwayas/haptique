#include "cube.h"

Cube::Cube() {
    x = 0;
    y = 0;
    QPixmap cubeSprite(":/images/img/cube.png");
    cubeImage = new QGraphicsPixmapItem(cubeSprite.scaled(QSize(taille,taille)));
}

Cube::Cube(int _x, int _y) {
    x = _x;
    y = _y;
    QPixmap cubeSprite(":/images/img/cube.png");
    cubeImage = new QGraphicsPixmapItem(cubeSprite.scaled(QSize(taille,taille)));
}
