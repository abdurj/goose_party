#include "player/Player.h"
using namespace std;

Player::~Player() {}

void Player::endTurn() {
    doEndTurn();
}

void Player::endCycle() {
    doEndCycle();
}

void Player::ListAbilities() const {
    abilityDesc();
}