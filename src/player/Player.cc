#include "player/Player.h"

using namespace ftxui;
using namespace std;

Player::Player(PlayerClass p): degrees{0}, grades{0}, name{"AbdurGay"}, playerNum{1} {
    switch (p) {
        case PlayerClass::FIGHTER:

        break;
        case PlayerClass::DEFENDER:
        
        break;
        case PlayerClass::MESSENGER:
        break;
        case PlayerClass::ROGUE:
        break;
        default:
            attack = 1;
            defence = 1;
            luck = 1;
        break;
    }
}

Element Player::getPlayerTile() {
    return text( "P" + to_string(playerNum)) | border | center;
}
