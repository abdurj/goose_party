#include "tiles/Tile.h"
using namespace ftxui;

Tile::Tile(int type) : type{type} {};

int Tile::Type() const{
    return type;
}

Tile::~Tile(){

}
