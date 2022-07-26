#include "tiles/DegreeTile.h"
#include "player/Player.h"
#include <iostream>
using namespace ftxui;
using namespace std;

DegreeTile::DegreeTile(int type) : Tile(type) {};

void DegreeTile::apply(shared_ptr<Player> &p) {
    cout << p->Options()->name << " is attempting to claim a degree with " << p->Grades() << " grades!" << endl;
}

Element DegreeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Blue);
}

Element DegreeTile::getElement() {
    return tileElement() | border;
};
