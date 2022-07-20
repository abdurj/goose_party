#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerOptions.h"
#include "ftxui/dom/elements.hpp"
#include <string.h>

class Player{
    int degrees;
    int grades;
    PlayerOptions options;
    public:
        Player(PlayerOptions);
        virtual int Grades() const;
        virtual void addGrades(int); //maybe doesn't need to be virtual
        ftxui::Element getPlayerTile();  
};

#endif // PLAYER_H
