#include "player/Player.h"
#include "utils/Utils.h"
#include "board/Board.h"
#include "cards/spells/PortalCard.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

// Portal Card
PortalCard::PortalCard() {}
string PortalCard::getName() {
    return "Portal Card";
}

string PortalCard::getDescription() {
    return "Swap positions with a player of your choice.";
}

void PortalCard::apply(Player * caller, shared_ptr<Player> target, Board *b) {
    // portal card effect
    int callerID = caller->Options()->id;
    int targetID = target->Options()->id;
    b->swapPositions(callerID, targetID);
    cout << "Portal Card Used. Swapped the positions of players " << callerID << " and " << targetID << "." << endl;
}

bool PortalCard::requiresTarget() {
    return true;
}
