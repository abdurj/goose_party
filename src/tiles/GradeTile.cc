#include "tiles/GradeTile.h"
#include <iostream>
using namespace ftxui;

GradeTile::GradeTile(bool intersection) : Tile(intersection) {};

void GradeTile::apply(Player* p) {
    std::cout << "landed on grade tile" << std::endl;
}

Element GradeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Yellow);
}

Element GradeTile::getElement() {
    return tileElement() | border;
};
