#ifndef SPELL_CARD_H
#define SPELL_CARD_H
#include "cards/Card.h"

// 25% Chance to give the player 30 grades. Else, lose 10 grades. 
class JuiceCard : public SpellCard {
    public:
    JuiceCard();
    void apply(Player*, std::shared_ptr<Player>, Board*) override;
    bool requiresTarget() override;
    std::string getName() override;
    std::string getDescription() override;
};

class PortalCard : public SpellCard {
    public:
        PortalCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;

};

// Deal 8 Damage to a player of your choice. 
class LazeezCard: public SpellCard {
    public:
        LazeezCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;

};

// grants a 25% chance to move the target forward 10 spaces. Else, caller take 10 damage.
class CS247Card: public SpellCard {
    public:
        CS247Card();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;

};

// Steal 15 grades from a player of your choice. 
class PredatorCard: public SpellCard {
    public: 
        PredatorCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;
};

// Heal for 10 HP. 
class HealthCard : public SpellCard {
    public:
        HealthCard();
        void apply(Player*, std::shared_ptr<Player>, Board*) override;
        bool requiresTarget() override;
        std::string getName() override;
        std::string getDescription() override;
};


// Other spell cards defined here


#endif
