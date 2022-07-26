#include "player/Player.h"
#include "utils/Utils.h"
#include "board/Board.h"
#include "cards/spells/PredatorCard.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
// Predator Card
PredatorCard::PredatorCard() {}
void PredatorCard::apply(Player *caller, shared_ptr<Player> target, Board *b) {
    cout << "Stealing 15 grades from " << target->Options()->name << "." << endl;
    int amount = target->modifyGrades(-15);
    caller->modifyGrades(amount);
}
bool PredatorCard::requiresTarget() {
    return true;
}
string PredatorCard::getName() {
    return "Predator";
}

string PredatorCard::getDescription() {
    return "Steals 15 grades from a target player.";
}
