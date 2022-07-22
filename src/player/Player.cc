#include "player/Player.h"

Player::~Player() {}

void Player::Abilities() const {
    listAbilities();
}

void Player::endTurn() {
    doEndTurn();
}

void Player::endCycle() {
    doEndCycle();
}