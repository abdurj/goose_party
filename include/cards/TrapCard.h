#ifndef TRAP_CARD_H
#define TRAP_CARD_H
#include "cards/Card.h"
// Trap Card definitions begin here
class TrapCard : public Card {
    protected:
    TrapCard();
    public:
        virtual void activate(std::shared_ptr<Player>) = 0;
        //virtual void apply(std::shared_ptr<Player>, Board*) = 0;
        //virtual bool requiresTarget() = 0;
};

// Other TRAP cards defined here




#endif
