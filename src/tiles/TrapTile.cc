#include "tiles/TrapTile.h"

using namespace ftxui;

TrapTile::TrapTile(Tile* t) : TileDecorator(t) {};

Element TrapTile::stylize(Element e){
    return e | borderHeavy | color(Color::MediumPurple2Bis);
}
