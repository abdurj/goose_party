#ifndef EXPLOSIVE_CARD_H
#define EXPLOSIVE_CARD_H
#include "cards/TrapCard.h"

class ExplosiveMine : public TrapCard {
    void activate(std::shared_ptr<Player>) override;
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
    std::string getDescription() override;
};

#endif
