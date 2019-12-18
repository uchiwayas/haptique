#ifndef CUBE_H
#define CUBE_H
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Cube
{
public:
    static const int taille = 100;

    Cube();
    Cube(int _x, int _y, int _poids);
    void Show(QGraphicsScene scene);
    QGraphicsPixmapItem* cubeImage;

    int poids;
    int x;
    int y;
    bool clicked = false;
};

#endif // CUBE_H
