#include "player/PlayerDecorator.h"
#include <iostream>
using namespace std;

PlayerDecorator::~PlayerDecorator() {}

void PlayerDecorator::doEndCycle() {
    playerComponent->endCycle();

}

void PlayerDecorator::doEndTurn() {
    playerComponent->endTurn();
}
void PlayerDecorator::listAbilities() const {}

PlayerDecorator::PlayerDecorator(shared_ptr<Player> p) : playerComponent{p} {}

int PlayerDecorator::Grades() const {
    return playerComponent->Grades();
}
int PlayerDecorator::Degrees() const {
    return playerComponent->Degrees();
}
int PlayerDecorator::modifyGrades(int n) {
    return playerComponent->modifyGrades(n);
}
bool PlayerDecorator::claimDegree() {
    return playerComponent->claimDegree();
}

void PlayerDecorator::addCard(unique_ptr<Card> p) {
    playerComponent->addCard(move(p));
}

int PlayerDecorator::listCards() const {
    return playerComponent->listCards();
}

void PlayerDecorator::useCard(int i, shared_ptr<Player> p, Board* b) {
    playerComponent->useCard(i, p, b);
}

bool PlayerDecorator::requiresTarget(int i) {
    return playerComponent->requiresTarget(i);
}

shared_ptr<PlayerOptions> PlayerDecorator::Options() const {
    return playerComponent->Options();
}
ftxui::Element PlayerDecorator::getPlayerTile() {
    return playerComponent->getPlayerTile();
}

int PlayerDecorator::getHP() const{
    return playerComponent->getHP();
}

bool PlayerDecorator::alive() const {
    return playerComponent->alive();
}

void PlayerDecorator::takeDamage(int dmg) {
    playerComponent->takeDamage(dmg);
}

void PlayerDecorator::reset() {
    playerComponent->reset();
}
