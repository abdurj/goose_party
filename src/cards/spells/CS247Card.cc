#include "player/Player.h"
#include "utils/Utils.h"
#include "board/Board.h"
#include "cards/spells/CS247Card.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

// CS247
CS247Card::CS247Card() {}
void CS247Card::apply(Player* caller, shared_ptr<Player> target, Board* b) {
    int roll = utils::roll();
    if (roll < 4) {
        cout << "Success! Moving " << target->Options()->name << "10 spaces forward." << endl;
        b->move(target, 10);
    } else {
        cout << "Failure! " << target->Options()->name << " takes 10 damage." << endl;
        target->modifyHP(-10);
    }
}
bool CS247Card::requiresTarget() {
    return true;
}
string CS247Card::getName() {
    return "CS247";
}

string CS247Card::getDescription() {
    return "When used, grants a 1 in 4 chance to move the target 10 spaces forward. Else, the target takes 10 damage.";
}
