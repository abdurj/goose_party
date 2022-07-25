#include "player/ability/PerfectGpa.h"
#include <iostream>
using namespace std;

PerfectGpa::PerfectGpa(shared_ptr<Player> p) : count{1}, PlayerDecorator{p} {
    p->addAbility("PerfectGpa");
}

void PerfectGpa::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Perfect GPA - After a long grind, this player has maintained an impressive 4.0 GPA! +16 grades every 4 cycles" << endl;
}

void PerfectGpa::doEndCycle() {
    playerComponent->endCycle();
    count = (count+1)%4;
    if(count == 0) {
        playerComponent->modifyGrades(10);
    }
}

