#include "tiles/DegreeTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

DegreeTile::DegreeTile(int type) : Tile(type) {};

void DegreeTile::apply(shared_ptr<Player> &p) {
    cout << "landed on degree tile" << endl;
}

Element DegreeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Blue);
}

Element DegreeTile::getElement() {
    return tileElement() | border;
};
