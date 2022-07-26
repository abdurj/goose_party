#include "player/Player.h"
#include "cards/spells/HealthCard.h"
#include "utils/Utils.h"
#include "board/Board.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

// Health Card
HealthCard::HealthCard() {}
void HealthCard::apply(Player *caller, shared_ptr<Player> target, Board *b) {
    cout << "Healing for 10 HP" << endl;
    target->modifyHP(10);
}
bool HealthCard::requiresTarget() {
    return true;
}
string HealthCard::getName() {
    return "Healing";
}
string HealthCard::getDescription() {
    return "Heals for 10 HP";
}
