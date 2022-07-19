#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerOptions.h"
#include "ftxui/dom/elements.hpp"
#include <string.h>

class Player{
    int degrees;
    int grades;
    int attack;
    int defence;
    int luck;
    std::string name;
    int playerNum;
    public:
        Player(PlayerClass);
        Player(PlayerClass, int, std::string);
        Player(int, std::string);
        ftxui::Element getPlayerTile();  
};

#endif // PLAYER_H
