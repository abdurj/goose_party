#include "player/ability/CopyCat.h"
#include <iostream>
using namespace std;

CopyCat::CopyCat(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->addAbility("CopyCat");
}

void CopyCat::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Copy Cat - This player copies the assignments of other players! Steal 5 grades from a player every cycle." << endl;
}

void CopyCat::doEndCycle(vector<shared_ptr<Player>>& players) {
    playerComponent->endCycle(players);
    cout << playerComponent->Options()->name << "'s Copy Cat ability has activated. Choose a player to steal 10 grades from." << endl;
    for(int i = 0; i < players.size(); ++i) {
        cout << i << ". " << players.at(i)->Options()->name << endl;
    }
    int victim;
    try {
        cin >> victim;
        playerComponent->modifyGrades(abs(players.at(victim)->modifyGrades(-10))); 
    } catch(...) {
        cout << "Error stealing grades from chosen player." << endl;
        cin.clear();
    }
    
    
}

