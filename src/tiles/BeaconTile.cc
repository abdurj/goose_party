#include "tiles/BeaconTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

BeaconTile::BeaconTile(bool intersection) : Tile(intersection) {};

void BeaconTile::apply(shared_ptr<Player> &p) {
    cout << "landed on beacon tile" << endl;
}

Element BeaconTile::tileElement() {
    return text(" ") |  bgcolor(Color::CyanLight);
}

Element BeaconTile::getElement() {
    return tileElement() | border;
};
