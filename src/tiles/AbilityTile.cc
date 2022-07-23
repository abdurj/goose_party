#include "tiles/AbilityTile.h"
#include <iostream>
#include "utils/Utils.h"
using namespace ftxui;
using namespace std;

AbilityTile::AbilityTile(bool intersection) : Tile(intersection) {};

void AbilityTile::apply(std::shared_ptr<Player> p) {
    cout << "landed on ability tile" << endl;
    utils::drawAbility(p);
}

Element AbilityTile::tileElement() {
    return text(" ") |  bgcolor(Color::Green);
}

Element AbilityTile::getElement() {
    return tileElement() | border;
};
