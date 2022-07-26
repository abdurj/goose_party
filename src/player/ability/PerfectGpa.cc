#include "player/ability/PerfectGpa.h"
#include <iostream>
using namespace std;

PerfectGpa::PerfectGpa(shared_ptr<Player> p) : count{0}, PlayerDecorator{p} {
    p->addAbility("PerfectGpa");
}

void PerfectGpa::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Perfect GPA - After a long grind, this player has maintained an impressive 4.0 GPA! +20 grades every 4 cycles" << endl;
}

void PerfectGpa::doEndCycle(vector<shared_ptr<Player>>& players) {
    playerComponent->endCycle(players);
    count = (count+1)%4;
    if(count == 0) {
        cout << playerComponent->Options()->name << "'s Perfect Gpa ability has activated. They will now get 20 grades." << endl;
        playerComponent->modifyGrades(20);
    }
}

