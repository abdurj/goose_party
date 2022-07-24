#include "tiles/CardTile.h"
#include "player/Player.h"
#include "cards/Card.h"
#include "utils/Utils.h"
#include <iostream>
using namespace ftxui;
using namespace std;

CardTile::CardTile(bool intersection) : Tile(intersection) {};

void CardTile::apply(shared_ptr<Player> &p) {
    cout << "landed on card tile" << endl;
    p->addCard(move(utils::generateCard()));
}

Element CardTile::tileElement() {
    return text(" ") |  bgcolor(Color::OrangeRed1);
}

Element CardTile::getElement() {
    return tileElement() | border;
};
