#ifndef BASEPLAYER_H
#define BASEPLAYER_H

#include <unordered_set>
#include "PlayerOptions.h"
#include "cards/Card.h"
#include "player/Player.h"
#include "ftxui/dom/elements.hpp"

class BasePlayer : public Player {
    void doEndTurn(std::vector<std::shared_ptr<Player>>&) override; //Better name suggestions?
    void doEndCycle(std::vector<std::shared_ptr<Player>>&) override;
    void abilityDesc() const override;
    int getRolls() const override;
    int degrees;
    int grades;
    int hp = 20;
    std::shared_ptr<PlayerOptions> options;
    std::vector<std::unique_ptr<Card>> deck;
    std::unordered_set<std::string> abilities;

    public:
    BasePlayer(std::shared_ptr<PlayerOptions>);
    void addAbility(std::string) override;
    const std::unordered_set<std::string>& Abilities() const override;
    void info() const override;
    int Grades() const override;
    int Degrees() const override;
    int modifyGrades(int) override; //Maybe doesn't need to be virtual? Will we have stuff that lets them get more gold?
    bool claimDegree() override;
    void addCard(std::unique_ptr<Card>) override;
    int listCards() const override;
    void cardDescriptions() const override;
    void useCard(int, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget(int) override;
    int getHP() const override;
    bool alive() const override;
    void modifyHP(int) override;
    void reset() override;


    std::shared_ptr<PlayerOptions> Options() const override;
};

#endif
