#include "tiles/GradeTile.h"
#include "utils/Utils.h"
#include <iostream>
using namespace ftxui;
using namespace std;

GradeTile::GradeTile(int type) : Tile(type) {};

void GradeTile::apply(shared_ptr<Player> &p) {
    cout << "Landed on grade tile!" << endl;
    int roll = utils::roll() + 20;
    cout << p->Options()->name << " has obtained " << roll << " grades!";
    p->modifyGrades(roll); //TODO: adds amt based on a roll
}

Element GradeTile::tileElement() {
    return text(" ") |  bgcolor(Color::Yellow);
}

Element GradeTile::getElement() {
    return tileElement() | border;
};
