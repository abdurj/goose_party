#include "tiles/BeaconTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

BeaconTile::BeaconTile(int type) : Tile(type) {};

void BeaconTile::apply(shared_ptr<Player> &p) {
    cout << "Landed on beacon tile!" << endl;
}

Element BeaconTile::tileElement() {
    return text(" ") |  bgcolor(Color::CyanLight);
}

Element BeaconTile::getElement() {
    return tileElement() | border;
};
