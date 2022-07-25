#include "player/ability/AllNighter.h"
#include <iostream>
using namespace std;

AllNighter::AllNighter(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->Options()->attack += 2;
}

void AllNighter::listAbilities(unordered_set<string> &set) const {
    unordered_set<string> compSet = playerComponent->Abilities();
    set.insert(compSet.begin(), compSet.end());
    cout << 
    "All Nighter - This player pulls all nighters to get things done! +2 to attack stat."
    << endl;
    set.insert("AllNighter");
}
