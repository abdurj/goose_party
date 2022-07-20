#include "tiles/DegreeTile.h"

using namespace ftxui;

DegreeTile::DegreeTile(bool intersection) : Tile(intersection) {};

Element DegreeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Blue);
}

Element DegreeTile::getElement() {
    return tileElement() | border;
};
