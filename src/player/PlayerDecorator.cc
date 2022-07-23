#include "player/PlayerDecorator.h"

using namespace std;

PlayerDecorator::~PlayerDecorator() {}

//TODO: Is there a way I can avoid creating empty methods for these?
void PlayerDecorator::doEndCycle() {}
void PlayerDecorator::doEndTurn() {}
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
