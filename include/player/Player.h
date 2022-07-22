#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerOptions.h"
#include "ftxui/dom/elements.hpp"
#include <string.h>

class Player { //Abstract base class
    virtual void listAbilities() const = 0;
    virtual void doEndTurn() = 0; //Better name suggestions?
    virtual void doEndCycle() = 0;

    public:
    virtual int Grades() const = 0;
    virtual int Degrees() const = 0;
    virtual int modifyGrades(int) = 0;
    virtual bool claimDegree() = 0;
    void Abilities() const;
    void endTurn();
    void endCycle();
    virtual std::shared_ptr<PlayerOptions> Options() const = 0;
    virtual ftxui::Element getPlayerTile() = 0;

    virtual ~Player() = 0;
};

#endif // PLAYER_H
