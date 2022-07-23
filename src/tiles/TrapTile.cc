#include "tiles/TrapTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

TrapTile::TrapTile(std::shared_ptr<Tile> t) : TileDecorator(t) {};

void TrapTile::apply(shared_ptr<Player> &p) {
    cout << "landed on trap tile" << endl;
}

Element TrapTile::stylize(Element e){
    return e | borderHeavy | color(Color::MediumPurple2Bis);
}
