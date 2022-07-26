#include "player/ability/Overloading.h"
#include <iostream>
using namespace std;

Overloading::Overloading(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->addAbility("Overloading");
}

void Overloading::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Overloading - This player is overloading their current term! +1 roll when moving." << endl;
}

int Overloading::getRolls() const {
    cout << playerComponent->Options()->name << "'s Overloading ability has activated. They will now get an extra roll." << endl;
    return playerComponent->Rolls() + 1;
}

