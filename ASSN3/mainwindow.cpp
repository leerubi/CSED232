#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    this->hide();

    // 게임 시작.
    srand((unsigned int)time(NULL));
    QGraphicsScene * scene = new QGraphicsScene();

    Game * game = new Game(scene);
    game->playGame();

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    view->setFixedSize(800,800);
    scene->setSceneRect(0,0,800,800);
}

void MainWindow::on_endButton_clicked()
{
    exit(0);
}
