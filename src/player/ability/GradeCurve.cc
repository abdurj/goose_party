#include "player/ability/GradeCurve.h"
#include <iostream>
using namespace std;

GradeCurve::GradeCurve(shared_ptr<Player> p) : PlayerDecorator{p} {
    p->addAbility("GradeCurve");
}

void GradeCurve::abilityDesc() const {
    playerComponent->ListAbilities();
    cout << "Grade Curve - Some of this player's finals were curved! +10 grades per cycle." << endl;
}

void GradeCurve::doEndCycle() {
    playerComponent->endCycle();
    playerComponent->modifyGrades(10);
}

