#include "player/PlayerOptions.h"
#include <string>
using namespace std;
PlayerOptions::PlayerOptions(PlayerClass p, string name, int num): pClass{p}, playerName{name}, playerNum{num} {
    switch (p) {
        case PlayerClass::FIGHTER:
            attack = 3;
            defence = 1;
            luck = 0;
        break;
        case PlayerClass::DEFENDER:
            attack = 1;
            defence = 3;
            luck = 0;
        break;
        case PlayerClass::MESSENGER:
            attack = 1;
            defence = 1;
            luck = 2;
        break;
        case PlayerClass::ROGUE:
            attack = 1;
            defence = 0;
            luck = 3;
        break;
        default:
            attack = 1;
            defence = 1;
            luck = 1;
        break;
    }
};