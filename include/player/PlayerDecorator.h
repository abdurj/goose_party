#ifndef PLAYERDECO_H
#define PLAYERDECO_H

#include "player/Player.h"

class PlayerDecorator : public Player {
    void doEndTurn(std::vector<std::shared_ptr<Player>>&) override; //Better name suggestions?
    void doEndCycle(std::vector<std::shared_ptr<Player>>&) override;
    void abilityDesc() const override;
    
    protected:
    std::shared_ptr<Player> playerComponent;
    public:
    PlayerDecorator(std::shared_ptr<Player>);
    void addAbility(std::string) override;
    const std::unordered_set<std::string>& Abilities() const override;
    void info() const override;
    int Grades() const override;
    int Degrees() const override;
    int modifyGrades(int) override;
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
    ftxui::Element getPlayerTile() override;
    virtual ~PlayerDecorator() = 0;
};

#endif
