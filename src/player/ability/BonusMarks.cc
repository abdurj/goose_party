#include "player/ability/BonusMarks.h"
#include "utils/Utils.h"
#include <iostream>
using namespace std;

BonusMarks::BonusMarks(shared_ptr<Player> p) : PlayerDecorator{p} {}

void BonusMarks::listAbilities(unordered_set<string> &set) const {
    unordered_set<string> compSet = playerComponent->Abilities();
    set.insert(compSet.begin(), compSet.end());
    cout << "Bonus Marks - Some of this player's assignments have bonus marks! 50\% chance of +4 grades per turn." << endl;
    set.insert("BonusMarks");
}

void BonusMarks::doEndTurn() {
    playerComponent->endTurn();
    playerComponent->modifyGrades(4); //TODO 50% chance
}

