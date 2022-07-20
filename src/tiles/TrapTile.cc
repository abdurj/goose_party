#include "tiles/TrapTile.h"
#include <iostream>
using namespace ftxui;

TrapTile::TrapTile(std::shared_ptr<Tile> t) : TileDecorator(t) {};

void TrapTile::apply(std::shared_ptr<Player> p) {
    std::cout << "landed on trap tile" << std::endl;
}

Element TrapTile::stylize(Element e){
    return e | borderHeavy | color(Color::MediumPurple2Bis);
}
