#include "tiles/BaseTile.h"

using namespace ftxui;
using namespace std;

BaseTile::BaseTile(bool intersection) : Tile(intersection) {};

void BaseTile::apply(shared_ptr<Player> &p) {}

Element BaseTile::tileElement(){
    return text(" ");
}

Element BaseTile::getElement(){
    return tileElement() | border;
};