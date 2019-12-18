#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mygraphicsscene1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void SetScene(QGraphicsScene *scene);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MyGraphicsScene1 * scene;
};

#endif // MAINWINDOW_H
