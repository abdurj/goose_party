#include "cards/traps/Boss.h"
#include "board/Board.h"
#include "player/Player.h"
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

void BossCard::activate(std::shared_ptr<Player> p) {

}

void BossCard::apply(Player* caller, shared_ptr<Player> target, Board* b) {

}

bool BossCard::requiresTarget() {
    return false;
}

string BossCard::getName() {
    return "Boss Trap";
}

string BossCard::getDescription() {
    return "Leaked Info!";
}
