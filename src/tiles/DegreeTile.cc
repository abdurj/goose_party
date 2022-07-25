#include "tiles/DegreeTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

DegreeTile::DegreeTile(bool intersection, bool elbow) : Tile(intersection, elbow) {};

void DegreeTile::apply(shared_ptr<Player> &p) {
    cout << "landed on degree tile" << endl;
}

Element DegreeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Blue);
}

Element DegreeTile::getElement() {
    return tileElement() | border;
};
