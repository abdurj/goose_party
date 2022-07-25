#include "player/ability/BonusMarks.h"
#include <iostream>
using namespace std;

BonusMarks::BonusMarks(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->addAbility("BonusMarks");
}

void BonusMarks::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Bonus Marks - Some of this player's assignments have bonus marks! 50\% chance of +4 grades per turn." << endl;
}

void BonusMarks::doEndTurn() {
    playerComponent->endTurn();
    playerComponent->modifyGrades(4); //TODO: 50% chance
}

