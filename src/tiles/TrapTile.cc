#include "tiles/TrapTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

TrapTile::TrapTile(std::shared_ptr<Tile> t) : TileDecorator(t) {};

TrapTile::TrapTile(std::shared_ptr<Tile> t, std::unique_ptr<TrapCard> trap) : TileDecorator(t), trap{std::move(trap)} {}


void TrapTile::apply(shared_ptr<Player> &p) {
    cout << "landed on trap tile" << endl;
    trap->activate(p.get());
}

Element TrapTile::stylize(Element e){
    return e | borderHeavy | color(Color::MediumPurple2Bis);
}
