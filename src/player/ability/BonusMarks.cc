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

void BonusMarks::doEndTurn(vector<shared_ptr<Player>>& players) {
    playerComponent->endTurn(players);
    cout << playerComponent->Options()->name << "'s Bonus Marks ability has activated. They will now get 4 grades." << endl;
    playerComponent->modifyGrades(4); //TODO: 50% chance
}

