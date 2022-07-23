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
}

bool PortalCard::requiresTarget() {
    return true;
}
