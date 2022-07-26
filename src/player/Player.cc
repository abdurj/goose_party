#include "player/Player.h"
using namespace std;

Player::~Player() {}

void Player::endTurn(vector<shared_ptr<Player>>& players) {
    doEndTurn(players);
}

void Player::endCycle(vector<shared_ptr<Player>>& players) {
    doEndCycle(players);
}

void Player::ListAbilities() const {
    abilityDesc();
}