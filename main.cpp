#include "mainwindow.h"
#include "Admin.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Admin x(10);
    Admin y(24);
    Admin z;

    z = x * y;
    cout << z.newNumber << endl;
    return a.exec();
}
