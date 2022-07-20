#include "tiles/BaseTile.h"

using namespace ftxui;

BaseTile::BaseTile(bool intersection) : Tile(intersection) {};

void BaseTile::apply(std::shared_ptr<Player> p) {}

Element BaseTile::tileElement(){
    return text(" ");
}

Element BaseTile::getElement(){
    return tileElement() | border;
};