#include "player/Player.h"
using namespace std;

Player::~Player() {}

unordered_set<string> Player::Abilities() const {
    unordered_set<string> playerAbilties;
    listAbilities(playerAbilties);
    return playerAbilties;
}

void Player::endTurn() {
    doEndTurn();
}

void Player::endCycle() {
    doEndCycle();
}