#include "tiles/GradeTile.h"
#include "utils/Utils.h"
#include <iostream>
using namespace ftxui;
using namespace std;

GradeTile::GradeTile(bool intersection) : Tile(intersection) {};

void GradeTile::apply(std::shared_ptr<Player> p) {
    cout << "landed on grade tile" << endl;
    p->addGrades(100); //TODO: adds amt based on a roll
}

Element GradeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Yellow);
}

Element GradeTile::getElement() {
    return tileElement() | border;
};
