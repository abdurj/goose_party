#ifndef TIMEMANAGE_H
#define TIMEMANAGE_H

#include "player/PlayerDecorator.h"

class TimeManagement : public PlayerDecorator {
    void listAbilities() const override;
    public:
    TimeManagement(std::shared_ptr<Player>);
};


#endif