#include "playgame.h"

PlayGame::PlayGame()
{
 createRooms();
}
void PlayGame::createRooms(){

Rooms *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l;

a = new Rooms("a");
    a->addItem(new Item("x", 1, 11));
    a->addItem(new Item("y", 2, 22));
b = new Rooms("b");
    b->addItem(new Item("xx", 3, 33));
    b->addItem(new Item("yy", 4, 44));
c = new Rooms("c");
d = new Rooms("d");
e = new Rooms("e");
f = new Rooms("f");
g = new Rooms("g");
h = new Rooms("h");
i = new Rooms("i");
j = new Rooms("j");
k = new Rooms("k");
l = new Rooms("l");

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

rooms.push_back(a);
rooms.push_back(b);
rooms.push_back(c);
rooms.push_back(d);
rooms.push_back(e);
rooms.push_back(f);
rooms.push_back(g);
rooms.push_back(h);
rooms.push_back(i);
rooms.push_back(j);
rooms.push_back(k);
rooms.push_back(l);

currentRoom = a;
}

