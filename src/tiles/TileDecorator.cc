#include "tiles/TileDecorator.h"

using namespace ftxui;

TileDecorator::TileDecorator(std::shared_ptr<Tile> t) : Tile(t->isIntersection(), t->isElbow()), tile{t} {};

Element TileDecorator::tileElement(){
    return tile->tileElement();
}

Element TileDecorator::getElement(){
    return stylize(tileElement());
}

TileDecorator::~TileDecorator(){
}
