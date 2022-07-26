#include "cards/traps/Explosive.h"
#include "board/Board.h"
#include "player/Player.h"
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

// Explosive Mine
void ExplosiveMine::activate(std::shared_ptr<Player> p) {
    cout << "KERBLAM!. Lose 10 HP." << endl;
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
