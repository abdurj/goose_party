#include "tiles/DegreeTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

DegreeTile::DegreeTile(bool intersection) : Tile(intersection) {};

void DegreeTile::apply(std::shared_ptr<Player> p) {
    cout << "landed on degree tile" << endl;
}

Element DegreeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Blue);
}

Element DegreeTile::getElement() {
    return tileElement() | border;
};
