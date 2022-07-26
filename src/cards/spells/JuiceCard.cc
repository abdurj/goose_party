#include "cards/spells/JuiceCard.h"
#include "player/Player.h"
#include "utils/Utils.h"
#include "board/Board.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

JuiceCard::JuiceCard() {

}

string JuiceCard::getName() {
    return "Juice Card";
}

string JuiceCard::getDescription() {
    return "When used, provides a 1 in 4 chance to give the caller 30 grades. Else, a penalty is applied instead.";
}

void JuiceCard::apply(Player *caller, shared_ptr<Player> target, Board *b) {
    int roll = utils::roll();
    if (roll < 4) {
        cout << "Success! Giving 30 grades to " << caller->Options()->name << endl;
        caller->modifyGrades(30);
    } else {
        cout << "Unlucky. Deducting 10 grades from " << caller->Options()->name << endl;
        caller->modifyGrades(-10);
    }
    // apply its effect
}

bool JuiceCard::requiresTarget() {
    // this particular spell card doesn't require a target
    return false;
}
