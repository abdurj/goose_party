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

void PlayerDecorator::listCards() const {
    playerComponent->listCards();
}

shared_ptr<PlayerOptions> PlayerDecorator::Options() const {
    return playerComponent->Options();
}
ftxui::Element PlayerDecorator::getPlayerTile() {
    return playerComponent->getPlayerTile();
}
