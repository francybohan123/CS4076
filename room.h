#ifndef ROOM_H_
#define ROOM_H_
#include "item.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class Room {

private:
    string description;
    map<string, Room*> exits;
    string exitString();
    Item *itemsInRoom; //not yet
    bool itemFlag;


public:
    ~Room();
    Room(string description); //constructor
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription(); //room name
    string longDescription(); //objective of the game
    Room* nextRoom(string direction);
    void addItem(Item *inItem); // not yet
    void setFlag(bool boolItem);
    Item getItem();
    bool checkTheItem();
    string displayItem(); //not yet
    int isItemInRoom(); // not yet
};

#endif
