#ifndef TRAP_CARD_H
#define TRAP_CARD_H
#include "cards/Card.h"

class BossCard : public TrapCard {
    void activate() override;
    void apply(std::shared_ptr<Player>, Board&) override;
    bool requiresTarget() override;
    std::string getName() override;
};

// Other TRAP cards defined here


#endif
