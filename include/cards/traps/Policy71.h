#ifndef POLICY_CARD_H
#define POLICY_CARD_H
#include "cards/TrapCard.h"

class Policy71 : public TrapCard {
    void activate(std::shared_ptr<Player>) override;
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
    std::string getDescription() override;
};
#endif
