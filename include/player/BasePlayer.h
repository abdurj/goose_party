#ifndef BASEPLAYER_H
#define BASEPLAYER_H
#include "PlayerOptions.h"
#include "player/Player.h"
#include "ftxui/dom/elements.hpp"

class BasePlayer : public Player {
    void doEndTurn() override; //Better name suggestions?
    void doEndCycle() override;
    void listAbilities() const override;
    int degrees;
    int grades;
    std::shared_ptr<PlayerOptions> options;

    public:
    BasePlayer(std::shared_ptr<PlayerOptions>);
    int Grades() const override;
    int Degrees() const override;
    int modifyGrades(int) override; //Maybe doesn't need to be virtual? Will we have stuff that lets them get more gold?
    bool claimDegree() override;
    std::shared_ptr<PlayerOptions> Options() const override;
    ftxui::Element getPlayerTile() override;
};

#endif
