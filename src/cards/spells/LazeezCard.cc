// Lazeez
#include "player/Player.h"
#include "utils/Utils.h"
#include "board/Board.h"
#include "cards/spells/LazeezCard.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

LazeezCard::LazeezCard() {}
void LazeezCard::apply(Player *caller, std::shared_ptr<Player> p, Board* b) {
    cout << "Dealing 8 damage to " << p->Options()->name << "." << endl;
    p->modifyHP(-8);
}
bool LazeezCard::requiresTarget() {
    return true;
}
string LazeezCard::getName() {
    return "Tactical Nutrition";
}

string LazeezCard::getDescription() {
    return "Deal 8 damage to a player of your choice.";
}
