#include "player/ability/TimeManagement.h"
#include <iostream>
using namespace std;

TimeManagement::TimeManagement(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->Options()->defence += 2;
}

void TimeManagement::listAbilities(unordered_set<string> &set) const {
    unordered_set<string> compSet = playerComponent->Abilities();
    set.insert(compSet.begin(), compSet.end());
    cout << 
    "Time Management - This player never leaves things to the last minute! +2 to defence stat."
    << endl;
    set.insert("TimeManagement");
}
