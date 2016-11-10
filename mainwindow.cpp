#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startTheGame();
}
/*
 * Creating the Graphics Scene where the Image is displayed.
 * Graphics scene size is set with setSceneRect.
 * Method where rooms are created is called here.
 * The Graphics scene is added to the Graphics view(Overall Window)
 */
void MainWindow::startTheGame()
{
    graphicScene = new QGraphicsScene(this);
    graphicScene->setSceneRect(0, 0, 591, 448);
    graphicScene->setBackgroundBrush(QBrush(QImage(":/Images/FTLShip.jpg"))); //add the image into the graphics scene and display in GUI
    temp = new Item();
    index = 0;
    itemText = "Items:\n";
    createRooms();
    ui->graphicsView->setScene(graphicScene);
    ui->NextMission->setVisible(false);
}
/*
 * Creates the rooms for the game.
 * Items are added to a few different rooms.
 * Exits for the rooms are set here too.
 * All variables are declared in the header file.
 * This code also update you on your current room position and displays it to one of the text boxes
 */
void MainWindow::createRooms()
{
    a = new Room("A - Tactical Planning Room");
    b = new Room("B - Strike Operations Room");
    c = new Room("C - Control Room");
    d = new Room("D - Maintainence Room");
    e = new Room("E - Crew Quarters");
    f = new Room("F - Armoury");
    g = new Room("G - Briefing Room");
        Radiator = new Item("Radiator");
        g->addItem(Radiator);
        g->setFlag(true);
    h = new Room("H - Pilot Ready Room");
        Petrol = new Item("Petrol"); //add item to the rooms
        h->addItem(Petrol);
        h->setFlag(true);
    i = new Room("I - Engine Room");
    j = new Room("J - Observation Room");
        Battery = new Item("Battery");
        j->addItem(Battery);
        j->setFlag(true);
    k = new Room("K - Captains Quarters");
        Oil = new Item("Oil");
        k->addItem(Oil);
        k->setFlag(true);

                //(N, E, S, W)
    a->setExits(b, NULL, c, NULL);
    b->setExits(NULL, f, a, NULL);
    c->setExits(a, g, NULL, NULL);
    d->setExits(NULL, NULL, f, NULL);
    e->setExits(g, NULL, NULL, NULL);
    f->setExits(d, NULL, g, b);
    g->setExits(f, h, e, c);
    h->setExits(NULL, k, NULL, g);
    i->setExits(NULL, NULL, j, NULL);
    j->setExits(i, NULL, k, NULL);
    k->setExits(j, NULL, NULL, h);

    currentRoom = a;
    const string numberOne = "1. Collect all engine parts and repair the ship";
    const string numberTwo = "\n2. Proceed to Room I - The Engine Room";
    const string numberThree = "\n3. Repair the Spaceship";
    const string numberFour = "\n4. Proceed to Room C (Press G) - The Control Room";
    const string numberFive = "\n5. Start the ship";
    const string nextMission = "\nGood luck on your next mission!!";

    ui->MissionDisplay->setText(QString::fromStdString(numberOne + numberTwo + numberThree + numberFour + numberFive + nextMission));
    ui->DisplayRoom->setText(QString::fromStdString("Current Room: " + currentRoom->shortDescription()));

    roomItem[0] = d;
    roomItem[1] = e;
    roomItem[2] = f;
    roomItem[3] = k;
}
/*
 * Direction Method
 * Set where the exits of the rooms are.
 * if equal to null display error message
*/
void MainWindow::goRoom(string direction)
{
    nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
        ui->DisplayRoom->setText(QString::fromStdString("Invalid Move"));
    }
    else
    {
        currentRoom = nextRoom;
        ui->DisplayRoom->setText(QString::fromStdString("Current Room: " + currentRoom->shortDescription()));
        if(currentRoom->checkTheItem())
        {
            if(currentRoom->checkTheItem())
            {
                *temp = currentRoom->getItem(); //learn
                playerItems[index] = temp;
                itemText += playerItems[index]->getShortDescription() + "\n";
                ui->ItemBox->setText(QString::fromStdString(itemText));
                index++;
                currentRoom->setFlag(false);
            }
        }
    }

    /*
     * if the current room is "I" and the array is full of items
     * display a message to say the engine has been fixed
     */
    if(currentRoom->shortDescription() == "I - Engine Room" && playerItems[4] != NULL){
            for(int i = 0; i < 4; i++)
            {
                playerItems[index] = NULL;
                ui->ItemBox->setText(QString::fromStdString("The engine has been fixed"));

            }
    }
            else if(currentRoom->shortDescription() == "I - Engine Room" && playerItems[4] == NULL)
            {
                 ui->ItemBox->setText(QString::fromStdString("You have not collected all the items to fix the ship"));
            }
}

/*
 * Listener for when the Space button is clicked.
 * Button only works if current room is C - The Control Room
 * Displays message and ends game
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
        ui->NextMission->setVisible(false);
        if(event->key() == Qt::Key_G)
        {
            if(currentRoom->shortDescription() == "C - Control Room")
            {
                ui->NextMission->setVisible(true);
            }
        }
}

/*
 * North Button Listener
 */
void MainWindow::on_North_clicked()
{
    goRoom("North");
}

/*
 * East Button Listener
 */
void MainWindow::on_East_clicked()
{
    goRoom("East");
}

/*
 * South Button Listener
 */
void MainWindow::on_South_clicked()
{
    goRoom("South");
}

/*
 * West Button Listener
 */
void MainWindow::on_West_clicked()
{
    goRoom("West");
}

/*
 * Exit Button listener
 */
void MainWindow::on_Exit_clicked()
{
    close();
}

/*
 * Displays when the ship has been repaired
 */
void MainWindow::on_NextMission_clicked()
{
    close();
}

/*
 * Everything that was created new is deleted here
 * this helps prevent data leaking
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete graphicScene;
    delete temp;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete i;
    delete j;
    delete k;
    delete Radiator;
    delete Battery;
    delete Petrol;
    delete Oil;
}


