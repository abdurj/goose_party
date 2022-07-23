#ifndef SPELL_CARD_H
#define SPELL_CARD_H
#include "cards/Card.h"

class JuiceCard : public SpellCard {
    public:
    JuiceCard();
    void apply(std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
};

// Other spell cards defined here


#endif
