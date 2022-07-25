#include "player/ability/GradeCurve.h"
#include <iostream>
using namespace std;

GradeCurve::GradeCurve(shared_ptr<Player> p) : PlayerDecorator{p} {}

void GradeCurve::listAbilities(unordered_set<string> &set) const {
    unordered_set<string> compSet = playerComponent->Abilities();
    set.insert(compSet.begin(), compSet.end());
    cout << "Grade Curve - Some of this player's finals were curved! +10 grades per cycle." << endl;
    set.insert("GradeCurve");
}

void GradeCurve::doEndCycle() {
    playerComponent->endCycle();
    playerComponent->modifyGrades(10);
}

