#ifndef PLAYERDECO_H
#define PLAYERDECO_H

#include "player/Player.h"

class PlayerDecorator : public Player {
    void doEndTurn() override; //Better name suggestions?
    void doEndCycle() override;
    void listAbilities() const override;

    protected:
    std::shared_ptr<Player> playerComponent;
    public:
    PlayerDecorator(std::shared_ptr<Player>);
    int Grades() const override;
    int Degrees() const override;
    int modifyGrades(int) override;
    bool claimDegree() override;
    std::shared_ptr<PlayerOptions> Options() const override;
    ftxui::Element getPlayerTile() override;
    virtual ~PlayerDecorator() = 0;
};

#endif
