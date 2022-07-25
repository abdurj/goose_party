#include "player/ability/TimeManagement.h"
#include <iostream>
using namespace std;

TimeManagement::TimeManagement(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->Options()->defence += 2;
    p->addAbility("TimeManagement");
}

void TimeManagement::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << 
    "Time Management - This player never leaves things to the last minute! +2 to defence stat."
    << endl;
}
