#ifndef LAZEEZ_CARD_H
#define LAZEEZ_CARD_H
#include "cards/SpellCard.h"
// Deal 8 Damage to a player of your choice. 
class LazeezCard: public SpellCard {
    public:
        LazeezCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;

};
#endif
