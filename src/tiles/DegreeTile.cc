#include "tiles/DegreeTile.h"
#include <iostream>
using namespace ftxui;

DegreeTile::DegreeTile(bool intersection) : Tile(intersection) {};

void DegreeTile::apply(Player * p) {
    std::cout << "landed on degree tile" << std::endl;
}

Element DegreeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Blue);
}

Element DegreeTile::getElement() {
    return tileElement() | border;
};
