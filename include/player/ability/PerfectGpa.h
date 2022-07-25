#ifndef PERFECTGPA_H
#define PERFECTGPA_H

#include "player/PlayerDecorator.h"

class PerfectGpa : public PlayerDecorator {
    int count;
    void doEndCycle() override;
    void abilityDesc() const override;
    public:
    PerfectGpa(std::shared_ptr<Player>);
};


#endif