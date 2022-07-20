#include "tiles/Tile.h"
using namespace ftxui;

Tile::Tile(bool inter) : intersection{inter} {};

bool Tile::isIntersection(){
    return intersection;
}

Tile::~Tile(){

}
