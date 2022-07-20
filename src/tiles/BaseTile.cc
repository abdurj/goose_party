#include "tiles/BaseTile.h"

using namespace ftxui;

BaseTile::BaseTile(bool intersection) : Tile(intersection) {};

Element BaseTile::tileElement(){
    return text(" ");
}

Element BaseTile::getElement(){
    return tileElement() | border;
};
