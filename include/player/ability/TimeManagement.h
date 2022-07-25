#ifndef TIMEMANAGE_H
#define TIMEMANAGE_H

#include "player/PlayerDecorator.h"

class TimeManagement : public PlayerDecorator {
    void abilityDesc() const override;
    public:
    TimeManagement(std::shared_ptr<Player>);
};


#endif