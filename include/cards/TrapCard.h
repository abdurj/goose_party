#ifndef TRAP_CARD_H
#define TRAP_CARD_H
#include "cards/Card.h"
// Trap Card definitions begin here
class TrapCard : public Card {
    protected:
    TrapCard();
    public:
        virtual void activate(std::shared_ptr<Player>) = 0;
};




#endif
