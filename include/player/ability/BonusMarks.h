#ifndef BONUSMARKS_H
#define BONUSMARKS_H

#include "player/PlayerDecorator.h"

class BonusMarks : public PlayerDecorator {
    void doEndTurn() override;
    void listAbilities(std::unordered_set<std::string>&) const override;
    public:
    BonusMarks(std::shared_ptr<Player>);
};


#endif