#ifndef TRAP_CARD_H
#define TRAP_CARD_H
#include "cards/Card.h"

class BossCard : public TrapCard {
    void activate(std::shared_ptr<Player>) override;
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
    std::string getDescription() override;
};

// Other TRAP cards defined here

class ExplosiveMine : public TrapCard {
    void activate(std::shared_ptr<Player>) override;
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
    std::string getDescription() override;
};

class Policy71 : public TrapCard {
    void activate(std::shared_ptr<Player>) override;
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
    std::string getDescription() override;
};


#endif
