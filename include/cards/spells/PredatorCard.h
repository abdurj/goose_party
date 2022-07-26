#ifndef PREDATOR_CARD_H
#define PREDATOR_CARD_H
#include "cards/SpellCard.h"
// Steal 15 grades from a player of your choice. 
class PredatorCard: public SpellCard {
    public: 
        PredatorCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;
};
#endif
