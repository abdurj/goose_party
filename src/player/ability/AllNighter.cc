#include "player/ability/AllNighter.h"
#include <iostream>
using namespace std;

AllNighter::AllNighter(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->Options()->attack += 2;
    p->addAbility("AllNighter");
}

void AllNighter::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << 
    "All Nighter - This player pulls all nighters to get things done! +2 to attack stat."
    << endl;
}
