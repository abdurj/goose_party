#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "PlayerOptions.h"
#include "ftxui/dom/elements.hpp"
#include "cards/Card.h"
class Card; // for some reason it won't compile if I don't do this, even if I have card.h included
class Board;
class Player { //Abstract base class
    virtual void listAbilities() const = 0;
    virtual void doEndTurn() = 0; //Better name suggestions?
    virtual void doEndCycle() = 0;

    public:
    virtual int Grades() const = 0;
    virtual int Degrees() const = 0;
    virtual int modifyGrades(int) = 0;
    virtual bool claimDegree() = 0;
    virtual void addCard(std::unique_ptr<Card>) = 0;
    virtual int listCards() const = 0;
    virtual void useCard(int, std::shared_ptr<Player>, Board*) = 0;
    virtual bool requiresTarget(int) = 0;
    virtual bool alive() const = 0;
    virtual void takeDamage(int) = 0;
    virtual void reset() = 0;

    void Abilities() const;
    void endTurn();
    void endCycle();
    virtual std::shared_ptr<PlayerOptions> Options() const = 0;
    virtual ftxui::Element getPlayerTile() = 0;

    virtual ~Player() = 0;
};

#endif // PLAYER_H
