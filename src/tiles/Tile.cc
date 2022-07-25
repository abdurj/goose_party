#include "tiles/Tile.h"
using namespace ftxui;

Tile::Tile(bool inter, bool elbow) : intersection{inter}, elbow{elbow} {};

bool Tile::isIntersection() const{
    return intersection;
}

bool Tile::isElbow() const{
    return elbow;
}

Tile::~Tile(){

}
