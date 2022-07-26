#ifndef OVERLOADING_H
#define OVERLOADING_H

#include "player/PlayerDecorator.h"

class Overloading : public PlayerDecorator {
    void abilityDesc() const override;
    int getRolls() const override;
    public:
    Overloading(std::shared_ptr<Player>);
};


#endif