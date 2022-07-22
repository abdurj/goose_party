#include "ability/GradeCurve.h"
#include <iostream>
using namespace std;

GradeCurve::GradeCurve(shared_ptr<Player> p) : PlayerDecorator{p} {}

void GradeCurve::listAbilities() const {
    playerComponent->Abilities();
    cout << "Grade Curve - Some of your finals were curved! +10 grades per cycle." << endl;
}

void GradeCurve::doEndCycle() {
    playerComponent->endCycle();
    playerComponent->modifyGrades(10);
}

