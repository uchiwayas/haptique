#include "cube.h"

/**
 * @brief Cube::Cube
 * default constructor
 */
Cube::Cube() {
    x = 0;
    y = 0;
    QPixmap cubeSprite(":/images/img/cube.png");
    cubeImage = new QGraphicsPixmapItem(cubeSprite.scaled(QSize(taille,taille)));
}

/**
 * @brief Cube::Cube
 * Constructor
 * @param _x : position x du cube
 * @param _y : position y du cube
 */
Cube::Cube(int _x, int _y) {
    x = _x;
    y = _y;
    QPixmap cubeSprite(":/images/img/cube.png");
    cubeImage = new QGraphicsPixmapItem(cubeSprite.scaled(QSize(taille,taille)));
}
