#include "player/ability/GoodSleep.h"
#include <iostream>
using namespace std;

GoodSleep::GoodSleep(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->Options()->attack += 1;
    p->Options()->defence += 1;
    p->Options()->luck += 1;
}

void GoodSleep::listAbilities(unordered_set<string> &set) const {
    unordered_set<string> compSet = playerComponent->Abilities();
    set.insert(compSet.begin(), compSet.end());
    cout << 
    "Good Sleep - Unlike the average UW student, this player has been getting enough sleep! +1 to all stats."
    << endl;
    set.insert("GoodSleep");
}
