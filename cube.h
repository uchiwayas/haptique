#ifndef CUBE_H
#define CUBE_H
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

/**
 * @brief The Cube class
 * Sert à créer les trois cubes du chapitre 2
 */
class Cube
{
public:
    static const int taille = 100;


    /**
     * @brief Cube::Cube
     * default constructor
     */
    Cube();
    /**
     * @brief Cube::Cube
     * Constructor
     * @param _x : position x du cube
     * @param _y : position y du cube
     */
    Cube(int _x, int _y);
    void Show(QGraphicsScene scene);
    QGraphicsPixmapItem* cubeImage;

    int x;
    int y;
    bool clicked = false;
};

#endif // CUBE_H
