#include "Room.h"


Room::Room(string description) {
    this->description = description;
    this->itemFlag = false;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["North"] = north;
    if (east != NULL)
        exits["East"] = east;
    if (south != NULL)
        exits["South"] = south;
    if (west != NULL)
        exits["West"] = west;
}

string Room::shortDescription() {
    return description;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem)
{
    this->itemsInRoom = inItem;
    //flag
}

void Room::setFlag(bool boolItem)
{
    this->itemFlag = boolItem;
}

Item Room::getItem()
{
    return *itemsInRoom;
}

bool Room::checkTheItem()
{
    return itemFlag;
}

Room::~Room()
{

}

