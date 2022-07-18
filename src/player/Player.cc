#include "player/Player.h"

Player::Player(PlayerClass p): degrees{0}, grades{0} {
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
