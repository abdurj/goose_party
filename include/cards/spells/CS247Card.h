#ifndef CS247_CARD_H
#define CS247_CARD_H
#include "cards/SpellCard.h"
// grants a 25% chance to move the target forward 10 spaces. Else, caller take 10 damage.
class CS247Card: public SpellCard {
    public:
        CS247Card();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;

};
#endif
