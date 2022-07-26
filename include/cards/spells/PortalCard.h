#ifndef PORTAL_CARD_H
#define PORTAL_CARD_H
#include "cards/SpellCard.h"
class PortalCard : public SpellCard {
    public:
        PortalCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;

};
#endif
