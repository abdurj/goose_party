#include "tiles/TileDecorator.h"

using namespace ftxui;

TileDecorator::TileDecorator(Tile* t) : tile{t} {};

Element TileDecorator::tileElement(){
    return tile->tileElement();
}

Element TileDecorator::getElement(){
    return stylize(tileElement());
}

TileDecorator::~TileDecorator(){
}