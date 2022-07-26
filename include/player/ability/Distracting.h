#ifndef DISTRACTING_H
#define DISTRACTING_H

#include "player/PlayerDecorator.h"

class Distracting : public PlayerDecorator {
    void doEndCycle(std::vector<std::shared_ptr<Player>>&) override;
    void abilityDesc() const override;
    public:
    Distracting(std::shared_ptr<Player>);
};


#endif