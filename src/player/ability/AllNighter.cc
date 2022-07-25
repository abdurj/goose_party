#include "player/ability/AllNighter.h"
#include <iostream>
using namespace std;

AllNighter::AllNighter(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->Options()->attack += 2;
}

void AllNighter::listAbilities() const {
    playerComponent->Abilities();
    cout << 
    "All Nighter - This player pulls all nighters to get things done! +2 to attack stat."
    << endl;
}
