#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <unordered_set>
#include <vector>

#include "PlayerOptions.h"
#include "ftxui/dom/elements.hpp"

class Card;
class Board;

class Player { //Abstract base class
    virtual void abilityDesc() const = 0;
    virtual void doEndTurn(std::vector<std::shared_ptr<Player>>&) = 0;
    virtual void doEndCycle(std::vector<std::shared_ptr<Player>>&) = 0;

    public:
    virtual int Grades() const = 0;
    virtual int Degrees() const = 0;
    virtual int modifyGrades(int) = 0;
    virtual bool claimDegree() = 0;
    virtual void addCard(std::unique_ptr<Card>) = 0;
    virtual int listCards() const = 0;
    virtual void cardDescriptions() const = 0;
    virtual void useCard(int, std::shared_ptr<Player>, Board*) = 0;
    virtual bool requiresTarget(int) = 0;
    virtual int getHP() const = 0;
    virtual bool alive() const = 0;
    virtual void modifyHP(int) = 0;
    virtual void reset() = 0;

    virtual void addAbility(std::string) = 0;
    virtual const std::unordered_set<std::string>& Abilities() const = 0;
    void ListAbilities() const;
    void endTurn(std::vector<std::shared_ptr<Player>>&);
    void endCycle(std::vector<std::shared_ptr<Player>>&);
    virtual std::shared_ptr<PlayerOptions> Options() const = 0;
    virtual ftxui::Element getPlayerTile() = 0;

    virtual ~Player() = 0;
};

#endif // PLAYER_H
