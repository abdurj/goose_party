#include "tiles/Tile.h"

Tile::Tile(bool inter) : intersection{inter} {};

bool Tile::isIntersection(){
    return intersection;
}

Tile::~Tile(){

}
