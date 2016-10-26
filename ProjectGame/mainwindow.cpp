#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTheGame();
}
void MainWindow::startTheGame()
{
    graphicScene = new QGraphicsScene(this);
    graphicScene->setSceneRect(0, 0, 591, 448);
    graphicScene->setBackgroundBrush(QBrush(QImage(":/Images/FTLShip.jpg")));
    createRooms();
    ui->graphicsView->setScene(graphicScene);
}

void MainWindow::createRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l;

    a = new Room("a");
        //a->addItem(new Item("x", 1, 11));
        //a->addItem(new Item("y", 2, 22));
    b = new Room("b");
        //b->addItem(new Item("xx", 3, 33));
        //b->addItem(new Item("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");
    k = new Room("k");
    l = new Room("l");

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, k, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, k, NULL, NULL);
    k->setExits(d, l, NULL, j);
    l->setExits(NULL, NULL, NULL, k);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_North_clicked()
{
    // go room
    //method to change room
    //north
}

void MainWindow::on_East_clicked()
{

}

void MainWindow::on_South_clicked()
{

}


void MainWindow::on_West_clicked()
{

}

void MainWindow::on_Exit_clicked()
{

}
