#include "cards/TrapCard.h"
#include "board/Board.h"
#include "player/Player.h"
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

void BossCard::activate(std::shared_ptr<Player> p) {

}

void BossCard::apply(Player* caller, shared_ptr<Player> target, Board* b) {

}

bool BossCard::requiresTarget() {
    return false;
}

string BossCard::getName() {
    return "Boss Trap";
}

string BossCard::getDescription() {
    return "Leaked Info!";
}

// Explosive Mine
void ExplosiveMine::activate(std::shared_ptr<Player> p) {
    cout << "EXPLOSIVE MINE ACTIVATED. Lose 10 HP." << endl;
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

string ExplosiveMine::getDescription() {
    return "Places a trap at current tile. If a player steps on this tile, they will take 10 damage.";
}

// Policy 71 definition
void Policy71::activate(std::shared_ptr<Player> victim) {
    cout << "Policy 71 TRAP ACTIVATED." << victim->Options()->name << " loses ALL their grades!" << endl;
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

string Policy71::getDescription() {
    return "Places a trap at current tile when used. If a player steps on this tile, they will lose ALL of their grades.";
}
