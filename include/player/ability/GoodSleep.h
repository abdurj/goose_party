#ifndef GOODSLEEP_H
#define GOODSLEEP_H

#include "player/PlayerDecorator.h"

class GoodSleep : public PlayerDecorator {
    void listAbilities(std::unordered_set<std::string>&) const override;
    public:
    GoodSleep(std::shared_ptr<Player>);
};


#endif