#ifndef HEALTH_CARD_H
#define HEALTH_CARD_H
#include "cards/SpellCard.h"
// Heal for 10 HP. 
class HealthCard : public SpellCard {
    public:
        HealthCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;
};
#endif
