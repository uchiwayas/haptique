#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sonmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    installEventFilter(this);

    this->showFullScreen();     //affichage en plein écran
    //this->move(QPoint(0,0));

    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setSceneRect(0,0,ui->graphicsView->width() - 5, ui->graphicsView->height() - 5);

    this->setAttribute(Qt::WA_TransparentForMouseEvents, false);

    scene = new MyGraphicsScene1(this, GestionHaptique::getInstance(this));     //lancement du
    this->SetScene(scene);
}

void MainWindow::SetScene(QGraphicsScene *scene) {
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    SonManager::killManager();
    GestionHaptique::killInstance();
}
