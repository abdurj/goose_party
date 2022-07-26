#include "player/PlayerDecorator.h"
#include "cards/Card.h"
#include <iostream>
using namespace std;

PlayerDecorator::~PlayerDecorator() {}

void PlayerDecorator::doEndCycle(vector<shared_ptr<Player>>& players) {
    playerComponent->endCycle(players);

}

void PlayerDecorator::doEndTurn(vector<shared_ptr<Player>>& players) {
    playerComponent->endTurn(players);
}

void PlayerDecorator::abilityDesc() const {
}
void PlayerDecorator::addAbility(string s) {
    playerComponent->addAbility(s);
}

const unordered_set<string>& PlayerDecorator::Abilities() const {
    return playerComponent->Abilities();
}

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

void PlayerDecorator::cardDescriptions() const {
    playerComponent->cardDescriptions();
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

void PlayerDecorator::modifyHP(int dmg) {
    playerComponent->modifyHP(dmg);
}

void PlayerDecorator::reset() {
    playerComponent->reset();
}

void PlayerDecorator::info() const{
    playerComponent->info();
}