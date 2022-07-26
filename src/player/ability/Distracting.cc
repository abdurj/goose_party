#include "player/ability/Distracting.h"
#include <iostream>
using namespace std;

Distracting::Distracting(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->addAbility("Distracting");
}

void Distracting::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Distracting - This player ruins the focus of all players! Do 1 damage to all players (except self) every cycle." << endl;
}

void Distracting::doEndCycle(vector<shared_ptr<Player>>& players) {
    playerComponent->endCycle(players);
    cout << playerComponent->Options()->name << "'s Distracting ability has activated. Damaging all players except self." << endl;
    for(int i = 0; i < players.size(); ++i) {
        if(playerComponent->Options()->id != players.at(i)->Options()->id) {
            cout << players.at(i)->Options()->id << endl;
            players.at(i)->modifyHP(-1);
        }
        
    }
    
}

