#ifndef PLAYER_OPTIONS_H
#define PLAYER_OPTIONS_H
#include <string>
enum class PlayerClass {
    FIGHTER,
    DEFENDER,
    MESSENGER,
    ROGUE
};

struct PlayerOptions {
    PlayerClass pClass;
    std::string playerName;
    int playerNum;
    int attack;
    int defence;
    int luck;
    PlayerOptions(PlayerClass, std::string, int);
};

#endif // PLAYER_OPTIONS_H
