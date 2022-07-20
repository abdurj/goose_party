#include "tiles/GradeTile.h"

using namespace ftxui;

GradeTile::GradeTile(bool intersection) : Tile(intersection) {};

Element GradeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Yellow);
}

Element GradeTile::getElement() {
    return tileElement() | border;
};
