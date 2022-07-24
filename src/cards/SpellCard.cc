#include "cards/SpellCard.h"
#include "player/Player.h"
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

JuiceCard::JuiceCard() {

}

string JuiceCard::getName() {
    return "Juice Card";
}

void JuiceCard::apply(Player *caller, shared_ptr<Player> target, Board *b) {
    cout << "juice card effect applied" << endl;
    // apply its effect
}

bool JuiceCard::requiresTarget() {
    // this particular spell card doesn't require a target
    return false;
}

// Portal Card
PortalCard::PortalCard() {}
string PortalCard::getName() {
    return "Portal Card";
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

// Lazeez

LazeezCard::LazeezCard() {}
void LazeezCard::apply(Player *, std::shared_ptr<Player>, Board*) {

}
bool LazeezCard::requiresTarget() {
    return false;
}
string LazeezCard::getName() {
    return "Lazeez";
}

// CS247
CS247Card::CS247Card() {}
void CS247Card::apply(Player* caller, shared_ptr<Player> target, Board* b) {

}
bool CS247Card::requiresTarget() {
    return false;
}
string CS247Card::getName() {
    return "CS247";
}

// Predator Card
PredatorCard::PredatorCard() {}
void PredatorCard::apply(Player *caller, shared_ptr<Player> target, Board *b) {

}
bool PredatorCard::requiresTarget() {
    return true;
}
string PredatorCard::getName() {
    return "Predator";
}
