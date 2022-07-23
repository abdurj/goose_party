#ifndef TRAP_CARD_H
#define TRAP_CARD_H
#include "cards/Card.h"

// TODO: delete this pfile probably

class BossCard : public TrapCard {
    void activate() override;
    void apply(std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
};

// Other TRAP cards defined here


#endif
