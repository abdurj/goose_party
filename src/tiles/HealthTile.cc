#include "tiles/HealthTile.h"
#include "player/Player.h"
#include <iostream>
using namespace ftxui;
using namespace std;

HealthTile::HealthTile(int type) : Tile(type){};

void HealthTile::apply(shared_ptr<Player> &p) {
    cout << "Landed on Health Tile. Healing " << p->Options()->name << " for 5 HP." << endl;
    p->modifyHP(5);
}

Element HealthTile::tileElement() {
    return text(" ") |  bgcolor(Color::Pink3);
}

Element HealthTile::getElement() {
    return tileElement() | border;
};
