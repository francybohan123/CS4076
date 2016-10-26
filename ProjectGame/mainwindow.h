#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "room.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_North_clicked();

    void on_East_clicked();

    void on_South_clicked();

    void on_West_clicked();

    void on_Exit_clicked();

private:
    Ui::MainWindow *ui;
    void startTheGame();
    QGraphicsScene *graphicScene;
    void createRooms();
};

#endif // MAINWINDOW_H
