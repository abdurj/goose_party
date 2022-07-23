#include "tiles/CardTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

CardTile::CardTile(bool intersection) : Tile(intersection) {};

void CardTile::apply(shared_ptr<Player> &p) {
    cout << "landed on card tile" << endl;
}

Element CardTile::tileElement() {
    return text(" ") |  bgcolor(Color::OrangeRed1);
}

Element CardTile::getElement() {
    return tileElement() | border;
};
