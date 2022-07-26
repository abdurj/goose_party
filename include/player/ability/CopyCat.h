#ifndef COPYCAT_H
#define COPYCAT_H

#include "player/PlayerDecorator.h"

class CopyCat : public PlayerDecorator {
    void doEndCycle(std::vector<std::shared_ptr<Player>>&) override;
    void abilityDesc() const override;
    public:
    CopyCat(std::shared_ptr<Player>);
};


#endif