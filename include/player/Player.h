#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerOptions.h"
#include "ftxui/dom/elements.hpp"
#include <string.h>

class Player{
    int degrees;
    int grades;
    std::shared_ptr<PlayerOptions> options;
    public:
        Player(std::shared_ptr<PlayerOptions>);
        int Grades() const;
        int Degrees() const;
        int modifyGrades(int); //Maybe doesn't need to be virtual? Will we have stuff that lets them get more gold?
        bool claimDegree();

        std::shared_ptr<PlayerOptions> Options() const;
        ftxui::Element getPlayerTile();
};

#endif // PLAYER_H
