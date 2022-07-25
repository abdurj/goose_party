#ifndef SPELL_CARD_H
#define SPELL_CARD_H
#include "cards/Card.h"

class JuiceCard : public SpellCard {
    public:
    JuiceCard();
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
};

class PortalCard : public SpellCard {
    public:
        PortalCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
};

// Deal 8 Damage to a player of your choice. 
class LazeezCard: public SpellCard {
    public:
        LazeezCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
};

// grants a 25% chance to move the target forward 10 spaces. Else, caller take 10 damage.
class CS247Card: public SpellCard {
    public:
        CS247Card();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
};

// Steal 15 grades from a player of your choice. 
class PredatorCard: public SpellCard {
    public: 
        PredatorCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
};


// Other spell cards defined here


#endif
