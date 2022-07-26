#include "player/ability/Attendance.h"
#include <iostream>
using namespace std;

Attendance::Attendance(shared_ptr<Player> p) : count{1}, PlayerDecorator{p} {
    p->addAbility("Attendance");
}

void Attendance::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Attendance - Rain, snow, or 8:30 lectures, no matter the obstacle, this player always attends their lectures! +8 grades every 2 turns." << endl;
}

void Attendance::doEndTurn(vector<shared_ptr<Player>>& players) {
    playerComponent->endTurn(players);
    count = (count+1)%4;
    if(count == 0) {
        cout << playerComponent->Options()->name << "'s Attendance ability has activated. They will now get 8 grades." << endl;
        playerComponent->modifyGrades(8);
    }
}

