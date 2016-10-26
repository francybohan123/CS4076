#ifndef ROOM_H_
#define ROOM_H_

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
    //vector <Item> itemsInRoom; //not yet


public:
    //int numberOfItems(); //not used yet
    Room(string description); //constructor
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription(); //room name
    string longDescription(); //objective of the game
    Room* nextRoom(string direction);
    //void addItem(Item *inItem); // not yet
    //string displayItem(); //not yet
    //int isItemInRoom(string inString); // not yet
    //void removeItemFromRoom(int location); // not yet
};

#endif
