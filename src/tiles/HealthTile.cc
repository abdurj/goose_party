#include "tiles/HealthTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

HealthTile::HealthTile(bool intersection) : Tile(intersection) {};

void HealthTile::apply(shared_ptr<Player> &p) {
    cout << "landed on health tile" << endl;
}

Element HealthTile::tileElement() {
    return text(" ") |  bgcolor(Color::Pink3);
}

Element HealthTile::getElement() {
    return tileElement() | border;
};
