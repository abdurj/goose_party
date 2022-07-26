#ifndef SPELL_CARD_H
#define SPELL_CARD_H
#include "cards/Card.h"
// Player will have a use() method which will call card->apply(Player), but how do we handle cases when a card effect does not need a player?
// Option 1 - Must always pass in a player. Spell cards that don't need a player will pass in the player calling it. But this would require that we know the type of the card, breaking polymorphism
// Option 2 - We can distinguish between cards using a function that tells the caller whether it requires a target, and work polymorphically with the spell and trap cards. 

class SpellCard : public Card {
    protected:
    SpellCard();
    public:
    //virtual void apply(std::shared_ptr<Player>, Board*) = 0;
    //virtual bool requiresTarget() = 0;

};









// Other spell cards defined here


#endif
