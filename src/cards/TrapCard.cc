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
    cout << "explosive mine activated" << endl;
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


