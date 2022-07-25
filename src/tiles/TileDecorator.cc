#include "tiles/TileDecorator.h"

using namespace ftxui;

TileDecorator::TileDecorator(std::shared_ptr<Tile> t) : Tile(t->Type()), tile{t} {};

void TileDecorator::apply(std::shared_ptr<Player> &p) {
    tile->apply(p);
}

Element TileDecorator::tileElement(){
    return tile->tileElement();
}

Element TileDecorator::getElement(){
    return stylize(tileElement());
}

TileDecorator::~TileDecorator(){
}
