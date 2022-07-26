#include "tiles/AbilityTile.h"
#include <iostream>
#include "utils/Utils.h"
using namespace ftxui;
using namespace std;

AbilityTile::AbilityTile(int type) : Tile(type) {};

void AbilityTile::apply(shared_ptr<Player> &p) {
    cout << "Landed on ability tile!" << endl;
    utils::generateAbility(p);
}

Element AbilityTile::tileElement() {
    return text(" ") |  bgcolor(Color::Green);
}

Element AbilityTile::getElement() {
    return tileElement() | border;
};
