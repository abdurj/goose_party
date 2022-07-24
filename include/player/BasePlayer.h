#ifndef BASEPLAYER_H
#define BASEPLAYER_H
#include "PlayerOptions.h"
#include "cards/Card.h"
#include "player/Player.h"
#include "ftxui/dom/elements.hpp"

class BasePlayer : public Player {
    void doEndTurn() override; //Better name suggestions?
    void doEndCycle() override;
    void listAbilities() const override;
    int degrees;
    int grades;
    int hp = 20;
    std::shared_ptr<PlayerOptions> options;
    std::vector<std::unique_ptr<Card>> deck;

    public:
    BasePlayer(std::shared_ptr<PlayerOptions>);
    int Grades() const override;
    int Degrees() const override;
    int modifyGrades(int) override; //Maybe doesn't need to be virtual? Will we have stuff that lets them get more gold?
    bool claimDegree() override;
    void addCard(std::unique_ptr<Card>) override;
    int listCards() const override;
    void useCard(int, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget(int) override;
    bool alive() const override;
    void takeDamage(int) override;
    void reset() override;


    std::shared_ptr<PlayerOptions> Options() const override;
    ftxui::Element getPlayerTile() override;
};

#endif
