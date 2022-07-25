#include "cards/TrapCard.h"
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

void BossCard::activate(Player *p) {

}

void BossCard::apply(Player* caller, shared_ptr<Player> target, Board* b) {

}

bool BossCard::requiresTarget() {
    return false;
}

string BossCard::getName() {
    return "Boss Trap";
}

// Explosive Mine
void ExplosiveMine::activate(Player *p) {
    cout << "explosive mine activated. Lose 10 HP." << endl;
    p->modifyHP(-10);
}

void ExplosiveMine::apply(Player *caller, shared_ptr<Player> target, Board *b) {
    b->placeTrap(caller->Options()->id, make_unique<ExplosiveMine>());
}

bool ExplosiveMine::requiresTarget() {
    return false;
}

string ExplosiveMine::getName() {
    return "Explosive Mine";
}

// Policy 71 definition
void Policy71::activate(Player *victim) {
    victim->modifyGrades(INT32_MIN);
}

void Policy71::apply(Player *caller, shared_ptr<Player> target, Board *b) {
    cout << "Trap Placed" << endl;
    b->placeTrap(caller->Options()->id, make_unique<Policy71>());
}

bool Policy71::requiresTarget() {
    return false;
}

string Policy71::getName() {
    return "Policy71 Trap";
}
