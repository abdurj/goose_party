#ifndef PLAYER_H
#define PLAYER_H

enum class PlayerClass {
    FIGHTER,
    DEFENDER,
    MESSENGER,
    ROGUE
};

class Player{
    int degrees;
    int grades;
    int attack;
    int defence;
    int luck;
    public:
        Player(PlayerClass);

};

#endif // PLAYER_H
