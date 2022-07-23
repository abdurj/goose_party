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

void JuiceCard::apply(shared_ptr<Player> p, Board &b) {
    cout << "juice card effect applied" << endl;
    // apply its effect
}

bool JuiceCard::requiresTarget() {
    // this particular spell card doesn't require a target
    return false;
}
