#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerOptions.h"
#include "ftxui/dom/elements.hpp"
#include <string.h>

class Player{
    int degrees;
    int grades;
    PlayerOptions options;

    virtual int getAttack() const;
    virtual int getDefence() const;
    virtual int getLuck() const;

    public:
        Player(PlayerOptions);
        int Grades() const;
        int Degrees() const;
        int Attack() const;
        int Defence() const;
        int Luck() const;
        void addGrades(int); //Maybe doesn't need to be virtual? Will we have stuff that lets them get more gold?
        int deductGrades(int); //Also maybe not virtual? Will we have an ability like lose less gold, etc?
        bool claimDegree();
        std::string Name() const;
        int PlayerNum() const;
        ftxui::Element getPlayerTile();  
};

#endif // PLAYER_H
