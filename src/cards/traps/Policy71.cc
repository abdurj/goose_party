#include "cards/traps/Policy71.h"
#include "board/Board.h"
#include "player/Player.h"
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

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
