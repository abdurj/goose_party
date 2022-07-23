#include "tiles/CardTile.h"
#include "player/Player.h"
#include "cards/Card.h"
#include <iostream>
using namespace ftxui;
using namespace std;

CardTile::CardTile(bool intersection) : Tile(intersection) {};

void CardTile::apply(std::shared_ptr<Player> p) {
    cout << "landed on card tile" << endl;
    p->addCard(make_unique<JuiceCard>());
}

Element CardTile::tileElement() {
    return text(" ") |  bgcolor(Color::OrangeRed1);
}

Element CardTile::getElement() {
    return tileElement() | border;
};
