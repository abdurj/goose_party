#ifndef ALLNIGHTER_H
#define ALLNIGHTER_H

#include "player/PlayerDecorator.h"

class AllNighter : public PlayerDecorator {
    void abilityDesc() const override;
    public:
    AllNighter(std::shared_ptr<Player>);
};


#endif