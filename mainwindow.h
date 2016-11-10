#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "item.h"
#include "room.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;
    Item *Radiator, * Battery, *Petrol, *Oil;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Room* currentRoom;
    Room* nextRoom;

private slots:

    void on_North_clicked();

    void on_East_clicked();

    void on_South_clicked();

     void on_West_clicked();

    void on_Exit_clicked();


    void on_NextMission_clicked();

private:
    Ui::MainWindow *ui;
    void startTheGame();
    Room* roomItem[4];
    QGraphicsScene *graphicScene;
    void createRooms();
    void goRoom(string direction);
    Item* playerItems[4];
    Item* temp;
    int index;
    string itemText;
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
