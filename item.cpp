#include "item.h"

Item::Item()
{

}

Item::Item(string description)
{
    this->description = description;
}

/*
 * returns the short description of the item.
 * i.e. the name of the item
 */
string Item::getShortDescription()
{
    return description;
}

/* This is the item deconstructor
 * it is called to delete objects when the program is finished with them
 * This prevents data leaking
 */
Item::~Item()
{

}

