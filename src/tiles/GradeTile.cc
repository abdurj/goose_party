#include "tiles/GradeTile.h"
#include "utils/Utils.h"
#include <iostream>
using namespace ftxui;
using namespace std;

GradeTile::GradeTile(bool intersection) : Tile(intersection) {};

void GradeTile::apply(std::shared_ptr<Player> p) {
    cout << "landed on grade tile" << endl;
    int roll = utils::roll(p, 20);
    p->addGrades(roll); //TODO: adds amt based on a roll
}

Element GradeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Yellow);
}

Element GradeTile::getElement() {
    return tileElement() | border;
};
