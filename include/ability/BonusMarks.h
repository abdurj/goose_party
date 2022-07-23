#ifndef BONUSMARKS_H
#define BONUSMARKS_H

#include "player/PlayerDecorator.h"

class BonusMarks : public PlayerDecorator {
    void doEndTurn() override;
    void listAbilities() const override;
    public:
    BonusMarks(std::shared_ptr<Player>);
};


#endif