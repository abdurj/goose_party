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
    const PlayerClass pClass;
    const std::string name;
    const int id;
    int attack;
    int defence;
    int luck;
    PlayerOptions(PlayerClass, std::string, int);
};

#endif // PLAYER_OPTIONS_H
