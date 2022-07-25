#include "cards/SpellCard.h"
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
void LazeezCard::apply(Player *caller, std::shared_ptr<Player> p, Board* b) {
    cout << "Dealing 8 damage to " << p->Options()->name << "." << endl;
    p->modifyHP(-8);
}
bool LazeezCard::requiresTarget() {
    return true;
}
string LazeezCard::getName() {
    return "Tactical Nutrition";
}

// CS247
CS247Card::CS247Card() {}
void CS247Card::apply(Player* caller, shared_ptr<Player> target, Board* b) {
    int roll = utils::roll();
    if (roll < 4) {
        cout << "Success! Moving " << target->Options()->name << "10 spaces forward." << endl;
        b->move(target, 20);
    } else {
        cout << "Failure! " << caller->Options()->name << " takes 10 damage." << endl;
        caller->modifyHP(-10);
    }
}
bool CS247Card::requiresTarget() {
    return true;
}
string CS247Card::getName() {
    return "CS247";
}

// Predator Card
PredatorCard::PredatorCard() {}
void PredatorCard::apply(Player *caller, shared_ptr<Player> target, Board *b) {
    cout << "Stealing 15 grades from " << target->Options()->name << "." << endl;
    caller->modifyGrades(15);
    target->modifyGrades(-15);
}
bool PredatorCard::requiresTarget() {
    return true;
}
string PredatorCard::getName() {
    return "Predator";
}
