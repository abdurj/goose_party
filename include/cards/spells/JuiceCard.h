#ifndef JUICE_CARD_H
#define JUICE_CARD_H

#include "cards/SpellCard.h"
// 25% Chance to give the player 30 grades. Else, lose 10 grades. 
class JuiceCard : public SpellCard {
    public:
    JuiceCard();
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
    std::string getDescription() override;
};

#endif
