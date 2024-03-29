#ifndef BONUSMARKS_H
#define BONUSMARKS_H

#include "player/PlayerDecorator.h"

class BonusMarks : public PlayerDecorator {
    void doEndTurn(std::vector<std::shared_ptr<Player>>&) override;
    void abilityDesc() const override;
    public:
    BonusMarks(std::shared_ptr<Player>);
};


#endif