#include "player/ability/PerfectGpa.h"
#include <iostream>
using namespace std;

PerfectGpa::PerfectGpa(shared_ptr<Player> p) : count{1}, PlayerDecorator{p} {}

void PerfectGpa::listAbilities(unordered_set<string> &set) const {
    unordered_set<string> compSet = playerComponent->Abilities();
    set.insert(compSet.begin(), compSet.end());
    cout << "Perfect GPA - After a long grind, this player has maintained an impressive 4.0 GPA! +16 grades every 4 cycles" << endl;
    set.insert("PerfectGpa");
}

void PerfectGpa::doEndCycle() {
    playerComponent->endCycle();
    count = (count+1)%4;
    if(count == 0) {
        playerComponent->modifyGrades(10);
    }
}

