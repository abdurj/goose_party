#include "tiles/CardTile.h"
#include "player/Player.h"
#include "cards/Card.h"
#include "utils/Utils.h"
#include <iostream>
using namespace ftxui;
using namespace std;

CardTile::CardTile(int type) : Tile(type) {};

void CardTile::apply(shared_ptr<Player> &p) {
    cout << "Landed on card tile" << endl;
    unique_ptr<Card> card = utils::generateCard();
    cout << p->Options()->name << " has obtained a " << card->getName() << " card!" << endl;
    p->addCard(move(card));
}

Element CardTile::tileElement() {
    return text(" ") |  bgcolor(Color::OrangeRed1);
}

Element CardTile::getElement() {
    return tileElement() | border;
};
